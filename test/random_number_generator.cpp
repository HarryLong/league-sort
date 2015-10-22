#include "random_number_generator.h"

RandomNumberGenerator::RandomNumberGenerator(int from, int to) :
    generator_(std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count())),
    distribution_(std::uniform_int_distribution<int>(from,to))
{
}

RandomNumberGenerator::~RandomNumberGenerator()
{

}

int RandomNumberGenerator::generate()
{
    return distribution_.operator()(generator_);
}
