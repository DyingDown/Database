project(inputBuffer)

# where are the source files
file(GLOB sources "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_library(${PROJECT_NAME} ${sources})
add_library(Database::inputBuffer ALIAS ${PROJECT_NAME})

# specify directory for all .h file
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

# link other .h files in other directories
#target_link_libraries(${PROJECT_NAME} ast)