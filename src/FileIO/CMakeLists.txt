add_library(${FileIO_Lib} STATIC FileIO.cpp fileio.h)



target_include_directories(${FileIO_Lib} PUBLIC ./)

target_link_libraries(${FileIO_Lib} ${Protein_Lib})