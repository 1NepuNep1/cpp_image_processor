#include "Processor.h"

Processor::Processor() {
    filters_map_["-neg"] = &FilterRealize::MakeNeg;
    filters_map_["-crop"] = &FilterRealize::MakeCrop;
    filters_map_["-gs"] = &FilterRealize::MakeGs;
    filters_map_["-sharp"] = &FilterRealize::MakeSharp;
    filters_map_["-edge"] = &FilterRealize::MakeEdge;
    filters_map_["-coal"] = &FilterRealize::MakeCoal;
    filters_map_["-blur"] = &FilterRealize::MakeBlur;
    filters_map_["-fisheye"] = &FilterRealize::MakeFishEye;
}

void Processor::Start(int argc, char **argv) {
    Parser parser;
    parser.SplitArgs(argc, argv);
    if (!parser.IsWithPath()) {
        return;
    }
    Image copy(parser.GetPathIn());
    std::vector<FilterDescriptor> applied_filters;
    applied_filters = parser.GetPar();
    for (const FilterDescriptor &filter_descriptor : applied_filters) {
        if (filters_map_.contains(filter_descriptor.filter)) {
            Append(filters_map_[filter_descriptor.filter](filter_descriptor));
        } else {
            throw std::runtime_error("Filter {" + filter_descriptor.filter + "} is not in the list of filters");
        }
    }
    Use(copy);
    SaveFile(parser.GetPathOut(), copy);
}

void Processor::Append(Filters *filter) {
    filters_.push_back(filter);
}

void Processor::Use(Image &image) {
    for (auto i : filters_) {
        image = i->Do(image);
    }
}

Processor::~Processor() {
    for (auto i : filters_) {
        delete i;
    }
}
