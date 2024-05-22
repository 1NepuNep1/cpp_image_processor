#include "negative_filter.h"

Image Negative::Do(Image& image) {
    for (int y = 0; y < image.Height(); ++y) {
        for (int x = 0; x < image.Width(); ++x) {
            RGB temp = image.GetRgb(x, y);
            image.ChangePixel(RGB(1 - temp.r, 1 - temp.g, 1 - temp.b), x, y);
        }
    }
    return image;
}
