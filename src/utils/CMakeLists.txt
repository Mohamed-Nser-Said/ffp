add_library(${utils} STATIC utils.cpp utils.h)



target_include_directories(${utils} PUBLIC ./)

target_link_libraries(${utils} ${Protein_Lib})