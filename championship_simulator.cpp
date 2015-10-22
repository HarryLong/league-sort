#include "championship_simulator.h"
#include "point_scheme.h"

template <class PointScheme> ChampionshipSimulator<PointScheme>::ChampionshipSimulator(const ResultSheet & results)
{
    for(Match match : results.getMatches())
    {
        std::string t1_name(match.getSideOne().name);
        std::string t2_name(match.getSideTwo().name);

        if(!team_initialised(t1_name))
            init_team(t1_name);
        if(!team_initialised(t2_name))
            init_team(t2_name);

        Team & t1(teams_.find(t1_name)->second);
        Team & t2(teams_.find(t2_name)->second);

        if(match.getSideOne().score == match.getSideTwo().score) // TIE
        {
            t1.addPoints(PointScheme::tie());
            t2.addPoints(PointScheme::tie());
        }
        else if(match.getSideOne().score > match.getSideTwo().score) // Team 1 wins
        {
            t1.addPoints(PointScheme::win());
            t2.addPoints(PointScheme::lose());
        }
        else // Team 2 wins
        {
            t1.addPoints(PointScheme::lose());
            t2.addPoints(PointScheme::win());
        }
    }
}

template <class PointScheme> ChampionshipSimulator<PointScheme>::~ChampionshipSimulator()
{

}

template <class PointScheme> std::vector<Team> ChampionshipSimulator<PointScheme>::getSortedTeams()
{
    std::vector<Team> ret;
    for(auto it(teams_.begin()); it != teams_.end(); it++)
    {
        ret.push_back(it->second);
    }
    std::sort(ret.begin(), ret.end());

    return ret;
}

template <class PointScheme> bool ChampionshipSimulator<PointScheme>::team_initialised(const std::string & name)
{
    return teams_.find(name) != teams_.end();
}

template <class PointScheme> void ChampionshipSimulator<PointScheme>::init_team(const std::string & name)
{
    teams_.emplace(name, Team(name));
}

template class ChampionshipSimulator<BasePointScheme>;
