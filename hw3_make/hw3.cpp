#include <stdio.h>
#include <math.h>
#include "CSCIx229.h"
#include <iostream>
#include "FerrisWheel.h"
#include "Mug.h"
#include "Ring.h"

// GLOBALS
// Viewing
int th = 0;       // Azimuth of view angle
int ph = 0;       // Elevation of view angle

/*
 *  Print any errors encountered
 *  copied from Schreuder's example 5
 */
void error_check(const char* where) {
    int err = glGetError();
    if (err) fprintf(stderr,"ERROR: %s [%s]\n",gluErrorString(err),where); //TODO: change to iostream
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

    // Set view angle
    glRotated(ph,1,0,0);
    glRotated(th,0,1,0);

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

    // draw a ferris wheel chair
    FerrisWheelChair c = FerrisWheelChair(0, 0, 0.5, 0.34, 0, 0, 0.7);
    c.draw();

    // draw an example ring
    Ring r = Ring(0.1, -0.3, 0.3, 0.2, 0.1);
    r.draw();

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
    double w2h = (height>0) ? (double)width/height : 1;
    // Set viewport as entire window
    glViewport(0,0, width,height);
    // Select projection matrix
    glMatrixMode(GL_PROJECTION);
    // Set projection to identity
    glLoadIdentity();
    // Orthogonal projection:  unit cube adjusted for aspect ratio
    glOrtho(-w2h,+w2h, -1.0,+1.0, -1.0,+1.0);
    // Select model view matrix
    glMatrixMode(GL_MODELVIEW);
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
}
/*
 *  GLUT calls this routine when an arrow key is pressed
 *  copied from Schreuder's example 6
 */
void special(int key, int x, int y) {
    const int view_step = 5;
    // Right arrow key - increase azimuth by 5 degrees
    if (key == GLUT_KEY_RIGHT)
        th += view_step;
        // Left arrow key - decrease azimuth by 5 degrees
    else if (key == GLUT_KEY_LEFT)
        th -= view_step;
        // Up arrow key - increase elevation by 5 degrees
    else if (key == GLUT_KEY_UP)
        ph += view_step;
        // Down arrow key - decrease elevation by 5 degrees
    else if (key == GLUT_KEY_DOWN)
        ph -= view_step;
    //  Keep angles to +/-360 degrees
    th %= 360;
    ph %= 360;
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
    glutCreateWindow("HW 3: James Marcus Hughes");

    // Tell GLUT to call "display" when the scene should be drawn
    glutDisplayFunc(display);

    // Tell GLUT to call "reshape" when the window is resized
    glutReshapeFunc(reshape);

    // Tell GLUT to call "special" when an arrow key is pressed
    glutSpecialFunc(special);

    // Tell GLUT to call "key" when a key is pressed
    glutKeyboardFunc(key);

    // Tell GLUT to call "idle" when nothing else is going on
    // glutIdleFunc(idle);

    // Pass control to GLUT so it can interact with the user
    error_check("init");

    glutMainLoop();

    return 0;
}