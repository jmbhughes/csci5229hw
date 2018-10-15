/*
 * Draws a ferris wheel
 */
#ifndef HW3NEW_FERRISWHEEL_H
#define HW3NEW_FERRISWHEEL_H


class FerrisWheel {
private:
    double cx, cy, cz, scale;
    void draw_support();
    void draw_chairs(double phase);
public:
    FerrisWheel(double cx, double cy, double cz, double scale);
    void draw(double phase);
};

class FerrisWheelChair {
private:
    double cx, cy, cz, width, rx, ry, rz, scale;
    void draw_back();
    void draw_seat();
    void draw_supports();
    void draw_foot_area();
public:
    FerrisWheelChair(double cx, double cy, double cz,
            double rx, double ry, double rz, double scale);
    void draw();
};
#endif //HW3NEW_FERRISWHEEL_H
