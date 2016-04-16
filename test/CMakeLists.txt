enable_testing()
find_package(GTest REQUIRED)

include_directories (${CMAKE_CURRENT_SOURCE_DIR})
include_directories (${GTEST_INCLUDE_DIRS})
file(GLOB_RECURSE test_source_files ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable (main_test ${test_source_files})

target_link_libraries(main_test sfvfs_lib ${GTEST_BOTH_LIBRARIES} pthread)

add_test(MainTest main_test)

add_custom_target( runtest ALL
DEPENDS main_test)

add_custom_command(TARGET runtest
                   POST_BUILD
               COMMAND main_test)
