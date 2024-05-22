#pragma once

#include "Parser.h"
#include "RealizeFilters.h"
#include "Image.h"

#include <map>

using RealizeArg = Filters* (*)(const FilterDescriptor&);

class Processor {
    std::map<std::string, RealizeArg> filters_map_;
    std::vector<Filters*> filters_;

public:
    Processor();

    void Start(int argc, char** argv);
    void Append(Filters* filter);
    void Use(Image& image);

    ~Processor();
};