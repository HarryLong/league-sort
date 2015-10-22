#include "result_sheet.h"
#include <fstream>
#include "file_utils.h"
#include <iostream>

ResultSheet::ResultSheet(std::string filename) : file_exists_(true), io_error_(false), syntax_valid_(true)
{
    // First perform an integrity check
    if(FileUtils::exists(filename))
    {
        file_exists_ = true;
        std::ifstream in(filename, std::ios::in );
        if(in.is_open())
        {
            std::string line;
            while(std::getline(in, line))
            {
                Match match(line);
                std::cout << match.getSideOne().name << " VS " << match.getSideTwo().name << " [ " << match.getSideOne().score << " - " << match.getSideTwo().score << "]" << std::endl;

                matches_.push_back(Match(line));
            }
            in.close();
        }
        else
            io_error_ = true;
    }
    else
        file_exists_ = false;
}

ResultSheet::~ResultSheet()
{

}

std::vector<Match> ResultSheet::getMatches() const
{
    return matches_;
}

bool ResultSheet::valid() const
{
    return fileExists() && validSyntax() && !ioError();
}

bool ResultSheet::fileExists() const
{
    return file_exists_;
}

bool ResultSheet::validSyntax() const
{
    return syntax_valid_;
}

bool ResultSheet::ioError() const
{
    return io_error_;
}
