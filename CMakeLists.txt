cmake_minimum_required(VERSION 2.8)

project(LearnFactors)

add_executable(LearnFactors LearnFunctors.cpp)
target_compile_features(LearnFactors PRIVATE cxx_range_for)
