#include "grayscale.h"

static const float SHIFT_255_F = 255.0f;

RGB ChangeGray(const RGB& rgb) {
    unsigned char r1 = static_cast<unsigned char>(rgb.r * SHIFT_255_F);
    unsigned char g1 = static_cast<unsigned char>(rgb.g * SHIFT_255_F);
    unsigned char b1 = static_cast<unsigned char>(rgb.b * SHIFT_255_F);
    float gray = static_cast<float>(0.299 * r1 + 0.587 * g1 + 0.114 * b1);  // NOLINT
    RGB rgb1;
    rgb1.r = gray / SHIFT_255_F;
    rgb1.g = gray / SHIFT_255_F;
    rgb1.b = gray / SHIFT_255_F;
    return rgb1;
}

Image Grayscale::Do(Image& image) {
    for (int y = 0; y < image.Height(); ++y) {
        for (int x = 0; x < image.Width(); ++x) {
            image.ChangePixel(ChangeGray(image.GetRgb(x, y)), x, y);
        }
    }
    return image;
}
