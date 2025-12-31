cmake_minimum_required(VERSION 3.10)
project(SimpleC)

# Find Clang and LLVM
find_package(Clang REQUIRED)
find_package(LLVM REQUIRED)

include_directories(${LLVM_INCLUDE_DIRS} ${CLANG_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/include) # Your internal headers

add_definitions(${LLVM_DEFINITIONS})

# Group your source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(sc ${SOURCES})

target_link_libraries(sc
    clangTooling
    clangFrontend
    clangRewrite
    clangAST
    clangASTMatchers
    clangBasic
    LLVMSupport
    LLVMCore
)