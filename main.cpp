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

using namespace std;

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
    const double kMarkerSize = 0.048; // [m]
    MarkerTracker markerTracker(kMarkerSize);
    
    float resultMatrix[16];
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
        markerTracker.findMarker( img_bgr, resultMatrix);
        
        /* Render here */
        display(window, img_bgr, resultMatrix, bkgnd, camera.getWidth(), camera.getHeight());
        
        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        
        /* Poll for and process events */
        glfwPollEvents();
    }
    
    glfwTerminate();
    
    
    return 0;
}