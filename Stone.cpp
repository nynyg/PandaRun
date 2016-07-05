//
//  Stone.cpp
//  OpenGLTest
//
//  Created by 周群洁 on 05/07/16.
//  Copyright © 2016 MissGrumpy. All rights reserved.
//

#include "Stone.h"
#include "DrawPrimitives.h"


void Stone::drawStone(float resultMatrix[16]){
    
    // move to marker-position
    
    float resultTransposedMatrix[16];
    for (int x=0; x<4; ++x)
    {
        for (int y=0; y<4; ++y)
        {
            resultTransposedMatrix[x*4+y] = resultMatrix[y*4+x];
        }
    }
    glLoadMatrixf( resultTransposedMatrix );
    
    
    
  // light brown  153, 102, 51 dark brown 38, 26, 13
    //draw bottom half
    
    glPushMatrix();
//  glRotatef(90, 0, 0, 0);
    glTranslatef(-10,0,0);//left
    glColor4f( 38, 26, 13, 1.0 );
    drawCylinder(STONE_BOTTOM, STONE_MIDDLE, STONE_BASE_HEIGHT, SLICES, STACKS);
    
    
    
    
    
    
    
    
    
    
}
