#include "crop.h"

Image Crop::Do(Image& image) {
    int new_width = std::min(width_, image.Width());
    int new_height = std::min(height_, image.Height());
    image.Resize(new_width, new_height);
    return image;
}
Crop::Crop(int width, int height) : width_(width), height_(height) {
}
