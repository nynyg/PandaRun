//
//  Panda.cpp
//
//  Created by Nan on 16/6/30.
//  Copyright © 2016 Nan. All rights reserved.
//

#include "Panda.h"
#include "DrawPrimitives.h"

void Panda::drawPanda(float resultTransposedMatrix[16]){
    //glLoadTransposeMatrixf( resultMatrix );
    glLoadMatrixf( resultTransposedMatrix );
    glRotatef( -90, 1, 0, 0 );
    glScalef(0.03, 0.03, 0.03);
    
    
    //draw legs
    
    //draw body
    glPushMatrix();
    glRotatef( -90, 1, 0, 0 );
    glColor4f( 1.0, 1.0, 1.0, 1.0 );
    drawCylinder(BOTTOM_BODY, TOP_BODY, HEIGHT_BODY, SLICES, STACKS);
    glPopMatrix();
    
    //draw head
    glPushMatrix();
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
    
    glPopMatrix();
    
    
    // draw 3 white spheres
    //    glColor4f( 1.0, 1.0, 1.0, 1.0 );
    ////    drawSphere( 0.8, 10, 10 );
    ////    glTranslatef( 0.0, 0.8, 0.0 );
    //    drawSphere( 0.7, 10, 10 );
    //    glTranslatef( 0.0, 0.65, 0.0 );
    //    drawSphere( 0.4, 10, 10 );
    //
    //    // draw the eyes
    //    glPushMatrix();
    //    glColor4f( 0.0, 0.0, 0.0, 1.0 );
    //    glTranslatef( 0.2, 0.2, 0.2 );
    //    drawSphere( 0.066, 10, 10 );
    //    glTranslatef( 0, 0, -0.4 );
    //    drawSphere( 0.066, 10, 10 );
    //    glPopMatrix();
    //
    //    // draw a nose
    //    glColor4f( 1.0, 0.5, 0.0, 1.0 );
    //    glTranslatef( 0.3, 0.0, 0.0 );
    //    glRotatef( 90, 0, 1, 0 );
    //    drawCone( 0.1, 0.3, 10, 10 );
}
