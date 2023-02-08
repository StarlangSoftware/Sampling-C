cmake_minimum_required(VERSION 3.23)
project(Sampling C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-O3")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(Sampling src/Bootstrap.c src/Bootstrap.h src/KFoldCrossValidation.c src/KFoldCrossValidation.h src/StratifiedKFoldCrossValidation.c src/StratifiedKFoldCrossValidation.h)
target_link_libraries(Sampling ${CONAN_LIBS})
add_executable(BootstrapTest src/Bootstrap.c src/Bootstrap.h src/KFoldCrossValidation.c src/KFoldCrossValidation.h src/StratifiedKFoldCrossValidation.c src/StratifiedKFoldCrossValidation.h Test/BootstrapTest.c)
target_link_libraries(BootstrapTest ${CONAN_LIBS})
add_executable(KFoldCrossValidationTest src/Bootstrap.c src/Bootstrap.h src/KFoldCrossValidation.c src/KFoldCrossValidation.h src/StratifiedKFoldCrossValidation.c src/StratifiedKFoldCrossValidation.h Test/KFoldCrossValidationTest.c)
target_link_libraries(KFoldCrossValidationTest ${CONAN_LIBS})
add_executable(StratifiedKFoldCrossValidationTest src/Bootstrap.c src/Bootstrap.h src/KFoldCrossValidation.c src/KFoldCrossValidation.h src/StratifiedKFoldCrossValidation.c src/StratifiedKFoldCrossValidation.h Test/StratifiedKFoldCrossValidationTest.c)
target_link_libraries(StratifiedKFoldCrossValidationTest ${CONAN_LIBS})
