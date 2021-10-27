#include <iostream>
#include "SimpleConfig.h"
#include "foo.h"
#include "bar.h"



using std::cout;
using std::endl;

/* A small example of a project built using CMake.
 * The Simple_VERSION_* variables are included
 * to show how a header file with configuration macros
 * can be generated from the CMakeLists.txt.
 */
int main()
{
    cout << "This is version " << Simple_VERSION_MAJOR << "." <<
        Simple_VERSION_MINOR << "\n";
    cout << "Hello, world!\n";
    foo_fun();
    bar_fun(42);
}


