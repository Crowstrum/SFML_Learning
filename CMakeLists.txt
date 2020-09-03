cmake_minimum_required(VERSION 3.5.1)
project(CMakeStarter VERSION 0.1.0)

include(CTest)
enable_testing()
set(CMAKE_CXX_STANDARD 14)
set(SFML_VERSION "2.5.1")
include(FetchContent)
FetchContent_Declare(
    sfml
    GIT_REPOSITORY "https://github.com/SFML/SFML.git"
    GIT_TAG        "${SFML_VERSION}"
)

FetchContent_GetProperties(sfml)
if(NOT sfml_POPULATED)
    FetchContent_Populate(sfml)
    add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
endif()

set(INCLUDESDIR "include")

set(
H_FILES 
${INCLUDESDIR}/Game.hpp 
${INCLUDESDIR}/ResourceHolder.hpp 
${INCLUDESDIR}/ResourceHolder.inl
${INCLUDESDIR}/Entity.hpp
${INCLUDESDIR}/Ship.hpp
)
include_directories(include)

set(SRCDIR "src")
set(
CPP_FILES
${SRCDIR}/main.cpp
${SRCDIR}/Game.cpp
${SRCDIR}/Entity.cpp
${SRCDIR}/Ship.cpp
)

add_executable(CMakeStarter ${CPP_FILES} ${H_FILES})

target_link_libraries(CMakeStarter sfml-audio sfml-graphics sfml-system sfml-window)

target_compile_options(CMakeStarter PRIVATE -Wall)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
