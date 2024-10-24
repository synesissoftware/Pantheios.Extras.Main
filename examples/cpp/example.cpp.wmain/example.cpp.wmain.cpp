/* /////////////////////////////////////////////////////////////////////////
 * File:    example.cpp.wmain.cpp
 *
 * Purpose: Implementation file for the example.cpp.wmain library.
 *
 * Created: 13th October 2015
 * Updated: 24th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * feature control
 */

// This is defined for illustrative purposes. You are advised to *not*
// define this in production code. See Quality Matters, #5: "Exceptions:
// The Worst Form of Error Handling, Apart From All The Others" for details
// (http://quality-matters-to.us/).
#define PANTHEIOS_EXTRAS_MAIN_USE_CATCHALL

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* Pantheios Extras header files */
#include <pantheios/extras/main.hpp>

/* Pantheios header files */
#include <pantheios/pantheios.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

PANTHEIOS_EXTERN_C PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("example.cpp.wmain");

/* ////////////////////////////////////////////////////////////////////// */

int main0(int argc, wchar_t* argv[])
{
    /* do the "main" business of main() here, without worrying about
     * initialising Pantheios libraries
     */

    /* in this case, we simply throw a given type of exception, as
     * requested by the user
     */

    if (argc == 2)
    {
        if (0 == wcscmp(argv[1], L"memory"))
        {
            throw std::bad_alloc();
        }
        else
        if (0 == wcscmp(argv[1], L"root"))
        {
            throw std::runtime_error("oops!");
        }
        else
        {
            throw 1.0;
        }
    }

    printf(
        "USAGE: %s {memory|root|other}\n"
    ,   argv[0]
    );

    return EXIT_SUCCESS;
}

int wmain(int argc, wchar_t* argv[])
{
    return pantheios::extras::main::invoke(argc, argv, main0);
}

/* ///////////////////////////// end of file //////////////////////////// */

