#define GLFW_INCLUDE_GLU
//#include <GL/glew.h>
#include "OSDetect.h"

#include "GLUtility.hpp"
#include <iostream>
#include <iomanip>

#define _USE_MATH_DEFINES
#include <math.h>

#include "MarkerTracker.h"
#include "Camera.hpp"
#include "Panda.h"
#include "Arrow.h"

using namespace std;

bool isStart = false;

int main(int argc, char* argv[])
{
    Camera camera;
    GLFWwindow* window;
    if (!glfwInit())
        return -1;
    window = glfwCreateWindow(camera.getWidth(), camera.getWidth(), "PandaRun", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    
    // Set callback functions for GLFW
    glfwSetFramebufferSizeCallback(window, reshape);
    glfwMakeContextCurrent(window);
    glfwSwapInterval( 1 );
    
    int window_width, window_height;
    glfwGetFramebufferSize(window, &window_width, &window_height);
    reshape(window, window_width, window_height);
    
    glViewport(0, 0, window_width, window_height);
    
    // initialize the GL library
    initGL(argc, argv);
    
    // setup OpenCV
    cv::Mat img_bgr;
    const double kMarkerSize = 0.044; // [m]
    MarkerTracker markerTracker(kMarkerSize);
    
    float resultMatrix[4][16] = {-1};
    /* Loop until the user closes the window */
    unsigned char bkgnd[camera.getWidth()*camera.getHeight()*3];
    while (!glfwWindowShouldClose(window))
    {
        /* Capture here */
        camera.getCap() >> img_bgr;
        
        if(img_bgr.empty()){
            std::cout << "Could not query frame. Trying to reinitialize." << std::endl;
            Camera camera;
            cv::waitKey(1000); /// Wait for one sec.
            continue;
        }
        
        /* Track a marker */
        vector<bool> foundPanda(4, false);
        vector<int> pandaMarker(4, 0);
        pandaMarker[0] = 0x0690;//LPanda
        pandaMarker[1] = 0x1C44;//RPanda
        pandaMarker[2] = 0x1228;//Left
        pandaMarker[3] = 0x0B44;//Right
        markerTracker.findMarker( img_bgr, resultMatrix, pandaMarker, foundPanda);
        if(!isStart){
            int key = cvWaitKey(200);
            if(key == 32){
                
                isStart = true;
                cout<<"game start!";
            }
        }
        /* Render here */
        display(window, img_bgr, resultMatrix[0], bkgnd, camera.getWidth(), camera.getHeight(), isStart);
        if(isStart){
            glMatrixMode( GL_MODELVIEW );
            //Panda panda1;
            //panda1.drawPanda(resultMatrix);
            if(foundPanda[2]){
                Arrow arr1;
                arr1.drawArrow(resultMatrix[2]);
            }
            if(foundPanda[3]){
                Arrow arr2;
                arr2.drawArrow(resultMatrix[3]);
            }
            if(foundPanda[0]){
                Panda pandaL;
                pandaL.drawPanda(resultMatrix[0]);
            }
            if(foundPanda[1]){
                Panda pandaR;
                pandaR.drawPanda(resultMatrix[1]);
            }
        }
        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        
        /* Poll for and process events */
        glfwPollEvents();
    }
    
    glfwTerminate();
    
    
    return 0;
}