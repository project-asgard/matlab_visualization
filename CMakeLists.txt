cmake_minimum_required( VERSION 3.13 )

set( CMAKE_CXX_STANDARD 11 )

set( CMAKE_CXX_STANDARD_REQUIRED ON )

project( look_capital_letters LANGUAGES CXX )

add_executable( main src/main.cpp )

target_include_directories( main PRIVATE 
                            ${CMAKE_SOURCE_DIR}/src
                            /usr/local/MATLAB/R2019b/extern/include )

target_link_libraries( main PRIVATE
                       /usr/local/MATLAB/R2019b/extern/bin/glnxa64/libMatlabEngine.so
                       /usr/local/MATLAB/R2019b/extern/bin/glnxa64/libMatlabDataArray.so
                       -lpthread )
