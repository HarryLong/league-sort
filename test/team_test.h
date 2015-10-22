#ifndef TEAM_TEST_H
#define TEAM_TEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <string>

class TeamTests : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( TeamTests );
    CPPUNIT_TEST( equalityTest );
    CPPUNIT_TEST( alphabeticalSortTest );
    CPPUNIT_TEST( pointSortTest );
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

    void equalityTest();
    void alphabeticalSortTest();
    void pointSortTest();

private:
};

CPPUNIT_TEST_SUITE_REGISTRATION( TeamTests );

#endif //TEAM_TEST_H
