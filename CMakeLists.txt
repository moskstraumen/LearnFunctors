cmake_minimum_required(VERSION 2.8)

project(LearnFactors)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
add_executable(LearnFactors LearnFunctors.cpp)
target_compile_features(LearnFactors PRIVATE cxx_range_for)
target_link_libraries(LearnFactors ${PYTHON_LIBRARIES})