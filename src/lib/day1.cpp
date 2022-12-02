#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>
#include <algorithm>

#include "utils.hpp"
#include "advent.hpp"


void solveDay1()
{
    const auto elfFood = getDay1Data();
    std::vector<uint32_t> totalFood;
    std::transform(elfFood.begin(), elfFood.end(), std::back_inserter(totalFood), [](const std::vector<uint32_t> &food)
                   { return std::accumulate(food.begin(), food.end(), 0); });
    const auto maxFood = std::accumulate(totalFood.begin(), totalFood.end(), totalFood.front(), [](const auto &a, const auto &b)
                                         { return std::max<uint32_t>(a, b); });

    std::cout << "day 1 solution part 1:" << std::endl;
    std::cout << maxFood << std::endl;

    auto topK = 3;
    std::partial_sort(totalFood.begin(), totalFood.begin() + topK, totalFood.end(), std::greater{});
    const auto top3Food = std::accumulate(totalFood.begin(), totalFood.begin() + topK, 0);

    std::cout << "day 1 solution part 2:" << std::endl;
    std::cout << top3Food << std::endl;
}