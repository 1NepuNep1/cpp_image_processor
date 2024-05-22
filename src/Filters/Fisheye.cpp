#include "Fisheye.h"
#include <cmath>

Image DoFishEye(const Image& image) {
    Image image1 = image;
    const int lens_center_x = 59 * image1.Width() / 100;
    const int lens_center_y = 50 * image1.Height() / 100;
    const double lens_radius = std::min(image1.Width(), image1.Height()) / 1.5;
    const double lens_factor = 1.5;

    for (auto x = 0; x < image.Width(); ++x) {
        for (auto y = 0; y < image.Height(); ++y) {
            const int dx = x - lens_center_x;
            const int dy = y - lens_center_y;
            const double dist = std::sqrt(dx * dx + dy * dy);
            if (dist <= lens_radius) {
                const double radius = dist / lens_radius;
                const double angle = std::atan2(dy, dx);
                const double distortion = std::pow(radius, lens_factor) * dist;

                int sx = static_cast<int>(distortion * std::cos(angle) + lens_center_x);
                int sy = static_cast<int>(distortion * std::sin(angle) + lens_center_y);
                if (sx >= 0 && sy >= 0 && sx < image1.Width() && sy < image1.Height()) {
                    RGB temp;
                    temp = image.GetRgb(sx, sy);
                    image1.ChangePixel(temp, x, y);
                }
            }
        }
    }
    return image1;
}

Image FishEye::Do(Image& image) {
    return DoFishEye(image);
}
