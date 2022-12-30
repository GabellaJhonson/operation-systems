cmake_minimum_required(VERSION 3.13)

project(Library)

add_library(lib STATIC src/ThreadSafeStack.cpp include/ThreadSafeStack.h)

set_target_properties(
       lib PROPERTIES
       CXX_STANDARD 17
       CXX_STANDARD_REQUIRED ON
)
target_include_directories( 
       cmkpr
       PUBLIC
       ${CMAKE_CURRENT_SOURCE_DIR}
)
