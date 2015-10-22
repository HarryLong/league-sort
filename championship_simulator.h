/**
  Author: @Harry Long

    Templated class which simulates the championship based on a given ResultSheet and PointScheme
  */
#ifndef CHAMPIONSHIP_SIMULATOR_H
#define CHAMPIONSHIP_SIMULATOR_H

#include "result_sheet.h"
#include "team.h"
#include <map>

template<class PointScheme> class ChampionshipSimulator : public PointScheme{
public:
    /**
     * @brief ChampionshipSimulator
     * @param results: The parsed resultsheet
     */
    ChampionshipSimulator(const ResultSheet & results);
    ~ChampionshipSimulator();
    /**
     * @brief getSortedTeams
     * @return Sorted teams from highest to lowest ranking in the championship
     */
    std::vector<Team> getSortedTeams();

private:
    void init_team(const std::string & name);
    bool team_initialised(const std::string & name);
    std::vector<Team> results_;
    std::map<std::string, Team> teams_;
};

#endif
