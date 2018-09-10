#include "CSCIx229.h"
#include <stdio.h>
#include <math.h>

//-------------------------------------------------
// GLOBAL DEFINES
#define PI 3.14159265
//-------------------------------------------------


//-------------------------------------------------
// GLOBAL PARAMETERS
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
int th = 0;       // Azimuth of view angle
int ph = 0;       // Elevation of view angle
int viewStep = 5;
//-------------------------------------------------


/*
 *  Convenience routine to output raster text
 *  Use VARARGS to make this more flexible
 * taken from Schreduer example 5
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

void drawGround(){ 
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(-1.0, 0.0, -1.0);
    glVertex3f(1.0, 0.0, -1.0);
    glVertex3f(1.0, 0.0, 1.0);
    glVertex3f(-1.0, 0.0, 1.0);
    glEnd();
}

void drawAnnulus(float innerRadius, float outerRadius){
    int numSections = 100;
    float thetaStep = 2 * PI / numSections;
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(outerRadius * cos(0), outerRadius * sin(0));
    for (int i = 0; i < numSections; i++) {
        glVertex2f(innerRadius * cos(i * thetaStep), innerRadius * sin(i * thetaStep));
        glVertex2f(outerRadius * cos((i+1) * thetaStep), outerRadius * sin((i+1) * thetaStep));
    }
    glVertex2f(innerRadius * cos(numSections * thetaStep), innerRadius * sin(numSections * thetaStep));
    glEnd();
}

void drawCircle(float radius) {
    int numSections = 100;
    float thetaStep = 2 * PI / numSections;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0, 0);
    for (int i = 0; i <= numSections; i++) {
        glVertex2f(radius * cos(i * thetaStep), radius * sin(i * thetaStep));
    }
    
    glEnd();
}

void drawCylinder(float radius, float height) {
    drawCircle(radius);
    
    int numSections = 100;
    float thetaStep = 2 * PI / numSections;
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= numSections; i++) {
        glVertex3f(radius * cos(i * thetaStep), radius * sin(i * thetaStep), 0);
        glVertex3f(radius * cos(i * thetaStep), radius * sin(i * thetaStep), height);
    }
    glEnd();
    glTranslatef(0, 0, height);
    drawCircle(radius);
}

/*
 *  Function to print any errors encountered
 *  copied from Schreuder's example 5
 */
void ErrCheck(const char* where) {
   int err = glGetError();
   if (err) fprintf(stderr,"ERROR: %s [%s]\n",gluErrorString(err),where);
}


double TREE_FACTOR = 1.0;
double TREE_LINE_BASE_LEN = 0.1;

void drawTree(int currentDepth, int maxDepth)
{
    if (currentDepth > maxDepth)
        return;

    if (currentDepth <= maxDepth - 2)
    {
        glColor3d(0.45, 0.2, 0.05);
        glLineWidth(10 * pow(TREE_FACTOR, currentDepth));
    }
    else
    {
        glColor3d(0, 0.5, 0);
        glLineWidth(30 * pow(TREE_FACTOR, currentDepth));
    }

    double lineLen = TREE_LINE_BASE_LEN * pow(TREE_FACTOR, currentDepth);
    glBegin(GL_LINES);
    glVertex2d(0, 0);
    glVertex2d(0, lineLen);
    glEnd();

    int angle1 = 10 + rand() % 40;
    int angle2 = 10 + rand() % 40;

    glTranslated(0, lineLen, 0);
    glRotated(-angle1, 0, 0, 1);
    drawTree(currentDepth + 1, maxDepth);
    glRotated(angle1 + angle2, 0, 0, 1);
    drawTree(currentDepth + 1, maxDepth);
    glRotated(-angle2, 0, 0, 1);
    glTranslated(0, -lineLen, 0);
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
 
   //drawGround();
   //drawAnnulus(0.5, 0.75);
   // drawCircle(0.5);
   //drawCylinder(0.5, 0.5);
   drawTree(0, 10);
   // Update the display
   glFlush();
   glutSwapBuffers();
}

/*
 *  This function is called by GLUT when the window is resized
 *  copied from Schreuder's example 5
 */
void reshape(int width,int height) {
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
        r += 1;
    } else if (ch == '-') {
        r -= 1;
    }
    glutPostRedisplay();
}

void idle() {
    ph += 1;
    th += 1;
    glutPostRedisplay();
}

int main(int argc, char *argv[]) {
    
   //  Initialize GLUT and process user parameters
   glutInit(&argc,argv);
 
   glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
   
   //  Request 500 x 500 pixel window
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
   // glutKeyboardFunc(key);
   
   //  Tell GLUT to call "idle" when nothing else is going on
   // glutIdleFunc(idle);

   //  Pass control to GLUT so it can interact with the user
   ErrCheck("init");

   glutMainLoop();
   return 0;
}
