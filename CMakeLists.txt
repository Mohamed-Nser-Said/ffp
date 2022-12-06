cmake_minimum_required(VERSION 3.16)

project(proteins_digestion_simulation VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


set(utils "utils")
set(Protein_Lib "Protein_Lib")
set(FFP_EXECUTABLE "ffp")
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")

option(ENABLE_TESTING "check if tests are enabled or not" ON)


include(Docs)
Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.1
)

FetchContent_MakeAvailable(Catch2)


add_subdirectory(tests)
add_subdirectory(src)
add_subdirectory(example)


