//
//  Camera.cpp
//
//  Created by Nan on 16/6/26.
//  Copyright © 2016 Nan. All rights reserved.
//

#include "Camera.hpp"

void Camera::init(){
    if( cap.isOpened() )
        cap.release();    
    cap.open(1); // open the default camera
    if ( cap.isOpened()==false ) {
        std::cout << "No webcam found, using a video file" << std::endl;
        cap.open("MarkerMovie.mpg");
        if ( cap.isOpened()==false ) {
            std::cout << "No video file found. Exiting."      << std::endl;
            exit(0);
        }
    }
}

int Camera::getNum() const{
    return cameraNum;
}

int Camera::getWidth() const{
    return cameraWidth;
}

int Camera::getHeight() const{
    return cameraHeight;
}
int Camera::getAngel() const{
    return virtualCameraAngel;
}

cv::VideoCapture Camera::getCap() const{
    return cap;
}
