#ifndef RANDOM_NUMBER_GENERATOR_H
#define RANDOM_NUMBER_GENERATOR_H

#include <chrono>
#include <random>

class RandomNumberGenerator {
public:
    RandomNumberGenerator(int from, int to);
    ~RandomNumberGenerator();

    int generate();
private:
    std::default_random_engine generator_;
    std::uniform_int_distribution<int> distribution_;
};

#endif //RANDOM_NUMBER_GENERATOR_H
