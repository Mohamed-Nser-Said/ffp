if(ENABLE_TESTING)

    set(TEST_MAIN "unit_test")
    set(TEST_SOURCES main.cpp)


    add_executable(${TEST_MAIN} ${TEST_SOURCES})
    target_link_libraries(${TEST_MAIN} PUBLIC ${ffp} Catch2::Catch2WithMain)

endif()