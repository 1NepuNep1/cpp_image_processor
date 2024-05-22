#pragma once
#include "../Filters.h"

class Crop : public Filters {
    int width_ = 0;
    int height_ = 0;

public:
    Crop(int width, int height);
    Image Do(Image& image) override;
    ~Crop() override = default;
};