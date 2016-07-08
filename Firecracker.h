//
//  Firecracker.h
//  OpenGLTest
//
//  Created by 周群洁 on 08/07/16.
//  Copyright © 2016 MissGrumpy. All rights reserved.
//

#ifndef Firecracker_h
#define Firecracker_h
#include "OSDetect.h"

class Firecracker{
    const int SLICES=40;
    const int STACKS=40;
    const double FIRECRACKER_HEIGHT=0.5f;
    const double FIRECRACKER_WIDTH=0.1f;
    const double THREAD_WIDTH=0.013f;
    const double THREAD_LENGHT=0.2f;
   public:
    void drawFirecracker(float resultTransposedMatrix[16]);
};

#endif /* Firecracker_h */
