#ifndef MATCH_TEST_H
#define MATCH_TEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <string>

class MatchTests : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( MatchTests );
    CPPUNIT_TEST( test1 );
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

    void test1();
};

CPPUNIT_TEST_SUITE_REGISTRATION( MatchTests );

#endif // MATCH_TEST_H
