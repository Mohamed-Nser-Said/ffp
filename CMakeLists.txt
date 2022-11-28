cmake_minimum_required(VERSION 3.16)

project(proteins_digestion_simulation VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(ENABLE_TESTING "check if tests are enabled or not" ON)



Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.1
)

FetchContent_MakeAvailable(Catch2)


add_subdirectory(tests)


include_directories("./includes")
add_library(fasta_toolkit STATIC src/FileIO.cpp src/Protein.cpp)

add_executable(run_app src/main.cpp)

target_link_libraries(run_app PUBLIC fasta_toolkit Catch2::Catch2WithMain)

