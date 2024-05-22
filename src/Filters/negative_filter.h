#pragma once

#include "../Filters.h"

class Negative : public Filters {
public:
    Image Do(Image& image) override;
    ~Negative() override = default;
};