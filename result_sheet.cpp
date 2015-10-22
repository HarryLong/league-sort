#include "result_sheet.h"
#include <fstream>
#include "utils.h"
#include <iostream>

ResultSheet::ResultSheet(std::string filename) : file_exists_(true), io_error_(false)
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
                if(match.valid())
                    matches_.push_back(Match(line));
                else
                    std::cerr << "Skipping erroneous line: " << line << std::endl;
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
    return fileExists() && !ioError();
}

bool ResultSheet::fileExists() const
{
    return file_exists_;
}

bool ResultSheet::ioError() const
{
    return io_error_;
}
