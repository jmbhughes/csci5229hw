#ifndef Definitions
#define Definitions

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>

#ifdef USEGLEW
#include <GL/glew.h>
#endif
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

void error_check(const char* where);

//  Macro for sin & cos in degrees
#define Cos(th) cos(M_PI/180*(th))
#define Sin(th) sin(M_PI/180*(th))

#define ACos(f) acos(f)*180/M_PI
#define ASin(f) asin(f)*180/M_PI

#ifdef __cplusplus
}
#endif

#endif
