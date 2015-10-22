#ifndef MATCH_H
#define MATCH_H

#include <regex>
#include "team.h"

class Match
{
public:
    class Side{
    public:
        std::string name;
        int score;
    };
    Match(std::string scoresheet_line);
    ~Match();

    Side getSideOne() const;
    Side getSideTwo() const;

    bool syntaxValid() const;

private:
    bool syntax_valid_;
    Side sides_[2];
};

#endif //MATCH_H
