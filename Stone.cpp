//
//  Stone.cpp
//  OpenGLTest
//
//  Created by 周群洁 on 05/07/16.
//  Copyright © 2016 MissGrumpy. All rights reserved.
//

#include "Stone.h"
#include "DrawPrimitives.h"


void Stone::drawStones(float resultMatrix[16]){
    
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
    glRotatef( -90, 1, 0, 0 ); //(x,z,-y) =>(x,y,z)
    glScalef(0.05, 0.05, 0.05);
  
    
    
    //translate to the ground right to the feet of panda
    glTranslatef(0.6,-0.4,0);//(x,z,-y)

    //draw bottom base
    glPushMatrix();
    glRotatef( -90, 1, 0, 0 );

    glColor4f( 102.0f/255,  57.0f/255, 0.0f ,1.0);//dark brown
    drawCylinder(STONE_BOTTOM, STONE_MIDDLE, STONE_BASE_HEIGHT, SLICES, STACKS);
    glPopMatrix();
    
    //draw the  left half
    glPushMatrix();
    glTranslatef(-0.2*STONE_LEFT_RADIUS,0.4*STONE_LEFT_RADIUS+STONE_BASE_HEIGHT,0);//(x,y,z)
    glColor4f( 153.0f/255,  79.0f/255, 0.0f ,1.0);//dark brown
    drawSphere( STONE_LEFT_RADIUS, SLICES, STACKS );
    glPopMatrix();
    
    //draw the right half
    glPushMatrix();
    glTranslatef(STONE_RIGHT_RADIUS,0.5*STONE_RIGHT_RADIUS+STONE_BASE_HEIGHT,0.08);//(x,y,z)
    glColor4f( 77.0f/255,  38.0f/255, 0.0f ,1.0);//dark brown
    drawSphere( STONE_RIGHT_RADIUS, SLICES, STACKS );


    glPopMatrix();
    //
    
    
    
    
    
    
    
    
    
}
