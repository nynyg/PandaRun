//
//  Panda.h
//
//  Created by Nan on 16/6/26.
//  Copyright © 2016 Nan. All rights reserved.
//

#ifndef Panda_h
#define Panda_h

#include "OSDetect.h"

class Panda{
    
    const int SLICES=40;
    const int STACKS=40;
    const float WIDTH_HEAD=0.52f;
    const float HEIGHT_EAR =0.13f;
    const float THICKNESS_EAR = 0.08f;
    const float WIDTH_EYES=0.2f;
    const float HEIGHT_BODY=0.75f;
    const float TOP_BODY=0.35f;
    const float BOTTOM_BODY=0.45f;
    const float WIDTH_ARMS=0.12f;
    const float LENGTH_ARMS=0.5f;
    const float WIDTH_HAND=0.13f;
    const float HEIGHT_LEGS=0.4f;
    const float WIDTH_LEGS=0.155f;
    const float WIDTH_FEET=0.165f;
    const float HEIGHT_FEET=0.13f;
    const float WIDTH_TAIL=0.12f;
public:
    void drawPanda(float resultTransposedMatrix[16]);
};
#endif /* Panda_h */
