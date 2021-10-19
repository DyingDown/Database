cmake_minimum_required(VERSION 3.14)
project(Database)

# set cmake version
set(CMAKE_CXX_STANDARD 17)

# specify directory for all .h file
include_directories("${PROJECT_SOURCE_DIR}/include")

# add sub project
add_subdirectory(ast)
add_subdirectory(parser)
add_subdirectory(inputBuffer)

add_executable(Database main.cpp)

# add sub project's target libraries
target_link_libraries(Database Database::ast Database::parser Database::inputBuffer)

