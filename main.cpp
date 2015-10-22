#include <iostream>
#include <cstdio>
#include <string>
#include "file_utils.h"
#include "result_sheet.h"
#include "championship_simulator.h"
#include "point_scheme.h"

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
        if(result_sheet.valid())
        {
            ChampionshipSimulator<BasePointScheme> simulator(result_sheet);
            int previous_points(-1);
            int current_position(1);
            std::vector<Team> sorted_teams(simulator.getSortedTeams());
            for(int i(0); i < sorted_teams.size(); i++)
            {
                Team & t (sorted_teams.at(i));

                if(t.getPoints() != previous_points)
                    current_position = i+1;

                std::cout << current_position << ". " << t.getName() << ", " << t.getPoints() << "pts" << std::endl;
                previous_points = t.getPoints();
            }
        }
        else
        {
            if(!result_sheet.fileExists())
                std::cerr << "File doesn't exist: " << filename << std::endl;
            else // IO error
                std::cerr << "Input/Output error occured whilst reading file... aborting!" << std::endl;
        }
    }

    return 0;
}
