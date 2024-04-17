if(BUILD_TESTING)
    set(GPUT1_TEST
            "matrix_test.cpp"
    )
    add_executable(${PROJECT_NAME}Tests ${GPUT1_TESTS})
    target_link_libraries(${PROJECT_NAME}Tests PRIVATE GTest::gtest_main ${PROJECT_NAME})

    include(GoogleTest)
    gtest_discover_tests(${PROJECT_NAME}Tests)
endif()
