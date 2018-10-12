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
    double sx;
    double sy;
    double sz;

    // orientation
    double rx;
    double ry;
    double rz;

    // colors of faces: [bottom, front, right, back, left, top]
    double face_colors[18];
public:
    /*
     * Draw a rectangular prism at (x,y,z) with dimensions (sx, sy, sz)
     * with no rotations and default colors:
     * [magenta bottom, red front, green right, blue back, yellow left, cyan top]
     */
    RectangularPrism(double x, double y, double z, double sx, double sy, double sz);

    /*
     * Draw a rectangular prism at (x,y,z) with dimensions (sx, sy, sx)
     * with rotations of (rx, ry, rz)
     * and default colors:
     * [magenta bottom, red front, green right, blue back, yellow left, cyan top]
     */
    RectangularPrism(double x, double y, double z,
            double sx, double sy, double sz,
            double rx, double ry, double rz);

    /*
     * Draw a rectangular prism at (x,y,z) with dimensions (sx, sy, sz)
     * with rotations of (rx, ry, rz) degrees and specified colors:
     * [bottom, front, right, back, left, top], each being an rgb number in (0,0,0)-(1,1,1)
     */
    RectangularPrism(double x, double y, double z,
            double sx, double sy, double sz,
            double rx, double ry, double rz,
            double face_colors[18]);

    // draw the specified rectangular prism
    void draw();
};

#endif //HW3NEW_RECTANGULARPRISM_H