cmake_minimum_required( VERSION 3.13 )

set( CMAKE_CXX_STANDARD 11 )

set( CMAKE_CXX_STANDARD_REQUIRED ON )

project( look_capital_letters LANGUAGES CXX )

# Find matlab and set matlab_arch and matlab_lib_ext vars
set(MATLAB_FIND_DEBUG 1)
find_package(Matlab REQUIRED)
matlab_get_mex_suffix( ${Matlab_ROOT_DIR} mex_suffix)
#message(STATUS ${Matlab_ROOT_DIR})
STRING(REPLACE "mex" "" matlab_arch ${mex_suffix})
if(${matlab_arch} MATCHES "maci64")
  set(matlab_lib_ext dylib)
else()
  set(matlab_lib_ext so)
endif()

add_executable( main src/main.cpp )

target_include_directories( main PRIVATE 
                            ${CMAKE_SOURCE_DIR}/src
                            ${Matlab_ROOT_DIR}/extern/include )

target_link_libraries( main PRIVATE
                       ${Matlab_ROOT_DIR}/extern/bin/${matlab_arch}/libMatlabEngine.${matlab_lib_ext}
                       ${Matlab_ROOT_DIR}/extern/bin/${matlab_arch}/libMatlabDataArray.${matlab_lib_ext}
                       -lpthread )
