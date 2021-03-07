cmake_minimum_required(VERSION 3.0)
project("tutorial4")

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_VERBOSE_MAKEFILE ON)

find_package(LLVM REQUIRED CONFIG)

list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(AddLLVM)

add_definitions(${LLVM_DEFINITIONS})
include_directories(${LLVM_INCLUDE_DIRS})

llvm_map_components_to_libnames(llvm_libs analysis bitreader bitwriter codegen core asmparser irreader instcombine instrumentation mc objcarcopts scalaropts support ipo target transformutils vectorize)

include_directories(.)

add_executable(t4 t4.cpp)
target_link_libraries(t4 ${llvm_libs})

enable_testing()
add_test(NAME RunT4 COMMAND t4 main.bc )
