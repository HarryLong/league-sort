#include "team_test.h"
#include "../team.h"
#include "random_number_generator.h"
#include "test_utils.h"

void TeamTests::setUp()
{
    // Nothing to do
}

void TeamTests::tearDown()
{
    // Nothing to do
}

void TeamTests::equalityTest()
{
    std::cout << "** EQUALITY TEST **" << std::endl;
    // EQUAL INDEPENDENT OF POINTS
    {
        Team team_one("abcdefgh");
        Team team_two("abcdefgh");
        team_one.addPoints(500);
        CPPUNIT_ASSERT(team_one == team_two);
        std::cout << " ....OK!" << std::endl;
    }
}

void TeamTests::alphabeticalSortTest()
{
    std::cout << "** ALPHABETICAL SORTING TEST **" << std::endl;
    // ONE LONGER THAN THE OTHER
    {
        Team team_one("abcdefgh");
        Team team_two("abcdefghijk");
        std::cout << team_one.getName() << " < " << team_two.getName();
        CPPUNIT_ASSERT(team_one < team_two);
        std::cout << " ....OK!" << std::endl;
    }

    // SPACE RULES
    {
        Team team_one("ab cdefgh");
        Team team_two("abcdefgh");
        std::cout << team_one.getName() << " < " << team_two.getName();
        CPPUNIT_ASSERT(team_one < team_two);
        std::cout << " ....OK!" << std::endl;
    }
}

void TeamTests::pointSortTest()
{
    std::cout << "** POINT SORTING TEST **" << std::endl;
    for(int i(0); i < 100; i++)
    {
        Team t1(getRandomName(10));
        Team t2(getRandomName(10));

        int t1_score(getRandomScore(1000));
        int t2_score(0);
        do{
            t2_score = getRandomScore(1000);
        }while(t2_score == t1_score);

        std::cout << t1_score << " V. " << t2_score;

        t1.addPoints(t1_score);
        t2.addPoints(t2_score);

        if(t1_score < t2_score)
            CPPUNIT_ASSERT(t1 > t2);
        else
            CPPUNIT_ASSERT(t2 > t1);

        std::cout << "....OK!" << std::endl;
    }
}

