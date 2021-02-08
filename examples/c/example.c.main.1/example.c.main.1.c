/* /////////////////////////////////////////////////////////////////////////
 * File:        example.c.main.1.c
 *
 * Purpose:     Implementation file for the example.c.main.1 library.
 *
 * Created:     5th January 2011
 * Updated:     18th October 2019
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2011-2019, Synesis Software Pty Ltd.
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
 * globals
 */

PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("example.c.main.1");

/* ////////////////////////////////////////////////////////////////////// */

int main0(int argc, char** argv)
{
    /* do the "main" business of main() here, without worrying about
     * initialising Pantheios libraries
     */

    /* suppress argc+argv here since they're unused; you will probably need them in your programs */
    STLSOFT_SUPPRESS_UNUSED(argc);
    STLSOFT_SUPPRESS_UNUSED(argv);


    pantheios_logputs(PANTHEIOS_SEV_DEBUG, PANTHEIOS_LITERAL_STRING("in main()"));


    return EXIT_SUCCESS;
}

int main(int argc, char** argv)
{
    return pantheios_extras_main_invoke(argc, argv, main0, NULL, NULL);
}

/* ///////////////////////////// end of file //////////////////////////// */
