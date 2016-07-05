//
//  Panda.cpp
//
//  Created by Nan on 16/6/30.
//  Copyright © 2016 Nan. All rights reserved.
//

#include "Panda.h"
#include "DrawPrimitives.h"
#include "Stone.h"
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
    
    
    
    
    
    //draw foot
    glPushMatrix();
    glRotatef(90, 0, 0, 0);
    glTranslatef(-0.21,0,0);//left
    glColor4f( 1.0, 1.0, 1.0, 1.0 );
    drawCylinder(WIDTH_LEGS, WIDTH_LEGS, HEIGHT_LEGS, SLICES, STACKS);
    glTranslatef(2*0.21,0,0);//right
    drawCylinder(WIDTH_LEGS, WIDTH_LEGS, HEIGHT_LEGS, SLICES, STACKS);
    glPopMatrix();
   
    
    //draw tailor
    glPushMatrix();
    glRotatef(90, -1, 0, 0);
    glTranslatef(0, 0.6*HEIGHT_BODY, 0.1);
    glColor4f( 0.0, 0.0, 0.0, 1.0 );
    drawSphere( WIDTH_TAIL, SLICES, STACKS );
    glPopMatrix();
    glPushMatrix();
    
    

    
    /**
     calibrated by: 
     rotatef(90, -1, 0, 0)
     => glTranslatef(x,z,y)
     */
    //draw feet&shoes
    glPushMatrix();
    glRotatef(90, -1, 0, 0);
    glTranslatef(-0.21,-0.7*WIDTH_LEGS,-1*HEIGHT_LEGS);//left
    drawSphere( 0.8*WIDTH_FEET, SLICES, STACKS );
    glTranslatef(2*0.21,0,0);//right
    drawSphere( 0.8*WIDTH_FEET, SLICES, STACKS );
    
    glTranslatef(0,0.3*WIDTH_LEGS,-0.5*WIDTH_FEET);//right
    drawCylinder(1.2*WIDTH_FEET, WIDTH_LEGS, HEIGHT_FEET, SLICES, STACKS);
    glTranslatef(-2*0.21,0,0);//left
    drawCylinder(1.4*WIDTH_FEET, WIDTH_LEGS, HEIGHT_FEET, SLICES, STACKS);
    glPopMatrix();
    
    
    //draw body
    glPushMatrix();
    glRotatef( -90, 1, 0, 0 );
    glColor4f( 1.0, 1.0, 1.0, 1.0 );
    drawCylinder(BOTTOM_BODY, TOP_BODY, HEIGHT_BODY, SLICES, STACKS);
    glPopMatrix();
    
    //draw left hand
    glPushMatrix();
    glColor4f( 1.0, 1.0, 1.0, 1.0 );
    glRotatef( -90, 1, -0.4, 0 );//-0.4 angle to left
//    glRotatef(10, 1, 0, 0);
    glTranslatef(-1.5*TOP_BODY,0.18,-0.04);//left   (x,-z,y)
    //normal   if 'jump' glRotatef(150, 0, -100, 0)
    drawCylinder( WIDTH_ARMS, WIDTH_ARMS, LENGTH_ARMS, SLICES, STACKS);
    glColor4f( 0.0, 0.0, 0.0, 1.0 );
    glTranslatef( -0.03, 0, 0);
    drawSphere(WIDTH_ARMS, SLICES, STACKS);
    glPopMatrix();
    
    //draw right hand
    
    glPushMatrix();
    glColor4f( 1.0, 1.0, 1.0, 1.0 );
    glRotatef( -90, 1, 0.4, 0 );//0.35 angle to right
    glTranslatef(1.5*TOP_BODY,0.18,-0.04);//right   (x,-z,y)
    //normal   if 'jump' glRotatef(150, 0, -100, 0)
    drawCylinder( WIDTH_ARMS, WIDTH_ARMS, LENGTH_ARMS, SLICES, STACKS);
    glColor4f( 0.0, 0.0, 0.0, 1.0 );
    glTranslatef( 0.03, 0, 0);
    drawSphere(WIDTH_ARMS, SLICES, STACKS);
    glPopMatrix();

    
    //draw head
    glPushMatrix();
    glColor4f( 1.0, 1.0, 1.0, 1.0 );
    glTranslatef(0, HEIGHT_BODY*1.3, 0);
    drawSphere( WIDTH_HEAD, SLICES, STACKS );
    glPopMatrix();
    
    //draw eyes
    glPushMatrix();
    glTranslatef(-0.8*WIDTH_EYES, HEIGHT_BODY*1.3+WIDTH_HEAD*0.2, WIDTH_HEAD-WIDTH_EYES);
    glColor4f( 0.0, 0.0, 0.0, 1.0 );
    drawSphere( WIDTH_EYES,SLICES,STACKS);
    glTranslatef(1.6*WIDTH_EYES, 0.0f, 0.0f);
    drawSphere( WIDTH_EYES,SLICES,STACKS);
    glPopMatrix();
    
    
    //draw ears
    glPushMatrix();
    glTranslatef(-0.31,HEIGHT_BODY*1.3+WIDTH_HEAD*0.8,0.1);//left
    drawCylinder(HEIGHT_EAR, HEIGHT_EAR, THICKNESS_EAR, SLICES, STACKS);
    glTranslatef(2*0.31,0,0);//right
    drawCylinder(HEIGHT_EAR, HEIGHT_EAR, THICKNESS_EAR, SLICES, STACKS);
    glPopMatrix();
    
}
