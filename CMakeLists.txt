cmake_minimum_required(VERSION 3.10)
project(cmake_testapp)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BINARY_DIR /c++\ analytics/)

add_executable(cmake_testapp ./src/main.cpp ./src/core/core.cpp ./src/opengl/shader.cpp)


target_link_libraries(cmake_testapp GL)
target_link_libraries(cmake_testapp SDL2)
target_link_libraries(cmake_testapp GLEW)
