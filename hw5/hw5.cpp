#include <stdio.h>
#include <math.h>
#include "Definitions.h"
#include <iostream>
#include <stdarg.h>
#include "Mug.h"
#include "Ring.h"
#include "Ball.h"
#include "Cylinder.h"
#include "RectangularPrism.h"
#include "FerrisWheel.h"

// GLOBALS
// Viewing
int th = 0;       // Azimuth of view angle
int ph = 0;       // Elevation of view angle
int mode = 1;     // projection mode, 1 = overhead ortho, 2 = overhead perspective, 3 = first person
int fov=55;       //  Field of view (for perspective)
double asp=1;     //  Aspect ratio
double dim=5.0;   //  Size of world

// eye location
double Ex = 0;
double Ey = 0;
double Ez = 4.5;

// facing direction
double view_angle = 180;
double dx = Sin(view_angle);
double dy = 0;
double dz = Cos(view_angle);


// Light values
int one       =   1;  // Unit value
int distance  =   5;  // Light distance
int smooth    =   1;  // Smooth/Flat shading
int local     =   0;  // Local Viewer Model
int emission  =   0;  // Emission intensity (%)
int ambient   =  30;  // Ambient intensity (%)
int diffuse   = 100;  // Diffuse intensity (%)
int specular  =   0;  // Specular intensity (%)
int shininess =   0;  // Shininess (power of two)
float shiny   =   1;  // Shininess (value)
int zh        =  90;  // Light azimuth
float ylight  =   0;  // Elevation of light
int move      =   1;  // boolean of light movement
int rotation  =  90;  // ferris wheel rotation
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

    //  Translate intensity to color vectors
    float Ambient[]   = {0.01*ambient ,0.01*ambient ,0.01*ambient ,1.0};
    float Diffuse[]   = {0.01*diffuse ,0.01*diffuse ,0.01*diffuse ,1.0};
    float Specular[]  = {0.01*specular,0.01*specular,0.01*specular,1.0};

    //  Light position
    float Position[]  = {distance*Cos(zh),ylight,distance*Sin(zh),1.0};
    //  Draw light position as ball (still no lighting here)
    glColor3f(1,1,1);
    Ball b = Ball(Position[0],Position[1],Position[2] , 0.1);
    b.draw(emission, shiny);
    //  OpenGL should normalize normal vectors
    glEnable(GL_NORMALIZE);

    //  Enable lighting
    glEnable(GL_LIGHTING);

    //  Location of viewer for specular calculations
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,local);

    //  glColor sets ambient and diffuse color materials
    glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);

    //  Enable light 0
    glEnable(GL_LIGHT0);

    //  Set ambient, diffuse, specular components and position of light 0
    glLightfv(GL_LIGHT0,GL_AMBIENT ,Ambient);
    glLightfv(GL_LIGHT0,GL_DIFFUSE ,Diffuse);
    glLightfv(GL_LIGHT0,GL_SPECULAR,Specular);
    glLightfv(GL_LIGHT0,GL_POSITION,Position);

    // Draw the scene
    // draw a mug
    /*double base_color[3] = {0.25,0.25,0.25};
    double side_color[3] = {0.3,0.16,0.40};
    double inside_color[3] = {0.3, 0.3, 0.4};
    double top_color[3] = {1, 1, 0};
    double handle_color[3] = {1, 1, 0};
    Mug m = Mug(0, 0, 0, 2.0, 1.0, 0, 90, 270);
            //base_color, side_color, inside_color, top_color, handle_color);
    m.draw();*/

    // draw a cylinder
    /*double base_color[3] = {0.1,0.1,0.8};
    double side_color[3] = {0.03,0.16,0.40};
    Cylinder c = Cylinder(0, 0, 0, 1, 0.1, 0, 0, base_color, base_color, side_color);
    c.draw();*/

    // draw a rectangular prism

    //RectangularPrism rp = RectangularPrism(0, 0, 0, 1, 1, 1, 30, 90, 180);
    //rp.draw();

    // draw a chair
    //FerrisWheelChair f = FerrisWheelChair(0, 0, 0, 90, 0, 180, 2);
    //FerrisWheelChair f = FerrisWheelChair(0, 0, 0, 0, 0, 0, 1);
    //f.draw();

    //FerrisWheel f = FerrisWheel(0, 0, 0, 1);
    //f.draw(rotation);

    Ring r = Ring(0, 0, 0, 1, 2);
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
    asp = (height>0) ? (double)width/height : 1;
    // Set viewport as entire window
    glViewport(0,0, width,height);

    project(); // update projection

    // Set model view to identity
    glLoadIdentity();
}

/*
 *  GLUT calls this routine when idle
 */
void idle()
{
    //  Elapsed time in seconds
    double t = glutGet(GLUT_ELAPSED_TIME)/1000.0;
    zh = fmod(90*t,360.0);
    rotation = fmod(20*t, 360.0);
    //  Tell GLUT it is necessary to redisplay the scene
    glutPostRedisplay();
}

/*
 * GLUT calls this routine when a regular key is clicked.
 * keybindings: escape key exits
 */
void key(unsigned char ch, int x, int y) {
    // exit upon hitting escape
    switch (ch) {
        // escape on hitting exit
        case 27:
            exit(0);
            break;
        // change view modes
        case '1': // orthogonal view
            mode = 1;
            break;
        case '2': // perspective overhead view
            mode = 2;
            break;
        case '3': // perspective first person view
            mode = 3;
            break;
        // change the light elevation
        case '[':
            ylight -= 0.1;
            break;
        case ']':
            ylight += 0.1;
            break;
        // change the light location
        case '<':
            zh += 1;
            break;
        case '>':
            zh -= 1;
            break;
        // toggle the light movement
        case 'm':
            move = 1 - move;
            break;

        default:
            std::cout << ch << std::endl;
            break;
    }
    project(); // reproject
    glutIdleFunc(move?idle:NULL);
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
    switch(key) {
        case GLUT_KEY_RIGHT:
        case GLUT_KEY_DOWN:
        case GLUT_KEY_LEFT:
        case GLUT_KEY_UP:
            if (mode == 1 || mode == 2) { // if in an overhead view
                change_overhead_view(key);
            } else { // in a first person view
                change_firstperson_view(key);
            }
            break;
        case GLUT_KEY_PAGE_DOWN:
            if (dim > 1)
                dim -= 0.1;
            break;
        case GLUT_KEY_PAGE_UP:
            dim += 0.1;
            break;
    }
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
    glutCreateWindow("HW 5: James Marcus Hughes");

    // Tell GLUT to call "display" when the scene should be drawn
    glutDisplayFunc(display);

    // Tell GLUT to call "reshape" when the window is resized
    glutReshapeFunc(reshape);

    // Tell GLUT to call "special" when an arrow key is pressed
    glutSpecialFunc(special);

    // Tell GLUT to call "key" when a key is pressed
    glutKeyboardFunc(key);

    // Tell GLUT  to call "idle" when no interaction
    glutIdleFunc(idle);

    // Pass control to GLUT so it can interact with the user
    error_check("init");

    glutMainLoop();

    return 0;
}