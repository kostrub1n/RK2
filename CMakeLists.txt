cmake_minimum_required(VERSION 3.10)

project(GumballMachine)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(SOURCES 
    main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set(HEADERS
    component.h
    concrete_component.h
    concrete_decorator.h
    decorator.h
)


target_sources(${PROJECT_NAME} PUBLIC ${HEADERS})

include(CPack.cmake)
