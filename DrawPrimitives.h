#define GLFW_INCLUDE_GLU
#include "OSDetect.h"

#include <glfw/glfw3.h>
//#include <GL/gl.h>

#include <math.h>


/* PI */
#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif


void drawSphere(double r, int lats, int longs);

void drawCone(GLdouble base, GLdouble height, GLint slices, GLint stacks);

void drawCylinder(GLdouble base,GLdouble top,GLdouble height,GLint slices, GLint stacks);