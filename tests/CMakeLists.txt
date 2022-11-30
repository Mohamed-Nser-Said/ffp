if(ENABLE_TESTING)

    set(TEST_MAIN "unit_test")
    set(TEST_SOURCES main.cpp)

    include_directories(${PROJECT_SOURCE_DIR}/includes)
    add_executable(${TEST_MAIN} ${TEST_SOURCES})
    target_link_libraries(${TEST_MAIN} PUBLIC ${Protein_Lib} Catch2::Catch2WithMain)

endif()