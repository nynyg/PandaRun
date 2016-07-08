//
//  Bamboo.cpp
//  OpenGLTest
//
//  Created by 周群洁 on 08/07/16.
//  Copyright © 2016 MissGrumpy. All rights reserved.
//

#include "Bamboo.h"

#include "DrawPrimitives.h"


void Bamboo::drawBamboo(float resultMatrix[16]){
    
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
    glScalef(0.07, 0.07, 0.07);

    //translate to left of the panda
    glTranslatef(-0.8,0,0);//(x,y,z)
    
    //upper
    glPushMatrix();
    glColor4f( 0.0f,  77.0f/255, 0.0f ,1.0);
    glRotatef( -90, 1, 0, 0 );//(x,z,-y)
    drawCylinder(BAMBOO_WIDTH_MIDDLE, BAMBOO_WIDTH, BAMBOO_HEIGHT_UP, SLICES, STACKS);//draw from bottom to up
    glPopMatrix();

    //middle
    glPushMatrix();
    glColor4f( 0.0f,  51.0f/255, 0.0f ,1.0);
    glRotatef( -90, 1, 0, 0 );//(x,z,y)
    glTranslatef(0,0,-BAMBOO_HEIGHT_MIDDLE);
    drawCylinder(BAMBOO_WIDTH_MIDDLE, BAMBOO_WIDTH_MIDDLE, BAMBOO_HEIGHT_MIDDLE, SLICES, STACKS);
    glPopMatrix();
    
    //bottom
    glPushMatrix();
    glColor4f( 0.0f,  77.0f/255, 0.0f ,1.0);
    glRotatef( -90, 1, 0, 0 );
    glTranslatef(0,0, -1*(BAMBOO_HEIGHT_MIDDLE+BAMBOO_HEIGHT_BOTTOM));
    drawCylinder(BAMBOO_WIDTH, BAMBOO_WIDTH_MIDDLE, BAMBOO_HEIGHT_BOTTOM, SLICES, STACKS);
    glPopMatrix();

    //left branch
    glPushMatrix();
    glColor4f( 0.0f,  77.0f/255, 0.0f ,1.0);
    glRotatef( -90, 1, 0.5, 0 );//-0.5 angle to left
    glTranslatef(-0.3*BAMBOO_WIDTH,0, 0.15*BAMBOO_HEIGHT_UP);
    drawCylinder(BAMBOO_BRANCH_WIDTH, BAMBOO_BRANCH_WIDTH*0.85, BAMBOO_BRANCH_HEIGHT, SLICES, STACKS);
    glPopMatrix();
    
    //right branch
    glPushMatrix();
    glColor4f( 0.0f,  77.0f/255, 0.0f ,1.0);
    glRotatef( -90, 1, -0.5, 0 );//-0.4 angle to right
    glTranslatef(3.5*BAMBOO_WIDTH,0, -BAMBOO_HEIGHT_UP);
    drawCylinder(BAMBOO_BRANCH_WIDTH, BAMBOO_BRANCH_WIDTH*0.8, BAMBOO_BRANCH_HEIGHT*1.25, SLICES, STACKS);
    glPopMatrix();
    
}