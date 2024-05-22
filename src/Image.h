#pragma once
#include <cstdint>
#include <vector>
#include "RGB.h"
#include <string>

class Image {
private:
    int width_;
    int height_;
    std::vector<std::vector<RGB>> pixels_;

public:
    Image();
    Image(int width, int height);
    explicit Image(const char* path);
    ~Image();

    RGB GetRgb(int x, int y) const;
    void ChangePixel(RGB rgb, int x, int y);

    int Width() const;
    int Height() const;
    void Resize(int width, int height);

    friend void SaveFile(const char* path, Image& image);
    void Read(const char* path);
};