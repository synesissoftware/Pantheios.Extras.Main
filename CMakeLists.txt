
cmake_minimum_required(VERSION 3.0)

if(WIN32)

    message(FATAL_ERROR "Use of CMake on Windows not currently supported")
endif()

install(
    DIRECTORY ${CMAKE_SOURCE_DIR}/include/
    DESTINATION include
    FILES_MATCHING PATTERN "*.h*"
	)

