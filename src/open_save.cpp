#include "open_save.h"
#include "Image.h"
#include <fstream>
#include <iostream>

void CreateFileHeader(unsigned char *file_header, const int file_size) {
    uint8_t idx = 0;
    file_header[idx++] = 'B';
    file_header[idx++] = 'M';
    file_header[idx++] = file_size;
    file_header[idx++] = file_size >> SHIFT_8;
    file_header[idx++] = file_size >> SHIFT_16;
    file_header[idx++] = file_size >> SHIFT_24;
    for (int i = idx; i < FILE_HEADER_SIZE; ++i) {
        if (i != 10) {  // NOLINT
            file_header[i] = 0;
        } else {
            file_header[i] = FILE_HEADER_SIZE + INFO_HEADER_SIZE;
        }
    }
}

void CreateInfoHeader(unsigned char *info_header, int width, int height) {
    uint8_t idx = 0;
    info_header[idx++] = INFO_HEADER_SIZE;
    info_header[idx++] = 0;
    info_header[idx++] = 0;
    info_header[idx++] = 0;

    info_header[idx++] = width;
    info_header[idx++] = width >> SHIFT_8;
    info_header[idx++] = width >> SHIFT_16;
    info_header[idx++] = width >> SHIFT_24;

    info_header[idx++] = height;
    info_header[idx++] = height >> SHIFT_8;
    info_header[idx++] = height >> SHIFT_16;
    info_header[idx++] = height >> SHIFT_24;

    info_header[idx++] = 1;
    info_header[idx++] = 0;

    info_header[idx++] = SHIFT_24;
    for (int i = idx; i < INFO_HEADER_SIZE; ++i) {
        info_header[i] = 0;
    }
}

void SaveFile(const char *path, Image &image) {
    std::ofstream f;
    f.open(path, std::ios::out | std::ios::binary);
    if (!f.is_open()) {
        throw std::runtime_error("File can't be saved");
    }
    unsigned char padding[3] = {0, 0, 0};
    const int count_paddings = ((4 - (image.width_ * 3) % 4) % 4);
    const int file_size =
        FILE_HEADER_SIZE + INFO_HEADER_SIZE + image.width_ * image.height_ * 3 + count_paddings * image.height_;
    unsigned char file_header[FILE_HEADER_SIZE];
    unsigned char info_header[INFO_HEADER_SIZE];
    CreateFileHeader(file_header, file_size);
    CreateInfoHeader(info_header, image.width_, image.height_);
    f.write(reinterpret_cast<char *>(file_header), FILE_HEADER_SIZE);
    f.write(reinterpret_cast<char *>(info_header), INFO_HEADER_SIZE);
    for (int y = 0; y < image.height_; ++y) {
        for (int x = 0; x < image.width_; ++x) {
            unsigned char pixel_r = static_cast<unsigned char>(image.GetRgb(x, y).r * SHIFT_255_F);
            unsigned char pixel_g = static_cast<unsigned char>(image.GetRgb(x, y).g * SHIFT_255_F);
            unsigned char pixel_b = static_cast<unsigned char>(image.GetRgb(x, y).b * SHIFT_255_F);

            unsigned char pixel_color[] = {pixel_b, pixel_g, pixel_r};
            f.write(reinterpret_cast<char *>(pixel_color), 3);
        }
        f.write(reinterpret_cast<char *>(padding), count_paddings);
    }
    f.close();
}

void Image::Read(const char *path) {
    std::ifstream f;
    f.open(path, std::ios::in | std::ios::binary);
    if (!f.is_open()) {
        throw std::runtime_error("File can't be read");
    }
    unsigned char file_header[FILE_HEADER_SIZE];
    f.read(reinterpret_cast<char *>(file_header), FILE_HEADER_SIZE);
    if (file_header[0] != 'B' || file_header[1] != 'M') {
        throw std::runtime_error("Not a bmp file");
    }
    unsigned char info_header[INFO_HEADER_SIZE];
    f.read(reinterpret_cast<char *>(info_header), INFO_HEADER_SIZE);
    width_ = (info_header[4]) + (info_header[5] << SHIFT_8) + (info_header[6] << SHIFT_16) +    // NOLINT
             (info_header[7] << SHIFT_24);                                                      // NOLINT
    height_ = (info_header[8]) + (info_header[9] << SHIFT_8) + (info_header[10] << SHIFT_16) +  // NOLINT
              (info_header[11] << SHIFT_24);                                                    // NOLINT
    pixels_.resize(height_);
    for (int i = 0; i < Height(); ++i) {
        pixels_[i].resize(width_);
    }
    const int count_paddings = ((4 - (width_ * 3) % 4) % 4);
    for (int y = 0; y < height_; ++y) {
        for (int x = 0; x < width_; ++x) {
            unsigned char pixel_colors[3];
            f.read(reinterpret_cast<char *>(pixel_colors), 3);
            pixels_[y][x].r = static_cast<float>(pixel_colors[2]) / SHIFT_255_F;
            pixels_[y][x].g = static_cast<float>(pixel_colors[1]) / SHIFT_255_F;
            pixels_[y][x].b = static_cast<float>(pixel_colors[0]) / SHIFT_255_F;
        }
        f.ignore(count_paddings);
    }
    f.close();
}
