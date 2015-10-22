#include <iostream>
#include <cstdio>
#include <string>
#include "file_utils.h"
#include "result_sheet.h"

int main(int argc, char * argv[])
{
    if(argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <filename>";
        exit(1);
    }
    else
    {
        std::string filename(argv[1]);
        ResultSheet result_sheet(filename);

    }

    return 0;
}
