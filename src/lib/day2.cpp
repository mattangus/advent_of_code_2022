#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

#include "utils.hpp"
#include "advent.hpp"

constexpr uint16_t elfRock = 'A';
constexpr uint16_t elfPaper = 'B';
constexpr uint16_t elfScissors = 'C';

constexpr uint16_t myRock = 'X';
constexpr uint16_t myPaper = 'Y';
constexpr uint16_t myScissors = 'Z';

constexpr uint16_t shouldLose = 'X';
constexpr uint16_t shouldDraw = 'Y';
constexpr uint16_t shouldWin = 'Z';

constexpr uint16_t encode(const uint16_t elf, const uint16_t me)
{
    return (elf << 8) | me;
}

uint16_t encode(const std::pair<uint8_t, uint8_t> &match)
{
    return encode((uint16_t)match.first, (uint16_t)match.second);
}

std::unordered_map<uint16_t, uint32_t> matchPoints = {
    // win
    {encode(elfRock, myPaper), 6},
    {encode(elfPaper, myScissors), 6},
    {encode(elfScissors, myRock), 6},
    // loss
    {encode(elfRock, myScissors), 0},
    {encode(elfPaper, myRock), 0},
    {encode(elfScissors, myPaper), 0},
    // draw
    {encode(elfRock, myRock), 3},
    {encode(elfPaper, myPaper), 3},
    {encode(elfScissors, myScissors), 3},
};

std::unordered_map<uint16_t, uint8_t> actions = {
    {encode(elfRock, shouldLose), myScissors},
    {encode(elfRock, shouldDraw), myRock},
    {encode(elfRock, shouldWin), myPaper},

    {encode(elfPaper, shouldLose), myRock},
    {encode(elfPaper, shouldDraw), myPaper},
    {encode(elfPaper, shouldWin), myScissors},

    {encode(elfScissors, shouldLose), myPaper},
    {encode(elfScissors, shouldDraw), myScissors},
    {encode(elfScissors, shouldWin), myRock},
};

std::unordered_map<uint8_t, uint32_t> playPoints = {
    {(uint8_t)myRock, 1},
    {(uint8_t)myPaper, 2},
    {(uint8_t)myScissors, 3}};

std::unordered_map<uint8_t, uint32_t> realMatchPoints = {
    {(uint8_t)shouldLose, 0},
    {(uint8_t)shouldDraw, 3},
    {(uint8_t)shouldWin, 6}};



std::vector<uint16_t> encodeMatches(const std::vector<std::pair<uint8_t, uint8_t>> &matches)
{
    std::vector<uint16_t> encoded;
    std::transform(matches.begin(), matches.end(), std::back_inserter(encoded), [](const auto &pair)
                   { return encode(pair); });
    return encoded;
}

void solveDay2()
{
    const auto matches = getDay2Data();
    const auto encoded = encodeMatches(matches);
    const auto throwPoints = std::accumulate(matches.begin(), matches.end(), 0, [](uint32_t cur, const auto &pair)
                                             { return cur + playPoints.at(pair.second); });
    const auto wonPoints = std::accumulate(encoded.begin(), encoded.end(), 0, [](uint32_t cur, const auto &match)
                                           { return cur + matchPoints.at(match); });

    const auto realThrowPoints = std::accumulate(encoded.begin(), encoded.end(), 0, [](uint32_t cur, const auto &match)
                                               {const auto toPlay = actions.at(match);
                                                return cur + playPoints.at(toPlay); });
    const auto realWinPoints = std::accumulate(matches.begin(), matches.end(), 0, [](uint32_t cur, const auto &pair)
                                             { return cur + realMatchPoints.at(pair.second); });

    const auto fakePoints = throwPoints + wonPoints;
    const auto realPoints = realThrowPoints + realWinPoints;

    std::cout << "day 2 part 1 solution" << std::endl;
    std::cout << fakePoints << std::endl;
    std::cout << "day 2 part 2 solution" << std::endl;
    std::cout << realPoints << std::endl;
}