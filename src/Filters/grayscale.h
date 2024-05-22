#pragma once
#include "../Filters.h"

class Grayscale : public Filters {
public:
    Image Do(Image& image) override;
    ~Grayscale() override = default;
};