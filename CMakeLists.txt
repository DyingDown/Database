cmake_minimum_required(VERSION 3.14)
project(Database)

set(CMAKE_CXX_STANDARD 14)

add_executable(Database main.cpp InputBuffer.cpp InputBuffer.h LexicalAnalyzer.cpp LexicalAnalyzer.h Token.cpp Token.h TokenType.cpp TokenType.h test_texicalAnalyzer.cpp)
add_executable(test_texicalAnalyzer test_texicalAnalyzer.cpp)