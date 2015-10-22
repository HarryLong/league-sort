#ifndef CHAMPIONSHIP_SIMULATOR_H
#define CHAMPIONSHIP_SIMULATOR_H

#include "result_sheet.h"
#include "team.h"
#include <map>

template<class PointScheme> class ChampionshipSimulator : public PointScheme{
public:
    ChampionshipSimulator(const ResultSheet & results);
    ~ChampionshipSimulator();
    std::vector<Team> getSortedTeams();

private:
    void init_team(const std::string & name);
    bool team_initialised(const std::string & name);
    std::vector<Team> results_;
    std::map<std::string, Team> teams_;
};

#endif
