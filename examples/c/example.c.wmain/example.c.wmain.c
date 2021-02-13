/* /////////////////////////////////////////////////////////////////////////
 * File:        example.c.wmain.c
 *
 * Purpose:     Implementation file for the example.c.wmain library.
 *
 * Created:     17th January 2021
 * Updated:     13th February 2021
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2021, Synesis Information Systems Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */

/* Pantheios Extras header files */
#include <pantheios/extras/main.h>

/* Pantheios header files */
#include <pantheios/pantheios.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#ifndef PANTHEIOS_USE_WIDE_STRINGS

# error requires PANTHEIOS_USE_WIDE_STRINGS
#endif

/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

#define TOOL_NAME       L"example.c.wmain"

PANTHEIOS_EXTERN_C PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = TOOL_NAME;

/* ////////////////////////////////////////////////////////////////////// */

int main0(int argc, wchar_t* argv[])
{
    /* do the "main" business of main() here, without worrying about
     * initialising Pantheios libraries
     */

    /* suppress argc+argv here since they're unused; you will probably need them in your programs */
    STLSOFT_SUPPRESS_UNUSED(argc);
    STLSOFT_SUPPRESS_UNUSED(argv);

    return EXIT_SUCCESS;
}

int wmain(int argc, wchar_t* argv[])
{
    return pantheios_extras_main_invoke_w(argc, argv, main0, TOOL_NAME, NULL);
}

/* ///////////////////////////// end of file //////////////////////////// */

