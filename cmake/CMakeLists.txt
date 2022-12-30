cmake_minimum_required(VERSION 3.13)

project(cmkpr) 

add_subdirectory(stack)

add_executable(cmkpr main.cpp solver/solver.cpp solver/solver.h)
set_target_properties(
       cmkpr PROPERTIES
       CXX_STANDARD 17
       CXX_STANDARD_REQUIRED ON
)
target_include_directories( 
       cmkpr
       PRIVATE
       ${CMAKE_CURRENT_SOURCE_DIR}/../stack
)

target_link_libraries(cmkpr lib)
