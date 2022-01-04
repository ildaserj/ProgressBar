cmake_minimum_required(VERSION 3.19)
project(test)

add_subdirectory(lib/googletest-main)
set(gtest_SOURCE_DIR, lib/googletest-main/googletest)
include_directories(lib/googletest-main/googletest/include)

set(SOURCE_FILES ResourceFileTest.cpp FileManagerTest.cpp)
add_executable(RunAllTest ${SOURCE_FILES})
target_link_libraries(RunAllTest gtest gtest_main)
#target_link_libraries(RunAllTest ${GTEST_BOTH_LIBRARIES} )

#core stdc++fs





