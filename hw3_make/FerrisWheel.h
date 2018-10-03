/*
 * Draws a ferris wheel
 */
#ifndef HW3NEW_FERRISWHEEL_H
#define HW3NEW_FERRISWHEEL_H


class FerrisWheel {
private:
    double cx, cy, cz, height, chair_width;
    void draw_support();
public:
    FerrisWheel(double cx, double cy, double cz, double height, double chair_width);
    void draw();
};

class FerrisWheelChair {
private:
    double cx, cy, cz, width, angle_alt, angle_az, scale;
public:
    FerrisWheelChair(double cx, double cy, double cz, double width,
            double angle_alt, double angle_az, double scale);
    void draw();
};
#endif //HW3NEW_FERRISWHEEL_H
