#ifndef MATCH_H
#define MATCH_H

#include <regex>

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

    int winning_team();

    bool valid() const;

private:
    bool syntax_valid_;
    Side sides_[2];
};

#endif //MATCH_H
