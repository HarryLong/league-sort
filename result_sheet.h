/**
  Author: @Harry Long

  Class to parse a result sheet file into individual matches
  */
#ifndef RESULT_SHEET_H
#define RESULT_SHEET_H

#include <string>
#include <vector>
#include "match.h"

class ResultSheet
{
public:
    /**
     * @brief ResultSheet
     * @param filename: Path to the file which contains necessary data
     */
    ResultSheet(std::string filename);
    ~ResultSheet();

    /**
     * @brief getMatches
     * @return Returns all parsed matches
     */
    std::vector<Match> getMatches() const;

    /**
     * @brief valid To check wheter the parsing was succesful
     * @return
     */
    bool valid() const;
    bool fileExists() const;
    bool ioError() const;

private:
    bool io_error_;
    bool file_exists_;

    std::vector<Match> matches_;
};

#endif //RESULT_SHEET_H
