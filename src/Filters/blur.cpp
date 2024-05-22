#include "blur.h"
#include <cmath>

Image Blur::DoBlur(const Image& image, const float sigma) {
    Image image1(image.Width(), image.Height());
    Image image2(image.Width(), image.Height());
    int sigma_3 = static_cast<int>(3 * sigma);
    std::vector<float> gauss_matrix;
    gauss_matrix.reserve(std::ceil(6 * sigma + 1));                         // NOLINT
    for (int i = 0; i < static_cast<int>(std::ceil(6 * sigma + 1)); ++i) {  // NOLINT
        gauss_matrix.push_back(expf(-powf(static_cast<float>(i - sigma_3), 2) / (2 * powf(sigma, 2))));
    }
    float sum = 0;
    for (float x : gauss_matrix) {
        sum += x;
    }
    for (float& x : gauss_matrix) {
        x /= sum;
    }
    for (int y = 0; y < image.Height(); ++y) {
        for (int x = 0; x < image.Width(); ++x) {
            float r_sum = 0.0f;
            float g_sum = 0.0f;
            float b_sum = 0.0f;
            for (int i = -sigma_3; i <= sigma_3; ++i) {
                int yi = std::max(0, std::min(y + i, image.Height() - 1));
                r_sum += gauss_matrix[i + sigma_3] * image.GetRgb(x, yi).r;
                g_sum += gauss_matrix[i + sigma_3] * image.GetRgb(x, yi).g;
                b_sum += gauss_matrix[i + sigma_3] * image.GetRgb(x, yi).b;
            }
            RGB pixel(r_sum, g_sum, b_sum);
            image1.ChangePixel(pixel, x, y);
        }
    }
    for (int x = 0; x < image.Width(); ++x) {
        for (int y = 0; y < image.Height(); ++y) {
            float r_sum = 0.0f;
            float g_sum = 0.0f;
            float b_sum = 0.0f;
            for (int i = -sigma_3; i <= sigma_3; ++i) {
                int xi = std::max(0, std::min(x + i, image.Width() - 1));
                r_sum += gauss_matrix[i + sigma_3] * image1.GetRgb(xi, y).r;
                g_sum += gauss_matrix[i + sigma_3] * image1.GetRgb(xi, y).g;
                b_sum += gauss_matrix[i + sigma_3] * image1.GetRgb(xi, y).b;
            }
            RGB pixel(r_sum, g_sum, b_sum);
            image2.ChangePixel(pixel, x, y);
        }
    }
    return image2;
}

Image Blur::Do(Image& image) {
    return DoBlur(image, sigma_);
}
