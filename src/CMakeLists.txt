
add_library(${FFP_LIB} STATIC ./FileIO.cpp ./Protein.cpp)

target_include_directories(${FFP_LIB} PUBLIC ./includes)
