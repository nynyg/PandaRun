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
    const float WIDTH_EYES=0.2f;
    const float HEIGHT_BODY=0.75f;
    const float TOP_BODY=0.35f;
    const float BOTTOM_BODY=0.45f;
    const float HEIGHT_LEGS=0.2f;
    const float WIDTH_LEGS=0.185f;
    
public:
    void drawPanda(float resultTransposedMatrix[16]);
};
#endif /* Panda_h */
