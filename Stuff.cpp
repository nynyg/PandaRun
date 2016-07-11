//
//  Stuff.cpp
//  Panda
//
//  Created by Saga on /6/716.
//  Copyright © 2016 Zhenzhang. All rights reserved.
//

#include "Stuff.hpp"
#include "DrawPrimitives.h"

void Stuff::drawBamboo(float resultMatrix[16]){
    // move to marker-position
    const int SLICES=40;
    const int STACKS=40;
    const double BAMBOO_HEIGHT_UP=0.3f;
    const double BAMBOO_HEIGHT_MIDDLE=0.02f;
    const double BAMBOO_HEIGHT_BOTTOM=0.37f;
    const double BAMBOO_WIDTH=0.04f;
    const double BAMBOO_WIDTH_MIDDLE=0.045f;
    const double BAMBOO_BRANCH_WIDTH=0.02f;
    const double BAMBOO_BRANCH_HEIGHT=0.25f;
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
    //glTranslatef(-0.8,0,0);//(x,y,z)
           glRotatef( -90, 1, 0.35, 0 );//(x,z,-y) angle to left
    //upper
    glPushMatrix();
    glColor4f( 0.0f,  120.0f/255, 0.0f ,1.0);

//    glRotatef( -90, 1, 0, 0 );//(x,z,-y)
    drawCylinder(BAMBOO_WIDTH_MIDDLE, BAMBOO_WIDTH, BAMBOO_HEIGHT_UP, SLICES, STACKS);//draw from bottom to up
    glPopMatrix();
    
    //middle
    glPushMatrix();
    glColor4f( 0.0f,  77.0f/255, 0.0f ,1.0);
//    glRotatef( -90, 1, 0, 0 );//(x,z,y)
    glTranslatef(0,0,-BAMBOO_HEIGHT_MIDDLE);
    drawCylinder(BAMBOO_WIDTH_MIDDLE, BAMBOO_WIDTH_MIDDLE, BAMBOO_HEIGHT_MIDDLE, SLICES, STACKS);
    glPopMatrix();
    
    //bottom
    glPushMatrix();
    glColor4f( 0.0f,  120.0f/255, 0.0f ,1.0);
//    glRotatef( -90, 1, 0, 0 );
    glTranslatef(0,0, -1*(BAMBOO_HEIGHT_MIDDLE+BAMBOO_HEIGHT_BOTTOM));
    drawCylinder(BAMBOO_WIDTH, BAMBOO_WIDTH_MIDDLE, BAMBOO_HEIGHT_BOTTOM, SLICES, STACKS);
    glPopMatrix();
    
    //left branch
    glPushMatrix();
    glColor4f( 0.0f,  120.0f/255, 0.0f ,1.0);
    glRotatef( 60,0, 1, 0 );//-0.5 angle to left
    glTranslatef(-0.3*BAMBOO_WIDTH,0, 0.15*BAMBOO_HEIGHT_UP);
    drawCylinder(BAMBOO_BRANCH_WIDTH, BAMBOO_BRANCH_WIDTH*0.85, BAMBOO_BRANCH_HEIGHT, SLICES, STACKS);
    glPopMatrix();
    
    //right branch
    glPushMatrix();
    glColor4f( 0.0f,  120.0f/255, 0.0f ,1.0);
    glRotatef( 120, 0,1, 0 );//-0.4 angle to right
    glTranslatef(0.5*BAMBOO_WIDTH,0, -1.1*BAMBOO_HEIGHT_UP);
    drawCylinder(BAMBOO_BRANCH_WIDTH, BAMBOO_BRANCH_WIDTH*0.8, BAMBOO_BRANCH_HEIGHT*1.25, SLICES, STACKS);
    glPopMatrix();
}

void Stuff::drawStone(float resultMatrix[16]){
    const int SLICES=40;
    const int STACKS=40;
    const double FIRECRACKER_HEIGHT=0.5f;
    const double FIRECRACKER_WIDTH=0.1f;
    const double THREAD_WIDTH=0.013f;
    const double THREAD_LENGHT=0.2f;
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
    //glTranslatef(-2,0,0);//(x,y,z)
    
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
    glPopMatrix();}
short Stuff::getType(){
    return type;
}