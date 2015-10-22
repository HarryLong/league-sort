find_package(CppUnit REQUIRED)

set(CMAKE_AUTOMOC ON)

set(INCLUDE_DIRECTORIES ${CppUnit_INCLUDE_DIRS})
include_directories(${INCLUDE_DIRECTORIES})

set(LIBS cppunit)

SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -O2 -g -std=c++11")
SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2 -std=c++11")
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g -std=c++11")
#SET(CMAKE_BUILD_TYPE DEBUG)
#SET(CMAKE_BUILD_TYPE RELEASE)
SET(CMAKE_BUILD_TYPE RELWITHDEBINFO)

SET(TEST_SRC_FILES main match_test result_sheet_test team_test championship_simulator_tests random_number_generator test_utils)
SET(SRC_FILES ../match ../utils ../team ../result_sheet ../championship_simulator ../point_scheme)

add_executable(runTests ${TEST_SRC_FILES} ${SRC_FILES})
target_link_libraries(runTests ${LIBS})

