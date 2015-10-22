#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <string>
#include "../team.h"

class ChampionshipSimulatorTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( ChampionshipSimulatorTest );
    CPPUNIT_TEST( testExpectedResult );
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

    void testExpectedResult();

    void checkEqual(const std::string & name, int points, const Team & team);

private:
    const std::string _test_filename = "test_file";

    const static std::string file_input;
};

CPPUNIT_TEST_SUITE_REGISTRATION( ChampionshipSimulatorTest );
