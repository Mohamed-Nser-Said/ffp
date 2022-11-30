add_executable(${FFP_EXECUTABLE} ./main.cpp)

target_link_libraries(${FFP_EXECUTABLE} PUBLIC ${FileIO_Lib})