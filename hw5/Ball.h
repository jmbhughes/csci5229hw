/*
 * Draw a ball (the boundary of a sphere)
 */

#ifndef HW5_BALL_H
#define HW5_BALL_H

class Ball {
private:
    double cx, cy, cz, r;

    // draw vertex in polar coordinates with normal
    static void vertex(double th, double ph);
public:
    // create a ball with center at (cx, cy, cz) and radius r
    Ball(double cx, double cy, double cz, double r);

    // draw the ball
    void draw(int emission, float shiny);
};
#endif //HW5_BALL_H
