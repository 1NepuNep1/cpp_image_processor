#include "RealizeFilters.h"

#include <math.h>

Filters* FilterRealize::MakeCrop(const FilterDescriptor& filter_descriptor) {
    if (filter_descriptor.params.size() != 2) {
        throw std::invalid_argument("Crop has 2 arguments");
    }
    int width = 0;
    int height = 0;
    try {
        width = std::stoi(filter_descriptor.params[0]);
        height = std::stoi(filter_descriptor.params[1]);
    } catch (std::exception& e) {
        throw std::runtime_error("Error converting parameter to float: not an integer");
    }
    Filters* result = new Crop(width, height);
    return result;
}

Filters* FilterRealize::MakeNeg(const FilterDescriptor& filter_descriptor) {
    if (!filter_descriptor.params.empty()) {
        throw std::invalid_argument("Negative has 0 arguments");
    }
    Filters* result = new Negative();
    return result;
}

Filters* FilterRealize::MakeGs(const FilterDescriptor& filter_descriptor) {
    if (!filter_descriptor.params.empty()) {
        throw std::invalid_argument("Grayscale has 0 arguments");
    }
    Filters* result = new Grayscale();
    return result;
}

Filters* FilterRealize::MakeSharp(const FilterDescriptor& filter_descriptor) {
    if (!filter_descriptor.params.empty()) {
        throw std::invalid_argument("Sharpening has 0 arguments");
    }
    Filters* result = new Sharpening();
    return result;
}
Filters* FilterRealize::MakeEdge(const FilterDescriptor& filter_descriptor) {
    if (filter_descriptor.params.size() != 1) {
        throw std::invalid_argument("Edge detection has 1 argument");
    }
    float threshold = NAN;
    try {
        threshold = std::stof(filter_descriptor.params[0]);
    } catch (std::exception& e) {
        throw std::runtime_error("Error converting parameter to float: not an integer");
    }
    Filters* result = new Edge(threshold);
    return result;
}

Filters* FilterRealize::MakeBlur(const FilterDescriptor& filter_descriptor) {
    if (filter_descriptor.params.size() != 1) {
        throw std::invalid_argument("Gaussian Blur has 1 argument");
    }
    float sigma = NAN;
    try {
        sigma = std::stof(filter_descriptor.params[0]);
    } catch (std::exception& e) {
        throw std::runtime_error("Error converting parameter to float: not an integer");
    }
    Filters* result = new Blur(sigma);
    return result;
}

Filters* FilterRealize::MakeCoal(const FilterDescriptor& filter_descriptor) {
    if (!filter_descriptor.params.empty()) {
        throw std::invalid_argument("Coal has 0 arguments");
    }
    Filters* result = new Coal();
    return result;
}
Filters* FilterRealize::MakeFishEye(const FilterDescriptor& filter_descriptor) {
    if (!filter_descriptor.params.empty()) {
        throw std::invalid_argument("Fisheye has 0 arguments");
    }
    Filters* result = new FishEye();
    return result;
}
