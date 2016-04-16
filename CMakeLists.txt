cmake_minimum_required(VERSION 2.8)
project(sfvfs)

OPTION(CMAKE_BUILD_TYPE "构建类型 / Build Type" Debug)
OPTION(BUILD_SHARED_LIBS "使用动态库 / Build with dynamic libraries." OFF)
OPTION(COVERAGE_FLAG "代码覆盖率 / Code coverag. " OFF)

## 配置输出目录
SET (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

## include路径配置
include_directories(
    include
)

file(GLOB_RECURSE source_files ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
file(GLOB_RECURSE main_file ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c)
list(REMOVE_ITEM source_files main_file)


SET (CMAKE_CXX_COMPILER_ENV_VAR "clang")
SET (CMAKE_CXX_FLAGS_DEBUG   "-g")
SET (CMAKE_CXX_FLAGS_MINSIZEREL  "-Os -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELEASE  "-O4 -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")
if(COVERAGE_FLAG)
	SET (CMAKE_CXX_FLAGS "-std=c99 -coverage")
else()
	SET (CMAKE_CXX_FLAGS "-std=c99")
endif()

add_library(sfvfs_lib ${source_files})
add_executable(sfvfs ${main_file})
link_libraries(sfvfs sfvfs_lib)

add_subdirectory(doc)
# add_subdirectory(test)
