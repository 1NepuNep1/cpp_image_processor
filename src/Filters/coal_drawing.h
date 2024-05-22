#pragma once
#include "../Filters.h"

Image DoCoal(const Image& image);

class Coal : public Filters {
public:
    Image Do(Image& image) override;
    ~Coal() override = default;
};