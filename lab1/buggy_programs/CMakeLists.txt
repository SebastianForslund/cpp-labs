# An example CMakeLists.txt for the sanitizers example, showing how to
# enable sanitizers in a debug build.
# It uses generator expressions, to set additional flags when the build type
# is Debug.
#
# To try this out, first create a build directory for a release build, 
# and do a release build, e.g.,
# % mkdir build-rel
# % cd build-rel
# % cmake SRC_DIR -DCMAKE_BUILD_TYPE=Release
# % make
#
# Run the examples and see that they crash.
#
# Then create another build directory and do a debug build:
#
# % mkdir build-dbg
# % cd build-dbg
# % cmake SRC_DIR -DCMAKE_BUILD_TYPE=Debug
# % make
#
# where SRC_DIR is the directory containing the source and CMakeLists.txt,
# e.g., .. if your build directories are placed in this directory.
# 
# Run the examples and verify that the sanitizers find the errors.
#
# If you want to see the actual commands run during the build, for instance
# to verify that the correct compiler flags are used, you can do
#
# % make VERBOSE=1


cmake_minimum_required (VERSION 3.5)
project (Sanitizers)
set (CMAKE_CXX_STANDARD 11)

# The three standard build types are Release, Debug, and RelWithDebInfo.
# If set here, it forces that build type.
#
# set(CMAKE_BUILD_TYPE Release)
# set build type to DEBUG
# set(CMAKE_BUILD_TYPE Debug)
# or to get an optimized build w/ debug symbols
# set(CMAKE_BUILD_TYPE RelWithDebInfo)

# add the executables
add_executable(leak leak.cc)
add_executable(bounds bounds.cc)
add_executable(bounds-heap bounds-heap.cc)
add_executable(ub ub.cc)
add_executable(dangling dangling.cc)
add_executable(sum sum.cc)
add_executable(sum_alt sum.cc)

# set compiler flag to turn off optimization (for all builds)
# add_compile_options("-O0")
# or use generator expressions to set flags in debug builds
add_compile_options($<$<CONFIG:Debug>:-O0>)

# set compiler and linker flags to enable the relevant sanitizer
target_compile_options(leak PUBLIC $<$<CONFIG:Debug>:-fsanitize=leak>)
target_link_libraries(leak $<$<CONFIG:Debug>:-fsanitize=leak>)

target_compile_options(bounds PUBLIC $<$<CONFIG:Debug>:-fsanitize=address>)
target_link_libraries(bounds $<$<CONFIG:Debug>:-fsanitize=address>)

target_compile_options(bounds-heap PUBLIC $<$<CONFIG:Debug>:-fsanitize=address>)
target_link_libraries(bounds-heap $<$<CONFIG:Debug>:-fsanitize=address>)

target_compile_options(ub PUBLIC $<$<CONFIG:Debug>:-fsanitize=undefined>)
target_link_libraries(ub $<$<CONFIG:Debug>:-fsanitize=undefined>)

target_compile_options(dangling PUBLIC $<$<CONFIG:Debug>:-fsanitize=address>)
target_link_libraries(dangling $<$<CONFIG:Debug>:-fsanitize=address>)

target_compile_options(sum PUBLIC $<$<CONFIG:Debug>:-fsanitize=undefined>)
target_link_libraries(sum $<$<CONFIG:Debug>:-fsanitize=undefined>)

target_compile_options(sum_alt PUBLIC $<$<CONFIG:Debug>:-fsanitize=address>)
target_link_libraries(sum_alt $<$<CONFIG:Debug>:-fsanitize=address>)

