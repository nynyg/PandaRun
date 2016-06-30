//
//  Panda.cpp
//
//  Created by Nan on 16/6/30.
//  Copyright © 2016 Nan. All rights reserved.
//

#include "Panda.h"
#include "DrawPrimitives.h"

void Panda::drawPanda(float resultMatrix[16]){
    //glLoadTransposeMatrixf( resultMatrix );
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
    glRotatef( -90, 1, 0, 0 );
    glScalef(0.03, 0.03, 0.03);
    
    // draw 3 white spheres
    glColor4f( 1.0, 1.0, 1.0, 1.0 );
    drawSphere( 0.8, 10, 10 );
    glTranslatef( 0.0, 0.8, 0.0 );
    drawSphere( 0.6, 10, 10 );
    glTranslatef( 0.0, 0.6, 0.0 );
    drawSphere( 0.4, 10, 10 );
    
    // draw the eyes
    glPushMatrix();
    glColor4f( 0.0, 0.0, 0.0, 1.0 );
    glTranslatef( 0.2, 0.2, 0.2 );
    drawSphere( 0.066, 10, 10 );
    glTranslatef( 0, 0, -0.4 );
    drawSphere( 0.066, 10, 10 );
    glPopMatrix();
    
    // draw a nose
    glColor4f( 1.0, 0.5, 0.0, 1.0 );
    glTranslatef( 0.3, 0.0, 0.0 );
    glRotatef( 90, 0, 1, 0 );
    drawCone( 0.1, 0.3, 10, 10 );
}
