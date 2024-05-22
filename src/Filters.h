#pragma once

#include "Image.h"

class Filters {
public:
    virtual Image Do(Image& image) = 0;
    virtual ~Filters(){};
};