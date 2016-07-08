//
//  Stuff.hpp
//  Panda
//
//  Created by Saga on /6/716.
//  Copyright © 2016 Zhenzhang. All rights reserved.
//

#ifndef Stuff_hpp
#define Stuff_hpp

#include <stdio.h>
#include "OSDetect.h"

class Stuff{
public:
    Stuff(int itype):type(itype){
    }
    void drawBamboo(float matrix[16]);
    void drawStone(float matrix[16]);
    short getType();
    short step=0;
protected:
    short type;
};

#endif /* Stuff_hpp */
