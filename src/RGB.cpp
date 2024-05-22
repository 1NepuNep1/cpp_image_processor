#include "RGB.h"

RGB::RGB() : r(0), g(0), b(0) {
}
RGB::RGB(float r, float g, float b) : r(r), g(g), b(b) {
}
RGB::~RGB() {
}
RGB& RGB::operator=(const RGB& rgb) {
    r = rgb.r;
    g = rgb.g;
    b = rgb.b;
    return *this;
}
RGB& RGB::operator+(const RGB& rgb) {
    r += rgb.r;
    g += rgb.g;
    b += rgb.g;
    return *this;
}
RGB& RGB::operator*(float x) {
    r *= x;
    g *= x;
    b *= x;
    return *this;
}
