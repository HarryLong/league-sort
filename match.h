/**
  Author: @Harry Long

  Parses a single line of a championship file into individual teams and associated scores
  */
#ifndef MATCH_H
#define MATCH_H

#include <regex>

class Match
{
public:
    /**
     * @brief The Side class: One side of the match (i.e team and score)
     */
    class Side{
    public:
        std::string name;
        int score;
    };
    /**
     * @brief Match Builds a new match instance
     * @param scoresheet_line A single match line from the championship file
     */
    Match(std::string scoresheet_line);
    ~Match();

    Side getSideOne() const;
    Side getSideTwo() const;

    /**
     * @brief valid Returns whether or not the parsing was succesful
     * @return
     */
    bool valid() const;

private:
    bool syntax_valid_;
    Side sides_[2];
};

#endif //MATCH_H
