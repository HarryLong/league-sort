#include "test_utils.h"
#include "random_number_generator.h"

std::string getRandomMatchLine(int max_name_length, int max_score)
{
    int scores[2] { getRandomScore(max_score), getRandomScore(max_score) };
    std::string names[2] { getRandomName(max_name_length), getRandomName(max_name_length)};

    return buildMatchLine(names[0], scores[0], names[1], scores[1]);
}

std::string buildMatchLine(std::string t1_name, int t1_score, std::string t2_name, int t2_score)
{
    std::string concatenated;
    concatenated.append(t1_name).append(" ").append(std::to_string(t1_score)).append(", ").append(t2_name).append(" ").append(std::to_string(t2_score));
    return concatenated;
}

std::string getRandomName(int max_length)
{
    std::string s;
    int s_length(0);
    {
        RandomNumberGenerator random_number_generator(1, max_length);
        s_length = random_number_generator.generate();
    }

    RandomNumberGenerator char_generator('A', 'z');
    RandomNumberGenerator dice_roller(1, 6);

    for(int i(0); i < s_length; i++)
    {
        char random_char(char_generator.generate());
        s += random_char;

        if(i < s_length-1 && dice_roller.generate() == 1) // Add a space
            s += " ";
    }

    return s;
}

int getRandomScore(int max_score)
{
    RandomNumberGenerator score_generator(1, max_score);
    return score_generator.generate();
}
