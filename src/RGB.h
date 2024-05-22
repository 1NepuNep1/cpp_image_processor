#pragma once

#include <cstdint>

struct RGB {
    float r = 0;
    float g = 0;
    float b = 0;

    RGB();
    RGB(float r, float g, float b);
    ~RGB();
    RGB& operator=(const RGB& rgb);
    RGB& operator+(const RGB& rgb);
    RGB& operator*(float x);
};
