add_library(${Protein_Lib} STATIC Protein.cpp Protein.h)

target_include_directories(${Protein_Lib} PUBLIC ./)