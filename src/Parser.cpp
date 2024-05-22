#include "Parser.h"
void Parser::SplitArgs(int argc, char** argv) {
    if (argc == 1) {
        Help();
        return;
    }
    if (argc == 2) {
        throw std::runtime_error("No saving path\n");
    }
    if (argc == 3) {
        Help();
    }
    with_path_ = true;
    path_in_ = argv[1];
    path_out_ = argv[2];
    for (int i = 3; i < argc; ++i) {
        std::string str = argv[i];
        if (str[0] == '-') {
            std::vector<std::string> parametrs;
            int size = 0;
            for (int j = i + 1; j < argc; ++j) {
                std::string str2 = argv[j];
                if (str2[0] != '-') {
                    parametrs.push_back(str2);
                    ++size;
                } else {
                    break;
                }
            }
            FilterDescriptor filter_param = {str, parametrs};
            filters_.push_back(filter_param);
            i += size;
        }
    }
}
std::vector<FilterDescriptor> Parser::GetPar() {
    return filters_;
}
char* Parser::GetPathIn() {
    return path_in_;
}
char* Parser::GetPathOut() {
    return path_out_;
}

void Parser::Help() {
    std::cout << "—————————————————————————————Filters to use————————————————————————————————\n";
    std::cout << "| -neg >>> Apply Negative Filter                                          |\n";
    std::cout << "| -crop (width) (height) >>> Apply crop with preferable width and height  |\n";
    std::cout << "| -gs >>> Apply Grayscale Filter                                          |\n";
    std::cout << "| -sharp >>> Apply Sharpening Filter                                      |\n";
    std::cout << "| -edge (threshold) >>> Apply Edge Detection with preferable threshold    |\n";
    std::cout << "| -blur (sigma) >>> Apply Blur Filter with preferable sigma               |\n";
    std::cout << "| -coal >>> Apply Coal Drawing Filter (also cool with -neg)               |\n";
    std::cout << "| -fisheye >>> Apply Fisheye Filter                                       |\n";
    std::cout << "———————————————————————————————————————————————————————————————————————————";
}
bool Parser::IsWithPath() const {
    return with_path_;
}
