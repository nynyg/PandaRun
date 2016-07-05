//
//  Stone.h
//  OpenGLTest
//
//  Created by 周群洁 on 05/07/16.
//  Copyright © 2016 MissGrumpy. All rights reserved.
//

#ifndef Stone_h
#define Stone_h
#include "OSDetect.h"

class Stone{
    const int SLICES=40;
    const int STACKS=40;
    const float STONE_BOTTOM=0.16f;
    const float STONE_MIDDLE =0.13f;
    const float STONE_BASE_HEIGHT = 0.11f;
    const float STONE_LEFT_RADIUS = 0.10f;
    const float STONE_RIGHT_RADIUS = 0.05f;
    
   public:
    void drawStones(float resultTransposedMatrix[16]);
};

#endif /* Stone_h */
