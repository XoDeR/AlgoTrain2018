cmake_minimum_required(VERSION 3.8.2)

set(SOURCES FindPairWithGivenSum01.cpp)
add_executable(FindPairWithGivenSum01 ${SOURCES})
source_group("Src" FILES ${SOURCES})
target_include_directories(FindPairWithGivenSum01 PUBLIC ./)