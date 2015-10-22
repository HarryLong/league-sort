#include "match_test.h"
#include "../match.h"
#include "test_utils.h"

void MatchTests::setUp()
{
    // Nothing to do
}

void MatchTests::tearDown()
{
    // Nothing to do
}

void MatchTests::test1()
{
    std::cout << "*** RANDOM MATCH TESTS ***" << std::endl;

    for(int i(0); i < 100; i++)
    {
        int scores[2] { getRandomScore(100), getRandomScore(100) };
        std::string names[2] { getRandomName(25), getRandomName(25)};

        std::string match_line( buildMatchLine(names[0], scores[0], names[1], scores[1]) );

        std::cout << "Testing: " << match_line;

        Match match(match_line);
        CPPUNIT_ASSERT(match.getSideOne().name == names[0]);
        CPPUNIT_ASSERT(match.getSideTwo().name == names[1]);
        CPPUNIT_ASSERT(match.getSideOne().score == scores[0]);
        CPPUNIT_ASSERT(match.getSideTwo().score == scores[1]);

        std::cout << "....... OK!" << std::endl;;
    }
}
