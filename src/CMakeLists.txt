cmake_minimum_required(VERSION 3.23)
project(Sampling)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-O3")

find_package(util_c REQUIRED)

add_library(Sampling Bootstrap.c Bootstrap.h KFoldCrossValidation.c KFoldCrossValidation.h StratifiedKFoldCrossValidation.c StratifiedKFoldCrossValidation.h)
target_link_libraries(Sampling util_c::util_c)
