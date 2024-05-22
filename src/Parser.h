#pragma once

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>


struct FilterDescriptor {
    std::string filter;
    std::vector<std::string> params;
};

class Parser {
    bool with_path_ = false;
    char* path_in_;
    char* path_out_;
    std::vector<FilterDescriptor> filters_;

    void Help();
public:
    void SplitArgs(int argc, char** argv);
    std::vector<FilterDescriptor> GetPar();
    char* GetPathIn();
    char* GetPathOut();
    bool IsWithPath() const;
};