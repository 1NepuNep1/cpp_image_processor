#include "edge_detection.h"

RGB ChangeToGray(const RGB& rgb) {
    unsigned char r1 = static_cast<unsigned char>(rgb.r * 255.0f);          // NOLINT
    unsigned char g1 = static_cast<unsigned char>(rgb.g * 255.0f);          // NOLINT
    unsigned char b1 = static_cast<unsigned char>(rgb.b * 255.0f);          // NOLINT
    float gray = static_cast<float>(0.299 * r1 + 0.587 * g1 + 0.114 * b1);  // NOLINT
    RGB rgb1;
    rgb1.r = gray / 255.0f;  // NOLINT
    rgb1.g = gray / 255.0f;  // NOLINT
    rgb1.b = gray / 255.0f;  // NOLINT
    return rgb1;
}
RGB PixelsValue(int x, int y, const Image& image) {
    RGB center_rgb = image.GetRgb(x, y);
    RGB top_rgb = (y > 0) ? image.GetRgb(x, y - 1) : center_rgb;
    RGB bottom_rgb = (y < image.Height() - 1) ? image.GetRgb(x, y + 1) : center_rgb;
    RGB left_rgb = (x > 0) ? image.GetRgb(x - 1, y) : center_rgb;
    RGB right_rgb = (x < image.Width() - 1) ? image.GetRgb(x + 1, y) : center_rgb;

    float pixel_r = std::min(
        1.0f, std::max(0.0f, (4.0f * center_rgb.r) - left_rgb.r - right_rgb.r - top_rgb.r - bottom_rgb.r));  // NOLINT
    float pixel_g = std::min(
        1.0f, std::max(0.0f, (4.0f * center_rgb.g) - left_rgb.g - right_rgb.g - top_rgb.g - bottom_rgb.g));  // NOLINT
    float pixel_b = std::min(
        1.0f, std::max(0.0f, (4.0f * center_rgb.b) - left_rgb.b - right_rgb.b - top_rgb.b - bottom_rgb.b));  // NOLINT
    return RGB(pixel_r, pixel_g, pixel_b);
}

Image Edge::DoEdge(const Image& image, const float threshold) {
    int height = image.Height();
    int width = image.Width();
    Image image1(width, height);
    Image image2(width, height);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            image1.ChangePixel(ChangeToGray(image.GetRgb(x, y)), x, y);
        }
    }
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            RGB pixel = PixelsValue(x, y, image1);
            image2.ChangePixel(pixel, x, y);
            if (pixel.r > threshold || pixel.g > threshold || pixel.b > threshold) {
                image2.ChangePixel(RGB(1, 1, 1), x, y);
            } else {
                image2.ChangePixel(RGB(0, 0, 0), x, y);
            }
        }
    }
    return image2;
}

Image Edge::Do(Image& image) {
    return DoEdge(image, threshold_);
}
