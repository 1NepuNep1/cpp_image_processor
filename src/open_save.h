#pragma once
#include <string>
#include "Image.h"

static const int FILE_HEADER_SIZE = 14;
static const int INFO_HEADER_SIZE = 40;
static const uint8_t SHIFT_8 = 8;
static const uint8_t SHIFT_16 = 16;
static const uint8_t SHIFT_24 = 24;
static const float SHIFT_255_F = 255.0f;


void CreateFileHeader(unsigned char* file_header, const int file_size);
void CreateInfoHeader(unsigned char* info_header, int width, int height);
