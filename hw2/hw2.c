#include "CSCIx229.h"
#include <stdio.h>

/*  Lorenz Parameters  */
double s  = 10.0;
double b  = 2.6666;
double r  = 28.0;

double x = 1.0;
double y = 1.026;
double z = 0.998;

double dt = 0.001;
double scale = 0.03;
double offset = 1.0;

/*
 * Calcuates the location of the point after the next Lorenz iteration
 */
void stepLorenz() {
    double dx = s*(y-x);
    double dy = x*(r-z)-y;
    double dz = x*y - b*z;
    x += dt*dx;
    y += dt*dy;
    z += dt*dz;
}

/*
 *  Function to print any errors encountered
 *  copied from Schreuder's example 5
 */
void ErrCheck(const char* where)
{
   int err = glGetError();
   if (err) fprintf(stderr,"ERROR: %s [%s]\n",gluErrorString(err),where);
}

/*
 * function is called by GLUT to display a scene
 */
void display() {
   //  Clear screen
   glClear(GL_COLOR_BUFFER_BIT);

   //  Draw triangle
   stepLorenz();
   glPointSize(5.0);
   glEnable(GL_POINT_SMOOTH);
   glBegin(GL_POINTS);
   glVertex3f(scale*x, scale*y, scale*y);
   glEnd();

   //  Make scene visible
   glFlush();
}

/*
 *  This function is called by GLUT when the window is resized
 *  copied from Schreuder's example 5
 */
void reshape(int width,int height)
{
   //  Calculate width to height ratio
   double w2h = (height>0) ? (double)width/height : 1;
   //  Set viewport as entire window
   glViewport(0,0, width,height);
   //  Select projection matrix
   glMatrixMode(GL_PROJECTION);
   //  Set projection to identity
   glLoadIdentity();
   //  Orthogonal projection:  unit cube adjusted for aspect ratio
   glOrtho(-w2h,+w2h, -1.0,+1.0, -1.0,+1.0);
   //  Select model view matrix
   glMatrixMode(GL_MODELVIEW);
   //  Set model view to identity
   glLoadIdentity();
}

int main(int argc, char *argv[]) {
    
   //  Initialize GLUT and process user parameters
   glutInit(&argc,argv);

    
   //  Request double buffered, true color window 
   // glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
   
   //  Request 500 x 500 pixel window
   // glutInitWindowSize(500,500);
   
   //  Create the window
   glutCreateWindow("HW 2: James Marcus Hughes");
   
   //  Tell GLUT to call "display" when the scene should be drawn
   glutDisplayFunc(display);
   
  //  Tell GLUT to call "reshape" when the window is resized
   glutReshapeFunc(reshape);
   
   //  Tell GLUT to call "special" when an arrow key is pressed
   // glutSpecialFunc(special);
   
   //  Tell GLUT to call "key" when a key is pressed
   // glutKeyboardFunc(key);
   
   //  Tell GLUT to call "idle" when nothing else is going on
   glutIdleFunc(display);

   //  Pass control to GLUT so it can interact with the user
   ErrCheck("init");

   glutMainLoop();
   return 0;
}
