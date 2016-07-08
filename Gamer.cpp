//
//  Gamer.cpp
//  Panda
//
//  Created by Saga on /6/716.
//  Copyright © 2016 Zhenzhang. All rights reserved.
//

#include "Gamer.hpp"
#include <iostream>
#include <ctime>

void Gamer::setMatrix(float (*resultMatrix)[16]){
    std::memcpy(leftPanda, resultMatrix[0], sizeof(float)*16);
    std::memcpy(rightPanda, resultMatrix[1], sizeof(float)*16);
}

void Gamer::playGame(std::vector<bool> &markers){
    if(current_pos == 1){
        markers[0] = true;
        markers[1] = false;
    }
    
    if(current_pos == 2){
        markers[0] = false;
        markers[1] = true;
    }
    
    if(markers[2] == false){
        markers[0] = true;
        markers[1] = false;
        current_pos = 1;
    }

    if(markers[3] == false){
        markers[0] = false;
        markers[1] = true;
        current_pos = 2;
    }
    count++;
    if(count%20 == 0){
        srand(rand());
        int left_num = rand()%3-1;
        int right_num = rand()%3-1;
        if(left_num + right_num ==-2){
            if(rand()%2 == 0){
                left_num = 0;
            }else{
                right_num = 0;
            }
        }
        leftList.push_back(Stuff(left_num));
        rightList.push_back(Stuff(right_num));
        count = 1;
    }
    
}

void Gamer::drawStuff(){
    float tempLPanda[16],tempRPanda[16];
    std::memcpy(tempLPanda, leftPanda, sizeof(float)*16);
    std::memcpy(tempRPanda, rightPanda, sizeof(float)*16);
    std::list<Stuff>::iterator it;
    for(it = leftList.begin();it!=leftList.end();it++){
        tempLPanda[7] = leftPanda[7];
        getTrans(tempLPanda, it->step++);
        if(it->getType() == 1){
            it->drawBamboo(tempLPanda);
        }else if (it->getType()==-1){
            it->drawStone(tempLPanda);
        }
        if(it->step == 50){
            if(current_pos == 1){
                if(it->getType() == 1){
                    current_grade++;
                }
                if(it->getType() == -1){
                    current_life--;
                }
            }
            leftList.pop_front();
        }
    }
    for(it = rightList.begin();it!=rightList.end();it++){
        tempRPanda[7] = rightPanda[7];
        getTrans(tempRPanda,it->step++);
        if(it->getType() == 1){
            it->drawBamboo(tempRPanda);
        }else if (it->getType()==-1){
            it->drawStone(tempRPanda);
        }
        if(it->step == 50){
            if(current_pos == 2){
                if(it->getType() == 1){
                    current_grade++;
                }
                if(it->getType() == -1){
                    current_life--;
                }
            }
            rightList.pop_front();
        }
    }
}

void Gamer::showGold(cv::Mat &img){
    CvFont font;
    double hScale=2;
    double vScale=2;
    int lineWidth=3;
    cvInitFont(&font,CV_FONT_HERSHEY_SIMPLEX|CV_FONT_ITALIC, hScale,vScale,0,lineWidth);
    IplImage arr = img;
    char show_msg[20] = "Grade: ";
    std::string s = std::to_string(current_life);
    std::strcpy((show_msg+7), s.c_str());
    cvPutText(&arr, show_msg, cv::Point(800,100),&font, cv::Scalar(0,0,0));
    img = cv::cvarrToMat(&arr);
}

void Gamer::getTrans(float *matrix, double step){
    matrix[7] += step/1000;
}

void Gamer::showLife(cv::Mat &img){
    CvFont font;
    double hScale=2;
    double vScale=2;
    int lineWidth=3;
    cvInitFont(&font,CV_FONT_HERSHEY_SIMPLEX|CV_FONT_ITALIC, hScale,vScale,0,lineWidth);
    IplImage arr = img;
    char show_msg[20] = "life: ";
    std::string s = std::to_string(current_life);
    std::strcpy((show_msg+6), s.c_str());
    cvPutText(&arr, show_msg, cv::Point(20,100),&font, cv::Scalar(0,0,0));
    img = cv::cvarrToMat(&arr);
}

void Gamer::playBGM(){
}