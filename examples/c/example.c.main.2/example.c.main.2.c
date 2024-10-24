/* /////////////////////////////////////////////////////////////////////////
 * File:    example.c.main.2.c
 *
 * Purpose: Implementation file for the example.c.main.2 library.
 *
 * Created: 5th January 2011
 * Updated: 24th October 2024
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

#define TOOL_NAME     "example.c.main.2"

PANTHEIOS_EXTERN_C PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING(TOOL_NAME);

/* ////////////////////////////////////////////////////////////////////// */

int main0(int argc, char* argv[])
{
    /* do the "main" business of main() here, without worrying about
     * initialising Pantheios libraries
     */

    /* suppress argc+argv here since they're unused; you will probably need them in your programs */
    STLSOFT_SUPPRESS_UNUSED(argc);
    STLSOFT_SUPPRESS_UNUSED(argv);


    pantheios_logputs(PANTHEIOS_SEV_NOTICE, PANTHEIOS_LITERAL_STRING("in main()"));


    return EXIT_SUCCESS;
}

int main(int argc, char* argv[])
{
    return pantheios_extras_main_invoke(argc, argv, main0, TOOL_NAME, NULL);
}

/* ///////////////////////////// end of file //////////////////////////// */
