include(GoogleTest)
include(googletest)

file(GLOB test_sources
        "${PROJECT_SOURCE_DIR}/test/*.cpp"
        "${PROJECT_SOURCE_DIR}/test/inputBuffer/*.cpp"
        "${PROJECT_SOURCE_DIR}/test/parser/*.cpp"
        "${PROJECT_SOURCE_DIR}/test/ast/*.cpp"
        )

add_executable(database_test "${test_sources}")

target_include_directories(database_test PRIVATE
        "${PROJECT_SOURCE_DIR}/include"
        )
target_link_libraries(database_test PRIVATE
        gtest
        gtest_main
        Database::inputBuffer
        Database::parser
        Database::ast
        )

#gtest_discover_tests(database_test)