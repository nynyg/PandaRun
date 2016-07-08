//
//  Firecracker.cpp
//  OpenGLTest
//
//  Created by 周群洁 on 08/07/16.
//  Copyright © 2016 MissGrumpy. All rights reserved.
//

#include "Firecracker.h"
#include "DrawPrimitives.h"
void Firecracker::drawFirecracker(float resultMatrix[16]){
    
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
    
    //translate to left of the panda
    glTranslatef(-2,0,0);//(x,y,z)
    
    //body rgb(204, 41, 0)
    glPushMatrix();
    glColor4f( 255.0f/255,  51.0f/255, 0.0f ,1.0);
    glRotatef( -90, 1, 0.35, 0 );//(x,z,-y) angle to left
    drawCylinder(FIRECRACKER_WIDTH, FIRECRACKER_WIDTH, FIRECRACKER_HEIGHT, SLICES, STACKS);//draw from bottom to up
    glPopMatrix();
    
    //thread rgb(41, 41, 61)
    glPushMatrix();
    glColor4f( 41.0f/255,  41.0f/255, 61.0f/255 ,1.0);
    glRotatef( -90, 1, 0.35, 0 );//(x,z,-y) angle to left
    glTranslatef(0,0,0.9*FIRECRACKER_HEIGHT);
    glRotatef( -10, 1, 1, 0 );//(x,z,-y) angle to left
    drawCylinder(THREAD_WIDTH, THREAD_WIDTH, THREAD_LENGHT, SLICES, STACKS);//draw from bottom to up
    glRotatef( 40, 0 , 1, 0 );//(x,z,-y) angle to left
    drawCylinder(THREAD_WIDTH, THREAD_WIDTH, THREAD_LENGHT, SLICES, STACKS);//draw from bottom to up
    glPopMatrix();
    
}
