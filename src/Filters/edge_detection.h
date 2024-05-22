#pragma once
#include "../Filters.h"

class Edge : public Filters {
    float threshold_ = 0.0f;

public:
    explicit Edge(float threshold) : threshold_(threshold){};
    Image Do(Image& image) override;
    Image DoEdge(const Image& image, const float threshold);
    ~Edge() override = default;
};