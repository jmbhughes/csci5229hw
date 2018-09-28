/*
 * A basic rectangular prism drawer for OpenGL
 * A rectangular prism is specified by:
 *      - its location (x,y,z)
 *      - its size (width, length, height)
 *      - its orientation (angle_az, angle_alt): the azimuthal angle and altitudinal angle in degrees
 *      - and the colors of its faces
 */

#ifndef HW3NEW_RECTANGULARPRISM_H
#define HW3NEW_RECTANGULARPRISM_H


class RectangularPrism {
private:
    // position in the world
    double x;
    double y;
    double z;

    // size
    double width;
    double length;
    double height;

    // orientation
    double angle_az;
    double angle_alt;

    // colors of faces: [bottom, front, right, back, left, top]
    double face_colors[3*6];
public:
    /*
     * Draw a rectangular prism at (x,y,z) with dimensions (width, length, height)
     * with no rotations and default colors:
     * [magenta bottom, red front, green right, blue back, yellow left, cyan top]
     */
    RectangularPrism(double x, double y, double z, double width, double length, double height);

    /*
     * Draw a rectangular prism at (x,y,z) with dimensions (width, length, height)
     * with rotations of angle_az degrees azimuth and angle_alt degrees altitude and default colors:
     * [magenta bottom, red front, green right, blue back, yellow left, cyan top]
     */
    RectangularPrism(double x, double y, double z, double width, double length, double height,
            double angle_az, double angle_alt);

    /*
     * Draw a rectangular prism at (x,y,z) with dimensions (width, length, height)
     * with rotations of angle_az degrees azimuth and angle_alt degrees altitude and specified colors:
     * [bottom, front, right, back, left, top], each being an rgb number in (0,0,0)-(1,1,1)
     */
    RectangularPrism(double x, double y, double z, double width, double length, double height,
            double angle_az, double angle_alt,
            double face_colors[3*6]);

    // draw the specified rectangular prism
    void draw();
};

#endif //HW3NEW_RECTANGULARPRISM_H