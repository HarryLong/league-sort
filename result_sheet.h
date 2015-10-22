#ifndef RESULT_SHEET_H
#define RESULT_SHEET_H

#include <string>
#include <vector>
#include "match.h"

class ResultSheet
{
public:
    ResultSheet(std::string filename);
    ~ResultSheet();

    std::vector<Match> getMatches() const;

    bool valid() const;
    bool fileExists() const;
    bool validSyntax() const;
    bool ioError() const;

private:
    bool syntax_valid_;
    bool io_error_;
    bool file_exists_;

    std::vector<Match> matches_;
};

#endif //RESULT_SHEET_H
