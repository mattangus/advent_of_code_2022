#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>

#include "advent.hpp"

const std::unordered_map<std::string, std::function<void()>> solvers = {
    {"day1", solveDay1},
    {"day2", solveDay2}
};

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        std::cout << "usage: " << argv[0] << " day<#>|all" << std::endl;
        return 1;
    }
    auto cmd = std::string(argv[1]);
    std::cout << "command: " << cmd << std::endl;
    if (cmd == "all")
        for (const auto& dayFn : solvers)
            dayFn.second();
    else if (solvers.count(cmd) == 0) {
        std::cout << cmd << " is not implemented yet" << std::endl;
    }
    else {
        solvers.at(cmd)();
    }
    return 0;
}
