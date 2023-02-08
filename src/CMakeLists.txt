cmake_minimum_required(VERSION 3.23)
project(Sampling C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-O3")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(Sampling src/Bootstrap.c src/Bootstrap.h src/KFoldCrossValidation.c src/KFoldCrossValidation.h src/StratifiedKFoldCrossValidation.c src/StratifiedKFoldCrossValidation.h)
target_link_libraries(Sampling ${CONAN_LIBS})
