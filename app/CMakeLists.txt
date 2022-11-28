add_executable(${FFP_EXECUTABLE} ./main.cpp)

target_link_libraries(${FFP_EXECUTABLE} PUBLIC ${FFP_LIB} Catch2::Catch2WithMain)