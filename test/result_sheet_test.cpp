#include "result_sheet_test.h"
#include "../result_sheet.h"
#include "test_utils.h"

void ResultSheetTest::setUp()
{
    // Nothing to do
}

void ResultSheetTest::tearDown()
{
    // Nothing to do
}

void ResultSheetTest::allMatchesValidTest()
{
    std::cout << "*** ALL MATCHES VALID IN FILE TEST ***" << std::endl;
    // WRITE TO FILE
    std::ofstream out_stream_(ResultSheetTest::_test_filename, std::ios_base::trunc);
    CPPUNIT_ASSERT(out_stream_.is_open());

    for(int i(0); i < 100; i++)
    {
        out_stream_ << getRandomMatchLine(30,50);
        out_stream_ << "\n";
    }
    out_stream_.close();

    ResultSheet result_sheet(_test_filename);
    std::vector<Match> matches(result_sheet.getMatches());

    std::cout << "Expected match count " << 100 << "...  Received: " << matches.size() << std::endl;
    CPPUNIT_ASSERT(result_sheet.getMatches().size() == 100);
    std::cout << ".....OK!" << std::endl;
}

void ResultSheetTest::invalidMatchesTest()
{
    std::cout << "*** ALL MATCHES VALID EXCEPT ONE FILE TEST ***" << std::endl;
    // WRITE TO FILE
    std::ofstream out_stream_(ResultSheetTest::_test_filename, std::ios_base::trunc);
    CPPUNIT_ASSERT(out_stream_.is_open());

    for(int i(0); i < 50; i++)
    {
        out_stream_ << getRandomMatchLine(30,50);
        out_stream_ << "\n";
    };
    for(int i(0); i < 24; i++)
    {
        out_stream_ << "blah fjsfrgsef\n";
    }
    for(int i(0); i < 100; i++)
    {
        out_stream_ << getRandomMatchLine(30,50);
        out_stream_ << "\n";
    };

    out_stream_.close();

    ResultSheet result_sheet(ResultSheetTest::_test_filename);
    std::vector<Match> matches(result_sheet.getMatches());

    std::cout << "Expected match count " << 150 << "...  Received: " << matches.size() << std::endl;
    CPPUNIT_ASSERT(result_sheet.getMatches().size() == 150);
    std::cout << ".....OK!" << std::endl;
}

