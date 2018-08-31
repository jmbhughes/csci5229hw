#include "CSCIx229.h"
#include <stdio.h>

//-------------------------------------------------
// GLOBALS
// Lorenz Parameters 
double s  = 10.0;
double b  = 2.6666;
double r  = 30.0;

double x = 1.0;
double y = 1.0;
double z = 1.0;

double dt = 0.001;
double scale = 0.01;
double offset = 1.0;
int iterations = 500000;

// Viewing
int th=0;       // Azimuth of view angle
int ph=0;       // Elevation of view angle
int viewStep=5;
//-------------------------------------------------


/*
 *  Convenience routine to output raster text
 *  Use VARARGS to make this more flexible
 * taken from Schreduer example 5
 */
#define LEN 8192  // Maximum length of text string
void Print(const char* format , ...)
{
   char    buf[LEN];
   char*   ch=buf;
   va_list args;
   //  Turn the parameters into a character string
   va_start(args,format);
   vsnprintf(buf,LEN,format,args);
   va_end(args);
   //  Display the characters one at a time at the current raster position
   while (*ch)
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*ch++);
}

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
void ErrCheck(const char* where) {
   int err = glGetError();
   if (err) fprintf(stderr,"ERROR: %s [%s]\n",gluErrorString(err),where);
}

void drawLorenzCurve() {
    x = 1.0;
    y = 1.0;
    z = 1.0;

    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < iterations; i++) {
        float fractionDrawn = (float) i / (float) iterations;
        glColor3f(1.0 * fractionDrawn, 0.0, 1.0 * (1 - fractionDrawn));
        glVertex3f(scale*x, scale*y, scale*z);
        stepLorenz();
    }
    glEnd();
}

/*
 * function is called by GLUT to display a scene
 */
void display() {
   // Clear screen
   glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

   // Reset previous transforms
   glLoadIdentity();

   // Set view angle
   glRotated(ph,1,0,0);
   glRotated(th,0,1,0);
 
   // Draw path
   drawLorenzCurve();

   // Print parameter settings at bottom left of screen
   glColor3f(1.0, 1.0, 1.0);
   glWindowPos2i(5,5);
   Print("s=%5.2f, b=%5.2f, r=%5.2f", s, b, r);

   // Update the display
   glFlush();
   glutSwapBuffers();
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

/*
 *  GLUT calls this routine when an arrow key is pressed
 *  copied from Schreuder's example 6
 */
void special(int key, int x, int y) {
   //  Right arrow key - increase azimuth by 5 degrees
   if (key == GLUT_KEY_RIGHT)
      th += viewStep;
   //  Left arrow key - decrease azimuth by 5 degrees
   else if (key == GLUT_KEY_LEFT)
      th -= viewStep;
   //  Up arrow key - increase elevation by 5 degrees
   else if (key == GLUT_KEY_UP)
      ph += viewStep;
   //  Down arrow key - decrease elevation by 5 degrees
   else if (key == GLUT_KEY_DOWN)
      ph -= viewStep;
   //  Keep angles to +/-360 degrees
   th %= 360;
   ph %= 360;
   //  Tell GLUT it is necessary to redisplay the scene
   glutPostRedisplay();
}

void key(unsigned char ch, int x, int y) {
    if (ch == '+') {
        r += 0.1;
    } else if (ch == '-') {
        r -= 0.1;
    }
    glutPostRedisplay();
}

int main(int argc, char *argv[]) {
    
   //  Initialize GLUT and process user parameters
   glutInit(&argc,argv);
 
   glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
   
   //  Request 500 x 500 pixel window
   glutInitWindowSize(500,500);
   
   //  Create the window
   glutCreateWindow("HW 2: James Marcus Hughes");
   
   //  Tell GLUT to call "display" when the scene should be drawn
   glutDisplayFunc(display);
   
  //  Tell GLUT to call "reshape" when the window is resized
   glutReshapeFunc(reshape);
   
   //  Tell GLUT to call "special" when an arrow key is pressed
   glutSpecialFunc(special);
   
   //  Tell GLUT to call "key" when a key is pressed
   glutKeyboardFunc(key);
   
   //  Tell GLUT to call "idle" when nothing else is going on
   // glutIdleFunc(display);

   //  Pass control to GLUT so it can interact with the user
   ErrCheck("init");

   glutMainLoop();
   return 0;
}
