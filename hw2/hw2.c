/*
 * hw2: Lorenz System
 * 
 * James Marcus Hughes
 *
 * Display Lorenz Attractor with modifiable parameters and views. 
 *
 * Key bindings:
 *   s/S     decrease/increase the s paramater
 *   r/R     decrease/increase the r parameter
 *   b/B     decrease/increase the b parameter
 *   arrows  change view angle
 *   0       reset view angle
 *   a       toggle axes on and off
 *   ESC     exit
 */

#include "CSCIx229.h"
#include <stdbool.h>
#include <stdio.h>

//-------------------------------------------------
// GLOBALS
// Lorenz Parameters 
double s  = 10.0;
double b  = 8.0/3.0;
double r  = 28.0;

double x = 1.0; // current x position
double y = 1.0; // current y position
double z = 1.0; // current z position

double dt = 0.001; // how rapidly parameters should change by, the step size
double scale = 0.05; // decreases attractor to show in field
int iterations = 500000; // how many steps to evaluate to show attractor

// Viewing
int th = 0;       // Azimuth of view angle
int ph = 0;       // Elevation of view angle
bool showAxes = true; // whether to print axes
int viewStep = 5; // how many degrees the arrows will change view by
//-------------------------------------------------

/*
 *  Convenience routine to output raster text
 *  Use VARARGS to make this more flexible
 *  taken from Schreduer example 5
 */
#define LEN 8192  // Maximum length of text string
void Print(const char* format , ...) {
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
 *  Function to print any errors encountered
 *  copied from Schreuder's example 5
 */
void ErrCheck(const char* where) {
   int err = glGetError();
   if (err) fprintf(stderr,"ERROR: %s [%s]\n",gluErrorString(err),where);
}

/*
 *  Calcuates the location of the point after the next Lorenz iteration
 */
void stepLorenz() {
    // Determine how much change is in system
    double dx = s*(y-x);
    double dy = x*(r-z)-y;
    double dz = x*y - b*z;

    // Update the parameters
    x += dt*dx;
    y += dt*dy;
    z += dt*dz;
}

/*
 *  Draws a Lorenz curve from (1,1,1) with the global parameters specified 
 */
void drawLorenzCurve(float xstart, float ystart, float zstart) {
    //  Set the initial point to (1, 1, 1)
    x = xstart; //1.0;
    y = ystart; //1.0;
    z = zstart; //1.0;

    //  Draw connected line strips, the count defined by the global parameter iterations
    //  Color will vary with the fraction drawn so far, starting blue and going red
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < iterations; i++) {
        // Determine the current color by the fraction drawn so far
        double fractionDrawn = (double) i / (double) iterations;
        //printf("%lf\n", log(fractionDrawn));
        glColor3f(1.0 * fractionDrawn, 0.0, 1.0 * (1 - fractionDrawn));

        // add the point and increment the lorenz attractor for the next point
        glVertex3f(scale*x, scale*y, scale*z);
        stepLorenz();
    }
    glEnd();
}

/*
 *  Draws the axes in white 
 */
void drawAxes() {
    glColor3f(1,1,1);
    glBegin(GL_LINES);
    glVertex3d(0,0,0);
    glVertex3d(1,0,0);
    glVertex3d(0,0,0);
    glVertex3d(0,1,0);
    glVertex3d(0,0,0);
    glVertex3d(0,0,1);
    glEnd();
    //  Label axes
    glRasterPos3d(1,0,0);
    Print("X");
    glRasterPos3d(0,1,0);
    Print("Y");
    glRasterPos3d(0,0,1);
    Print("Z");
}

/*
 * Function is called by GLUT to display a scene
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
   drawLorenzCurve(1.0, 1.0, 1.0);

   // Draw axes if requested
   if (showAxes)
       drawAxes();
   
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
void reshape(int width,int height) {
    double dim = 3.0;
    
   //  Calculate width to height ratio
   double w2h = (height>0) ? (double)width/height : 1;
   //  Set viewport as entire window
   glViewport(0,0, width,height);

   //  Select projection matrix
   glMatrixMode(GL_PROJECTION);

   //  Set projection to identity
   glLoadIdentity();

   //  Orthogonal projection:  unit cube adjusted for aspect ratio
   glOrtho(-w2h*dim,+w2h*dim, -dim,+dim, -dim,+dim);

   //  Select model view matrix
   glMatrixMode(GL_MODELVIEW);

   //  Set model view to identity
   glLoadIdentity();
}

/*
 *  GLUT calls this routine when an arrow key is pressed
 *  mappings are:
 *      RIGHT : rotates azimuth by +viewStep
 *      LEFT  : rotates azimuth by -viewstep
 *      UP    : rotates elevation by +viewStep
 *      DOWN  : rotates elevation by -viewStep
 *  copied from Schreuder's example 6
 */
void special(int key, int x, int y) {
   //  Right arrow key - increase azimuth by viewStep
   if (key == GLUT_KEY_RIGHT)
      th += viewStep;
   //  Left arrow key - decrease azimuth by viewStep
   else if (key == GLUT_KEY_LEFT)
      th -= viewStep;
   //  Up arrow key - increase elevation by viewStep
   else if (key == GLUT_KEY_UP)
      ph += viewStep;
   //  Down arrow key - decrease elevation by viewStep
   else if (key == GLUT_KEY_DOWN)
      ph -= viewStep;

   //  Keep angles to +/-360 degrees
   th %= 360;
   ph %= 360;

   //  Tell GLUT it is necessary to redisplay the scene
   glutPostRedisplay();
}

/*
 *  GLUT uses this on a regular key input
 *  key bindings are:
 *      s/S     decrease/increase the s paramater
 *      r/R     decrease/increase the r parameter
 *      b/B     decrease/increase the b parameter
 *      arrows  change view angle
 *      0       reset view angle
 *      a       toggle axes on and off
 *      ESC     exit
 */
void key(unsigned char ch, int x, int y) {
    switch (ch) {
    case 27: // escape key
        exit(0);
        break;
    case 'r':
        if (r - 0.1 > 0)
            r -= 0.1;
        break;
    case 'R':
        r += 0.1;
        break;
    case 'b':
        if (b - 0.1 > 0) 
            b -= 0.1;
        break;
    case 'B':
        b += 0.1;
        break;
    case 's':
        if (s - 0.1 > 0)
            s -= 0.1;
        break;
    case 'S':
        s += 0.1;
        break;
    case 'a':
        showAxes = !showAxes;
        break;
    case '0':
        ph = 0;
        th = 0;
        break;
    default:
        printf("Key not bound. See README.\n");
    }

    // ask to update 
    glutPostRedisplay();
}


/*
 *  Main method for execution
 */
int main(int argc, char *argv[]) {
    
   //  Initialize GLUT and process user parameters
   glutInit(&argc,argv);

   // Initialize the display mode
   glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
   
   //  Request 900 x 900 pixel window
   glutInitWindowSize(900, 900);
   
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

   //  Pass control to GLUT so it can interact with the user
   ErrCheck("init");

   // Start running!
   glutMainLoop();
   return 0;
}
