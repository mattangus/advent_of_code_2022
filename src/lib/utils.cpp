#include "utils.hpp"
#include <iostream>
#include <filesystem>

std::vector<std::string> getLines(const std::string &fileName)
{
    std::ifstream infile(fileName);
    std::string line;
    std::vector<std::string> lines;
    while (std::getline(infile, line))
        lines.push_back(line);
    
    return lines;
}

std::vector<std::vector<uint32_t>> getDay1Data()
{
    const std::string filePath = "data/day1.txt";
    std::vector<std::vector<uint32_t>> data;
    std::vector<uint32_t> current;
    const auto lines = getLines(filePath);

    for (const auto &line : lines)
    {
        if (line.length() == 0)
        {
            data.push_back(std::move(current));
            current = {};
        }
        else
            current.push_back(std::stoi(line));
    }

    return data;
}

std::vector<std::pair<uint8_t, uint8_t>> getDay2Data() {
    const std::string filePath = "data/day2.txt";
    std::vector<std::pair<uint8_t, uint8_t>> data;
    const auto lines = getLines(filePath);

    for (const auto &line : lines)
    {
        uint8_t l, r;
        std::stringstream ss(line);
        ss >> l >> r;
        data.push_back({l, r});
    }

    return data;
}
