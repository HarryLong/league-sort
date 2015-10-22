#ifndef RESULT_SHEET_TEST_H
#define RESULT_SHEET_TEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <string>

class ResultSheetTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( ResultSheetTest );
    CPPUNIT_TEST( allMatchesValidTest );
    CPPUNIT_TEST( invalidMatchesTest );
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

    void allMatchesValidTest();
    void invalidMatchesTest();

private:
    const std::string _test_filename = "test_file";

};

CPPUNIT_TEST_SUITE_REGISTRATION( ResultSheetTest );

#endif //RESULT_SHEET_TEST_H
