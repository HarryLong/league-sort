#include "match.h"
#include <iostream>
#include "file_utils.h"

Match::Match(std::string scoresheet_line)
{
    std::vector<std::string> raw_sides(StringUtils::splitAtFirstOccurence(scoresheet_line, ','));
    syntax_valid_ = (raw_sides.size() == 2);

    if(syntax_valid_)
    {
        for(int i(0); i < 2 && syntax_valid_; i++)
        {
            std::vector<std::string> name_score_split(StringUtils::splitAtLastOccurence(raw_sides.at(i), ' '));
            syntax_valid_ = (name_score_split.size() == 2);
            if(syntax_valid_)
            {
                sides_[i].name = StringUtils::trim(name_score_split.at(0));
                sides_[i].score = std::stoi(name_score_split.at(1));
            }
        }
    }
}

Match::~Match()
{

}

bool Match::syntaxValid() const
{
    return syntax_valid_;
}

Match::Side Match::getSideOne() const
{
    return sides_[0];
}

Match::Side Match::getSideTwo() const
{
    return sides_[1];
}
