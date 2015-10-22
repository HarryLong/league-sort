#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include <string>

std::string getRandomMatchLine(int max_name_length, int max_score);
std::string buildMatchLine(std::string t1_name, int t1_score, std::string t2_name, int t2_score);
std::string getRandomName(int max_length);
int getRandomScore(int max_score);

#endif //TEST_UTILS_H

