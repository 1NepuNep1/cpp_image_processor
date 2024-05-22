#include "Image.h"

Image::Image() : width_(0), height_(0) {
}
Image::Image(int width, int height) : width_(width), height_(height), pixels_(height_, std::vector(width, RGB{})) {
}
Image::~Image() {
}
Image::Image(const char *path) {
    Read(path);
}
RGB Image::GetRgb(int x, int y) const {
    return pixels_[y][x];
}
int Image::Width() const {
    return width_;
}
int Image::Height() const {
    return height_;
}
void Image::ChangePixel(RGB rgb, int x, int y) {
    pixels_[y][x] = rgb;
}
void Image::Resize(int width, int height) {
    pixels_ = std::vector<std::vector<RGB>>(pixels_.end() - height, pixels_.end());
    height_ = height;
    for (int i = 0; i < height; ++i) {
        pixels_[i].resize(width);
    }
    width_ = width;
}
