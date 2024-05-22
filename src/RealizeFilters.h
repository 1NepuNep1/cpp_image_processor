#pragma once

#include "iostream"

#include "Filters.h"
#include "Parser.h"

#include "Filters/blur.h"
#include "Filters/coal_drawing.h"
#include "Filters/crop.h"
#include "Filters/edge_detection.h"
#include "Filters/Fisheye.h"
#include "Filters/grayscale.h"
#include "Filters/negative_filter.h"
#include "Filters/sharpening.h"

class FilterRealize {
public:
    static Filters* MakeCrop(const FilterDescriptor& filter_descriptor);
    static Filters* MakeGs(const FilterDescriptor& filter_descriptor);
    static Filters* MakeSharp(const FilterDescriptor& filter_descriptor);
    static Filters* MakeNeg(const FilterDescriptor& filter_descriptor);
    static Filters* MakeEdge(const FilterDescriptor& filter_descriptor);
    static Filters* MakeBlur(const FilterDescriptor& filter_descriptor);
    static Filters* MakeCoal(const FilterDescriptor& filter_descriptor);
    static Filters* MakeFishEye(const FilterDescriptor& filter_descriptor);
};