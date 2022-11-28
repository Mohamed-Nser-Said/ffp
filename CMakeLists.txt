cmake_minimum_required(VERSION 3.16)

project(proteins_digestion_simulation VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


set(FFP_LIB "ffp_lib")
set(FFP_EXECUTABLE "ffp")

option(ENABLE_TESTING "check if tests are enabled or not" ON)



Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.1
)

FetchContent_MakeAvailable(Catch2)


add_subdirectory(tests)
add_subdirectory(app)
add_subdirectory(src)

