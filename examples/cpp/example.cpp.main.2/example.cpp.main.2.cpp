/* /////////////////////////////////////////////////////////////////////////
 * File:        example.cpp.main.2.c
 *
 * Purpose:     Implementation file for the example.cpp.main.2 library.
 *
 * Created:     5th January 2011
 * Updated:     10th September 2015
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2011-2015, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* Pantheios Extras header files */
#include <pantheios/extras/main.hpp>

/* Pantheios header files */
#include <pantheios/pantheios.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Globals
 */

PANTHEIOS_EXTERN_C PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("example.cpp.main.2");

/* ////////////////////////////////////////////////////////////////////// */

int main0(int /* argc */, char** /* argv */)
{
    /* do the "main" business of main() here, without worrying about
     * initialising Pantheios libraries
     */

    return EXIT_SUCCESS;
}

int main(int argc, char** argv)
{
    return pantheios::extras::main::invoke(argc, argv, main0, PANTHEIOS_FE_PROCESS_IDENTITY);
}

/* ///////////////////////////// end of file //////////////////////////// */
