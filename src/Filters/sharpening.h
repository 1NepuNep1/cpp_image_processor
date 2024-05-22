#pragma once
#include "../Filters.h"

Image DoSharp(Image& image);

class Sharpening : public Filters {
public:
    Image Do(Image& image) override;
    ~Sharpening() override = default;
};