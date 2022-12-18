add_library(${ffp} STATIC utils.cpp Protein.cpp)

target_include_directories(${ffp} PUBLIC ./)