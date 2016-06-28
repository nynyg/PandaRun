//
//  Camera.hpp
//
//  Created by Nan on 16/6/26.
//  Copyright © 2016 Nan. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp

#include "include/opencv/cv.h"
#include "include/opencv/highgui.h"

using namespace std;

class Camera{
public:
    Camera() :
    cameraNum(0),
    cameraWidth(1280),
    cameraHeight(720),
    virtualCameraAngel(30)
    {
        init();
    }
    Camera(int _cameraNum, int _cameraWidth, int _cameraHeight, int _virtualCameraAngel) :
    cameraNum(_cameraNum),
    cameraWidth(_cameraWidth),
    cameraHeight(_cameraHeight),
    virtualCameraAngel(_virtualCameraAngel)
    {
        init();
    }
    int getNum() const;
    int getWidth() const;
    int getHeight() const;
    int getAngel() const;
    cv::VideoCapture getCap() const;
    
private:
    const int cameraNum;
    const int cameraWidth;
    const int cameraHeight;
    const int virtualCameraAngel;
    cv::VideoCapture cap;
    
    void init();
    
};

#endif /* Camera_hpp */
