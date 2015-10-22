## league-sort

## Installation
Within the directory:  

cmake CMakeLists.txt  
make  
./leagueSort <input filename>  

## Dependencies  
C++11  
cppunit (for unit tests) --> http://sourceforge.net/projects/cppunit/  

## Tests
All tests implemented in subdirectory 'test'. Comment out the following line in the CMakeLists.txt file to enable unit tests:  
#add_subdirectory(test)

and recompile. A new executable 'runTests' will be generated within the test sub-directory.  
