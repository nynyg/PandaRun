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

void Panda::drawArrow(float resultTransposedMatrix[4][16]){
    for (int i = 0;i<4;i++){
        if(resultTransposedMatrix[i][0]!=-1){
            glLoadMatrixf(resultTransposedMatrix[i]);
            glRotatef(-90, 1, 0, 0 );
            glScalef(0.03, 0.03, 0.03);
            
            glColor4f(1.0,0,0,1.0);
            drawCone(0.1,0.3,10,10);
            
            GLUquadricObj *quadratic;
            quadratic=gluNewQuadric();
            glTranslatef(0, 0, -0.4);
            gluCylinder(quadratic,0.1f,0.1f,0.4f,32,32);
            
        }
    }
}

void Panda::drawStone(float resultTransposedMatrix[16]){
}

void Panda::drawBamboo(float resultTransposedMatrix[16]){
    glLoadMatrixf(resultTransposedMatrix);
    glRotatef(-60, 1, 0, 0 );
    glScalef(0.03, 0.03, 0.03);
    
    glColor4f(0.1,1.0,0.1,1.0);

    GLUquadricObj *quadratic;
    quadratic=gluNewQuadric();
    glTranslatef(0, 0, -0.4);
    gluCylinder(quadratic,0.1f,0.1f,0.4f,32,32);

    glTranslatef(0, 0, -0.4);
    gluCylinder(quadratic,0.1f,0.1f,0.4f,32,32);
    
    glColor4f(0.2, 0.2, 0.2, 1.0);
    glTranslatef(0, 0, 0.4);
    gluCylinder(quadratic,0.11f,0.11f,0.05f,32,32);
}
