#pragma once
#include "../Filters.h"

Image DoFishEye(const Image& image);

class FishEye : public Filters {
public:
    Image Do(Image& image) override;
    ~FishEye() override = default;
};