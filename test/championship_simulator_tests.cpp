#include "championship_simulator_tests.h"
#include "test_utils.h"
#include "../championship_simulator.h"
#include "../point_scheme.h"

const std::string ChampionshipSimulatorTest::file_input =
"Lions 3, Snakes 3\n\
Tarantulas 1, FC Awesome 0\n\
Lions 1, FC Awesome 1\n\
Tarantulas 3, Snakes 1\n\
Lions 4, Grouches 0\n";
void ChampionshipSimulatorTest::setUp()
{
    // Nothing to do
}

void ChampionshipSimulatorTest::tearDown()
{
    // Nothing to do
}

void ChampionshipSimulatorTest::testExpectedResult()
{
    std::cout << "*** CHECKING PREPROCESSED FILE ***" << std::endl;

    // WRITE TO FILE
    std::ofstream out_stream_(ChampionshipSimulatorTest::_test_filename, std::ios_base::trunc);
    CPPUNIT_ASSERT(out_stream_.is_open());
    out_stream_ << ChampionshipSimulatorTest::file_input;
    out_stream_.close();


    ResultSheet result_sheet(ChampionshipSimulatorTest::_test_filename);

    std::cout << "Checking parsed result sheet valid...";
    CPPUNIT_ASSERT(result_sheet.valid());
    std::cout << "OK!" << std::endl;

    ChampionshipSimulator<BasePointScheme> simulator(result_sheet);
    std::vector<Team> sorted_teams(simulator.getSortedTeams());

    std::string ranked_names[]{ "Tarantulas", "Lions", "FC Awesome", "Snakes", "Grouches"};
    int ranked_points[]{6,5,1,1,0};

    for(int i(0); i < 5; i++)
        checkEqual(ranked_names[i], ranked_points[i], sorted_teams.at(i));
}

void ChampionshipSimulatorTest::checkEqual(const std::string & name, int points, const Team & team)
{
    std::cout << "Checking team " << name << " is at expected position...";
    CPPUNIT_ASSERT(team.getName() == name);
    CPPUNIT_ASSERT(team.getPoints() == points);

    std::cout << "...OK!" << std::endl;
}
