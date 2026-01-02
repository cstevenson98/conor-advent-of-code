# Year 2025 Advent of Code problems

# Auto-discover and add all problem libraries
file(GLOB PROBLEM_DIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)
foreach(PROBLEM_DIR ${PROBLEM_DIRS})
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${PROBLEM_DIR})
        add_subdirectory(${PROBLEM_DIR})
    endif()
endforeach()

