#ifndef OOP_GAME_UTIL_RANDOM_NUMBER_GENERATOR_HEADLINE
#define OOP_GAME_UTIL_RANDOM_NUMBER_GENERATOR_HEADLINE
#include <random>

class RandomNumberGenerator {
public:
    RandomNumberGenerator() = default;
    ~RandomNumberGenerator() = default;

    unsigned int generate(unsigned int lower_num, unsigned int upper_num);
    bool simulate_chance(unsigned int chance_percent);
};

#endif