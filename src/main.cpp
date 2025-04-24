#include <iostream>
#include "../lib/cxxopts.hpp"

int main(int argc, char** argv)
{
    cxxopts::Options options("MyProgram", "Description of MyProgram");
    options.add_options()
        ("d,debug", "Enable debugging")  // Boolean flag
        ("i,integer", "Integer parameter", cxxopts::value<int>())
        ("f,file", "File name", cxxopts::value<std::string>())
        ("v,verbose", "Verbose output", cxxopts::value<bool>()->default_value("false"));
    
    auto result = options.parse(argc, argv);
    
    if (result.count("debug")) {
        std::cout << "Debugging enabled!" << std::endl;
    }
    if (result.count("integer")) {
        std::cout << "Integer parameter: " << result["integer"].as<int>() << std::endl;   
        int integerValue = result["integer"].as<int>();
    }
    if (result.count("verbose")) {
        bool verbose = result["verbose"].as<bool>();
        std::cout << "Verbose mode: " << (verbose ? "enabled" : "disabled") << std::endl;
    }
    if (result.count("file")) {
        std::string fileName = result["file"].as<std::string>();
        std::cout << "File name: " << fileName << std::endl;
    }
    return 0;
}