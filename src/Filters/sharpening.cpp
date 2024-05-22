#include "sharpening.h"
#include <cmath>

RGB PixelValue(int x, int y, const Image &image) {
    RGB center_rgb = image.GetRgb(x, y);
    RGB top_rgb = (y > 0) ? image.GetRgb(x, y - 1) : center_rgb;
    RGB bottom_rgb = (y < image.Height() - 1) ? image.GetRgb(x, y + 1) : center_rgb;
    RGB left_rgb = (x > 0) ? image.GetRgb(x - 1, y) : center_rgb;
    RGB right_rgb = (x < image.Width() - 1) ? image.GetRgb(x + 1, y) : center_rgb;

    float pixel_r = std::min(
        1.0f, std::max(0.0f, (5.0f * center_rgb.r) - left_rgb.r - right_rgb.r - top_rgb.r - bottom_rgb.r));  // NOLINT
    float pixel_g = std::min(
        1.0f, std::max(0.0f, (5.0f * center_rgb.g) - left_rgb.g - right_rgb.g - top_rgb.g - bottom_rgb.g));  // NOLINT
    float pixel_b = std::min(
        1.0f, std::max(0.0f, (5.0f * center_rgb.b) - left_rgb.b - right_rgb.b - top_rgb.b - bottom_rgb.b));  // NOLINT
    return RGB(pixel_r, pixel_g, pixel_b);
}
Image DoSharp(Image &image) {
    Image image1(image.Width(), image.Height());
    int width = image1.Width();
    int height = image1.Height();
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            RGB pixel = PixelValue(x, y, image);
            image1.ChangePixel(pixel, x, y);
        }
    }
    return image1;
}

Image Sharpening::Do(Image &image) {
    return DoSharp(image);
}
