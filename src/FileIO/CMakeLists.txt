add_library(${FileIO_Lib} STATIC utils.cpp utils.h)



target_include_directories(${FileIO_Lib} PUBLIC ./)

target_link_libraries(${FileIO_Lib} ${Protein_Lib})