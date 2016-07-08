//
//  Gamer.hpp
//  Panda
//
//  Created by Saga on /6/716.
//  Copyright © 2016 Zhenzhang. All rights reserved.
//

#ifndef Gamer_hpp
#define Gamer_hpp

#if __AR_USER__ == 0
#include <opencv/cv.h>
#else
#include <opencv2/opencv.hpp>
#endif

#include <opencv/highgui.h>

#include <stdio.h>
#include <cstring>
#include <vector>
#include <list>
#include <glfw/glfw3.h>
#include "Stuff.hpp"

class Gamer{
public:
    void setMatrix(float resultMatrix[4][16]);
    void playGame(std::vector<bool> &markers);
    void getTrans(float matrix[16], double step);
    void drawStuff();
    void showLife(cv::Mat &img);
    void showGold(cv::Mat &img);
    void playBGM();
private:
    float leftPanda[16];
    float rightPanda[16];
    short current_pos = 1;
    short current_life = 3;
    int current_grade = 0;
    int count = 0;
    std::list<Stuff> leftList,rightList;
};
#endif /* Gamer_hpp */
