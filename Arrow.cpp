//
//  Arrow.cpp
//  OpenCVTest
//
//  Copyright © 2016 Nan. All rights reserved.
//

#include "Arrow.h"
#include "DrawPrimitives.h"

void Arrow::drawArrow(float resultMatrix[16]){
    float resultTransposedMatrix[16];
    for (int x=0; x<4; ++x)
    {
        for (int y=0; y<4; ++y)
        {
            resultTransposedMatrix[x*4+y] = resultMatrix[y*4+x];
        }
    }
    glLoadMatrixf(resultTransposedMatrix);
    glScalef(0.03, 0.03, 0.03);
    glColor4f( 1, 1, 0, 1.0 );
    glRotatef( -90, 0, 0, 0 );
    drawCylinder(0.25,0.25,0.75,40,40);
    glTranslatef(2*0.21,0,0);
    
}