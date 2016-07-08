//
//  Stuff.cpp
//  Panda
//
//  Created by Saga on /6/716.
//  Copyright © 2016 Zhenzhang. All rights reserved.
//

#include "Stuff.hpp"
#include "DrawPrimitives.h"

void Stuff::drawBamboo(float matrix[16]){
    float resultTransposedMatrix[16];
    for (int x=0; x<4; ++x)
    {
        for (int y=0; y<4; ++y)
        {
            resultTransposedMatrix[x*4+y] = matrix[y*4+x];
        }
    }
    glLoadMatrixf(resultTransposedMatrix);
    glScalef(0.015, 0.015, 0.015);
    glColor4f( 1, 1, 0, 1.0 );
    drawCylinder(0.05,0.05,0.75,20,20);
}

void Stuff::drawStone(float matrix[16]){
    float resultTransposedMatrix[16];
    for (int x=0; x<4; ++x)
    {
        for (int y=0; y<4; ++y)
        {
            resultTransposedMatrix[x*4+y] = matrix[y*4+x];
        }
    }
    glLoadMatrixf(resultTransposedMatrix);
    glScalef(0.015, 0.015, 0.015);
    glColor4f( 1, 0, 0, 1.0 );
    drawCylinder(0.05,0.05,0.75,20,20);
}
short Stuff::getType(){
    return type;
}