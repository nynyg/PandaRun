//
//  DrawPrimitives.cpp
//  OpenCVTest
//
//  Copyright © 2016 Nan. All rights reserved.
//

#include <stdio.h>
#include "DrawPrimitives.h"

void drawSphere(double r, int lats, int longs) {
    int i, j;
    for(i = 0; i <= lats; i++) {
        double lat0 = M_PI * (-0.5 + (double) (i - 1) / lats);
        double z0  = r * sin(lat0);
        double zr0 = r *  cos(lat0);
        
        double lat1 = M_PI * (-0.5 + (double) i / lats);
        double z1  = r * sin(lat1);
        double zr1 = r * cos(lat1);
        
        glBegin(GL_QUAD_STRIP);
        for(j = 0; j <= longs; j++) {
            double lng = 2 * M_PI * (double) (j - 1) / longs;
            double x = cos(lng);
            double y = sin(lng);
            
            glNormal3f(x * zr0, y * zr0, z0);
            glVertex3f(x * zr0, y * zr0, z0);
            glNormal3f(x * zr1, y * zr1, z1);
            glVertex3f(x * zr1, y * zr1, z1);
        }
        glEnd();
    }
}


void drawCone(GLdouble base, GLdouble height, GLint slices, GLint stacks)
{
    GLUquadricObj* quadric = gluNewQuadric();
    gluQuadricDrawStyle(quadric, GLU_FILL);
    
    gluCylinder(quadric, base, (GLdouble)0.0, height, slices, stacks);
    const GLdouble innerradius = 0.0;
    gluDisk(quadric, innerradius, base, slices, stacks);
    
    gluDeleteQuadric(quadric);
}

void drawCylinder(GLdouble base,GLdouble top,GLdouble height,GLint slices, GLint stacks)
{
    GLUquadricObj* quadric = gluNewQuadric();
    gluQuadricDrawStyle(quadric, GLU_FILL);
    gluQuadricOrientation(quadric,GLU_OUTSIDE);
    //  gluQuadricNormals(quadric, GLU_SMOOTH);
    gluCylinder(quadric, base, top, height, slices, stacks);
    const GLdouble innerradius = 0.0;
    gluDisk(quadric, innerradius, base, slices, stacks);
    gluDeleteQuadric(quadric);
}