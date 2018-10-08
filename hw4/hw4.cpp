#include <stdio.h>
#include <math.h>
#include "Definitions.h"
#include <iostream>
#include "FerrisWheel.h"
#include <stdarg.h>
#include "Mug.h"
#include "Ring.h"


// GLOBALS
// Viewing
int th = 0;       // Azimuth of view angle
int ph = 0;       // Elevation of view angle
int mode = 1;     // projection mode, 1 = overhead ortho, 2 = overhead perspective, 3 = first person
int fov=55;       //  Field of view (for perspective)
double asp=1;     //  Aspect ratio
double dim=1.5;   //  Size of world

// eye location
double Ex = 0;
double Ey = 0;
double Ez = 4.5;
// facing direction
double view_angle = 180;
double dx = Sin(view_angle);
double dy = 0;
double dz = Cos(view_angle);

/*
 *  Print any errors encountered
 *  copied from Schreuder's example 5
 */
void error_check(const char* where) {
    int err = glGetError();
    if (err) fprintf(stderr,"ERROR: %s [%s]\n",gluErrorString(err),where); //TODO: change to iostream
}

/*
 *  Convenience routine to output raster text
 *  Use VARARGS to make this more flexible
 */
#define LEN 8192  //  Maximum length of text string
void print(const char* format , ...)  {
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
 *  Set projection
 *  modified from Schreuder's example 9
 */
void project() {
    //  Tell OpenGL we want to manipulate the projection matrix
    glMatrixMode(GL_PROJECTION);
    //  Undo previous transformations
    glLoadIdentity();
    //  Perspective transformation
    if (mode == 1) {
        glOrtho(-asp*dim,+asp*dim, -dim,+dim, -dim,+dim);
    } else if (mode == 2){
        gluPerspective(fov, asp, dim / 4, 4 * dim);
    } else if (mode == 3) {
        gluPerspective(fov, asp, dim / 4, 4 * dim);
    }
    //  Switch to manipulating the model matrix
    glMatrixMode(GL_MODELVIEW);
    //  Undo previous transformations
    glLoadIdentity();
}

/*
 * function is called by GLUT to display a scene
 */
void display() {
    // Clear screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    // Reset previous transforms
    glLoadIdentity();

    // update the current view
     if (mode == 1) { //  Orthogonal - overhead
        glRotatef(ph,1,0,0);
        glRotatef(th,0,1,0);
      } else if (mode == 2) { // Perspective - overhead
         gluLookAt(0, 0, 3.5,
                   0, 0, -1,
                   0, 1, 0);
         glRotatef(ph,1,0,0);
         glRotatef(th,0,1,0);
      } else if (mode == 3) { // Persepctive - first person
        // update eye position
         gluLookAt(Ex, Ey, Ez,
                   Ex + dx, Ey + dy, Ez + dz,
                   0, 1, 0);
      }

    // Draw the scene
    // draw a big ferris wheel
    auto obj = new FerrisWheel(0.0, 0.0, 0.0, 0.8, 0.2);
    obj->draw();

    // draw a smaller ferris wheel
    glPushMatrix();
    glScaled(0.4, 0.4, 0.4);
    obj = new FerrisWheel(0.8, 0.8, 0.8, 0.8, 0.2);
    obj->draw();
    glPopMatrix();

    // draw a mug
    Mug m = Mug(-0.45, 0.45, -0.45, 0.3, 0.2, 280, 30, 90);
    m.draw();

    // draw a smaller rotated mug
    Mug m2 = Mug(-0.75, -0.1, 0.45, 0.5, 0.1, 100, 30, 90);
    m2.draw();

    // draw a smaller rotated mug
    Mug m3 = Mug(-0.15, -0.1, 0.45, 0.5, 0.1, 100, 40, 130);
    m3.draw();

    // draw a ferris wheel chair
    FerrisWheelChair c = FerrisWheelChair(0, 0, 0.5, 0.34, 0, 0, 0.7);
    c.draw();

    // Print state information
    glWindowPos2i(5, 5);
    glColor3d(1, 1, 1);
    print("Angle=%d,%d  Dim=%.1f FOV=%d Projection=%s",th,ph,dim,fov,mode?"Perpective":"Orthogonal");
    // Update the display
    glFlush();
    glutSwapBuffers();
}

/*
 *  This function is called by GLUT when the window is resized
 *  copied from Schreuder's example 5
 */
void reshape(int width,int height) {
    // Calculate width to height ratio
    asp = (height>0) ? (double)width/height : 1;
    // Set viewport as entire window
    glViewport(0,0, width,height);

    project(); // update projection

    // Set model view to identity
    glLoadIdentity();
}


/*
 * GLUT calls this routine when a regular key is clicked.
 * keybindings: escape key exits
 */
void key(unsigned char ch, int x, int y) {
    if (ch == 27)
        exit(0);
    else if (ch == '1') // set to orthogonal view
        mode = 1;
    else if (ch == '2') // set to persepctive "overhead" view
        mode = 2;
    else if (ch == '3') // set to persepctive first person view
        mode = 3;
    project(); // reproject
    glutPostRedisplay();
}

/*
 * Given an input key, update the viewer in an overhead setting
 */
void change_overhead_view(int key) {
    const int view_step = 5;
    switch(key) {
        case GLUT_KEY_RIGHT: // roatate azimuth
            th += view_step;
            break;
        case GLUT_KEY_LEFT: // rotate azimuth
            th -= view_step;
            break;
        case GLUT_KEY_UP: // rotate altitude
            ph += view_step;
            break;
        case GLUT_KEY_DOWN: // rotate altitude
            ph -= view_step;
            break;
    }
    th %= 360;
    ph %= 360;
}

/*
 * Given an input key, update the viewer in the first person setting
 */
void change_firstperson_view(int key) {
    const int view_step = 1; // how much to rotate view by
    const double tstep = 0.1; // how quickly to step
    switch(key) {
        case GLUT_KEY_RIGHT: // rotate the view
            view_angle += view_step;
            dx = Sin(view_angle);
            dy = 0;
            dz = Cos(view_angle);
            break;
        case GLUT_KEY_LEFT: // rotate the view
            view_angle -= view_step;
            dx = Sin(view_angle);
            dy = 0;
            dz = Cos(view_angle);
            break;
        case GLUT_KEY_UP: // move forward
            Ex += tstep * dx;
            Ey += tstep * dy;
            Ez += tstep * dz;
            break;
        case GLUT_KEY_DOWN: // move backward
            Ex -= tstep * dx;
            Ey -= tstep * dy;
            Ez -= tstep * dz;
            break;
    }
}
/*
 *  GLUT calls this routine when an arrow key is pressed
 *  copied from Schreuder's example 6
 */
void special(int key, int x, int y) {
    if (mode == 1 || mode == 2) // if in an overhead mode
        change_overhead_view(key);
    else // mode == 3,  in a first person mode
        change_firstperson_view(key);
    project(); // update projection

    // Tell GLUT it is necessary to redisplay the scene
    glutPostRedisplay();
}

/*
 * Main executable method
 */
int main(int argc, char *argv[]) {

    //  Initialize GLUT and process user parameters
    glutInit(&argc,argv);

    // Enable color, depth, and double buffering
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    // Request 900 x 900 pixel window
    glutInitWindowSize(900, 900);

    // Create the window
    glutCreateWindow("HW 4: James Marcus Hughes");

    // Tell GLUT to call "display" when the scene should be drawn
    glutDisplayFunc(display);

    // Tell GLUT to call "reshape" when the window is resized
    glutReshapeFunc(reshape);

    // Tell GLUT to call "special" when an arrow key is pressed
    glutSpecialFunc(special);

    // Tell GLUT to call "key" when a key is pressed
    glutKeyboardFunc(key);

    // Pass control to GLUT so it can interact with the user
    error_check("init");

    glutMainLoop();

    return 0;
}