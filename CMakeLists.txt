
cmake_minimum_required(VERSION 3.10)
project(SimpleC)

find_package(LLVM REQUIRED CONFIG)
find_package(Clang REQUIRED CONFIG)

include_directories(${LLVM_INCLUDE_DIRS})
include_directories(${CLANG_INCLUDE_DIRS})
link_directories(${LLVM_LIBRARY_DIRS})

add_definitions(${LLVM_DEFINITIONS})

set(SOURCE_FILES
    src/main.cpp
)

add_executable(simplec ${SOURCE_FILES})

target_link_libraries(simplec
    PRIVATE
    clangTooling
    clangFrontend
    clangAST
    clangRewrite
    clangBasic
    clangSerialization
    
    LLVM
)

