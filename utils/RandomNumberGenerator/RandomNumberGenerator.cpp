#include "RandomNumberGenerator.h"
#include <random>

unsigned int RandomNumberGenerator::generate(unsigned int lower_num, unsigned int upper_num) {
    if (lower_num > upper_num) {
        unsigned int tmp = upper_num;
        upper_num = lower_num;
        lower_num = tmp;
    }

    static std::random_device rd;
    std::uniform_int_distribution<int> uni(static_cast<int>(lower_num),
                                           static_cast<int>(upper_num)); 

    return uni(rd);
}