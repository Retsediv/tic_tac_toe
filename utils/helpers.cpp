#include "helpers.h"
#include <random>

int get_random_number(int min, int max) {
    static std::random_device rd;
    static std::mt19937 rng(rd());
    std::uniform_int_distribution<std::mt19937::result_type> res(min, max);

    return res(rng);
}