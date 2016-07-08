//
//  Bamboo.h
//  OpenGLTest
//
//  Created by 周群洁 on 08/07/16.
//  Copyright © 2016 MissGrumpy. All rights reserved.
//

#ifndef Bamboo_h
#define Bamboo_h
#include "OSDetect.h"

class Bamboo{
    const int SLICES=40;
    const int STACKS=40;
    const double BAMBOO_HEIGHT_UP=0.3f;
    const double BAMBOO_HEIGHT_MIDDLE=0.02f;
    const double BAMBOO_HEIGHT_BOTTOM=0.37f;
    const double BAMBOO_WIDTH=0.04f;
    const double BAMBOO_WIDTH_MIDDLE=0.045f;
    const double BAMBOO_BRANCH_WIDTH=0.02f;
    const double BAMBOO_BRANCH_HEIGHT=0.25f;
    
public:
    void drawBamboo(float resultTransposedMatrix[16]);
};


#endif /* Bamboo_h */
