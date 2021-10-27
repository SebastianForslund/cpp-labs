This directory contains a few small examples of how the google sanitizers
can be used to find problems related to memory management and undefined behaviour.
The sanitizers are libraries that are used to instrument your programs, which is
done by compiling and linking with the option -fsanitize=<SANITIZER>.

For building this example includes two makefiles, one for building without
sanitizers (Makefile) and one for building with them (Makefile.sanitizers).
Also included is a CMakeListst.txt which uses sanitizers when doing a debug build.

Examples:

The file leak.cc contains an example of a memory leak.

The files bounds.cc, bounds-heap.cc and sum.cc contain examples of accessing
outside the bounds of an array (on the stack and on the heap).

The file dangling.cc contains an example of using a dangling pointer.

The file ub.cc contains an example of undefined behaviour.

Demonstration:

First build the programs using Makefile, and run them.

Then, first do make clean and then build them using Makefile.sanitizers 
(make -f Makefile.sanitizers) 

Run the programs again, and see if the errors are detected. Try to understand
the diagnostics pringed when the sanitizer detects an error. 

Note that the different sanitizers may produce different error messages
for the same problem. Compare the output from sum and sum_alt (which are
built from the same source file, but with different sanitizers.)

This example also includes a CMakeLists.txt that illustrates how to enable
the sanitizers for debug builds.

Building with cmake:

With cmake, make debug and release builds and compare, typically in
separate build directories:

For the release build:
% mkdir build-rel
% cd build-rel
% cmake -DCMAKE_BUILD_TYPE=Release SRC_DIR
% make

For the debug build:
% mkdir build-rel
% cd build-rel
% cmake -DCMAKE_BUILD_TYPE=Debug SRC_DIR
% make

Both gcc and clang use the google sanitizers, but different compiler versions
may use different versions of the sanitizers. If you have installed a more recent
compiler version, you may need to tell cmake to use that.
By default, cmake will use the system's default compiler. To specify which
compiler to use, you can add (for gcc)
-DCMAKE_CXX_COMPILER=g++ 
-DCMAKE_C_COMPILER=gcc 
or, for clang:
-DCMAKE_CXX_COMPILER=clang++ 
-DCMAKE_C_COMPILER=clang 
