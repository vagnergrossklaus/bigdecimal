cmake_minimum_required(VERSION 3.14)

project(BigDecimal LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(ENABLE_TESTING ON)

if(ENABLE_TESTING)
   enable_testing()
   add_subdirectory(test)
endif()

add_library(BigDecimal SHARED
    src/bigdecimal.cpp
)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC include)

target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE BIGDECIMAL_LIBRARY)
