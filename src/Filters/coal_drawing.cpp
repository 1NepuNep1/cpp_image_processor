#include "coal_drawing.h"
#include "cmath"

Image DoCoal(const Image& image) {
    Image image1(image.Width(), image.Height());
    int width = image1.Width();
    int height = image1.Height();
    Image coeffs(width, height);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            float color = (image.GetRgb(x, y).r + image.GetRgb(x, y).g + image.GetRgb(x, y).b) / 3.f;  // NOLINT
            coeffs.ChangePixel({color, color, color}, x, y);
        }
    }
    std::vector<std::vector<float>> matrix_1 = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    std::vector<std::vector<float>> matrix_2 = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    for (int y = 1; y < height - 1; ++y) {
        for (int x = 1; x < width - 1; ++x) {
            float matr_x = 0;
            float matr_y = 0;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    int new_x = x + i - 1;
                    int new_y = y + j - 1;
                    matr_x += coeffs.GetRgb(new_x, new_y).g * matrix_1[i][j];
                    matr_y += coeffs.GetRgb(new_x, new_y).g * matrix_2[i][j];
                }
            }
            float color_r = sqrtf(matr_x * matr_x + matr_y * matr_y);
            image1.ChangePixel({color_r, color_r, color_r}, x, y);
        }
    }
    return image1;
}

Image Coal::Do(Image& image) {
    return DoCoal(image);
}
