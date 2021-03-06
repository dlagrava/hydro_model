cmake_minimum_required(VERSION 3.1)

project(Hydro_Model)

set(Project-Name_VERSION_MAJOR 0)
set(Project-Name_VERSION_MINOR 1)
set(Project-Name_VERSION_PATCH 0)
set(Project-Name_VERSION "${Project-Name_VERSION_MAJOR}.${Project-Name_VERSION_MINOR}.${Project-Name_VERSION_PATCH}")

set(PROJ_NAME "\"Hydro_Model\"") # PROJECT_NAME is a predefined variable
set(PROJECT_DESCRIPTION "\"C++14 version of a Hydro model\"")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Options
option(BUILD_TESTS "Build test executable" OFF)
option(GEN_DOCS "Generate documentation" ON)
option(ENABLE_COVERAGE "Enable code coverage" OFF)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to 'Release' as no build type was specified")
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the build type (Debug/Release)" FORCE)
endif (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)

if (ENABLE_COVERAGE AND NOT CMAKE_CONFIGURATION_TYPES)
    if (NOT BUILD_TESTS)
        message(FATAL_ERROR "Tests must be enabled for code coverage!")
    endif (NOT BUILD_TESTS)
    
    include(CodeCoverage)
    
    append_coverage_compiler_flags()
    set(COVERAGE_EXCLUDES "/usr/include/\\*;${CMAKE_SOURCE_DIR}/src/main.cc;${CMAKE_SOURCE_DIR}/test/*;${CMAKE_SOURCE_DIR}/third_party/doctest/*")
    
    setup_target_for_coverage(NAME coverage EXECUTABLE ctest DEPENDENCIES coverage)
else (ENABLE_COVERAGE AND NOT CMAKE_CONFIGURATION_TYPES)
    if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
        set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")
    elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /WX")
        set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /O2")
    endif(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
endif (ENABLE_COVERAGE AND NOT CMAKE_CONFIGURATION_TYPES)

#set(LIBRARY_SOURCES
#    src/input_utils.cc
#    src/reach.cc
#    src/river_network.cc
#)

include_directories("include/hydro_model")

file(GLOB LIBRARY_SOURCES "src/*.cc")

add_library(hydro-model-lib ${LIBRARY_SOURCES}) # main library
set_target_properties(hydro-model-lib PROPERTIES PREFIX "") # Remove the lib prefix
target_include_directories(hydro-model-lib PUBLIC ${CMAKE_SOURCE_DIR}/include ${CMAKE_BINARY_DIR}/include)

# cpptoml: https://github.com/skystrife/cpptoml
add_library(cpptoml INTERFACE)
target_include_directories(cpptoml INTERFACE "${CMAKE_SOURCE_DIR}/third_party/cpptoml")

# the main executable
add_executable(hydro-model apps/hydro_model.cc) # The main executable
target_link_libraries(hydro-model hydro-model-lib cpptoml) # Link our sources to the executable

if (BUILD_TESTS)
    include(CTest)
    enable_testing()
    add_subdirectory(test)
endif (BUILD_TESTS)

if (GEN_DOCS)
    add_subdirectory(doc)
endif (GEN_DOCS)

# Install the built library and executable into the appropriate directory
install(TARGETS hydro-model DESTINATION bin)
install(TARGETS hydro-model-lib
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

# Install the project header files into the appropriate directory
install(DIRECTORY include/ DESTINATION include PATTERN) # Install our main header files

# Install the project's extra files
install(FILES README.md LICENSE DESTINATION share/hydro_model)

