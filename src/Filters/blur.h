#pragma once
#include "../Filters.h"

class Blur : public Filters {
    float sigma_ = 0.0f;

public:
    explicit Blur(float sigma) : sigma_(sigma){};
    Image Do(Image& image) override;
    Image DoBlur(const Image& image, const float sigma);
    ~Blur() override = default;
};