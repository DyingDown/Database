cmake_minimum_required(VERSION 3.14)
project(Database)

# set cmake version
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILECOMMANDS ON)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake;${CMAKE_MODULE_PATH}")

IF (CMAKE_BUILD_TYPE STREQUAL Debug)
    ADD_DEFINITIONS(-DDEBUG)
ENDIF()

# specify directory for all .h file
include_directories("${PROJECT_SOURCE_DIR}/include")

# add sub project
add_subdirectory(ast)
add_subdirectory(parser)
add_subdirectory(inputBuffer)
add_subdirectory(storage)

add_executable(Database main.cpp)

# add sub project's target libraries
target_link_libraries(Database
        Database::ast
        Database::parser
        Database::inputBuffer
        Database::storage)

option(PACKAGE_TESTS "Build the tests" ON)
if(PACKAGE_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()

