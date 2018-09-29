//
// Created by marcus on 9/25/18.
//

#include "House.h"
#include "CSCIx229.h"
#include "RectangularPrism.h"

House::House(double x, double y, double z,
        double width, double length, double height):
        x(x), y(y), z(z), width(width), length(length), height(height) {}

void House::draw() {
    glPushMatrix();
    auto p = RectangularPrism(x, y, z, width, length, height);
    p.draw();
    glPopMatrix();
}