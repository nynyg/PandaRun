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
public:
    void drawPanda(float resultTransposedMatrix[16]);
    void drawArrow(float resultTransposedMatrix[4][16]);
    void drawStone(float resultTransposedMatrix[16]);
    void drawBamboo(float resultTransposedMatrix[16]);
};
#endif /* Panda_h */
