/* /////////////////////////////////////////////////////////////////////////
 * File:        pantheios/extras/main/invoke.h
 *
 * Purpose:     Definition of the pantheios_extras_main_invoke() function.
 *
 * Created:     29th December 2010
 * Updated:     13th February 2021
 *
 * Home:        http://www.pantheios.org/
 *
 * Copyright (c) 2019-2021, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2010-2019, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - Neither the name(s) of Matthew Wilson and Synesis Information Systems
 *   nor the names of any contributors may be used to endorse or promote
 *   products derived from this software without specific prior written
 *   permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


/** \file pantheios/extras/main/invoke.h
 * [C only] Definition of the pantheios_extras_main_invoke() function,
 *   as part of the
 *   \ref group__library__pantheios_extras_main "Pantheios.Extras.Main" library.
 */

#ifndef PANTHEIOS_EXTRAS_MAIN_INCL_PANTHEIOS_EXTRAS_MAIN_H_INVOKE
#define PANTHEIOS_EXTRAS_MAIN_INCL_PANTHEIOS_EXTRAS_MAIN_H_INVOKE

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# define PANTHEIOS_EXTRAS_MAIN_VER_PANTHEIOS_EXTRAS_MAIN_H_INVOKE_MAJOR     1
# define PANTHEIOS_EXTRAS_MAIN_VER_PANTHEIOS_EXTRAS_MAIN_H_INVOKE_MINOR     3
# define PANTHEIOS_EXTRAS_MAIN_VER_PANTHEIOS_EXTRAS_MAIN_H_INVOKE_REVISION  1
# define PANTHEIOS_EXTRAS_MAIN_VER_PANTHEIOS_EXTRAS_MAIN_H_INVOKE_EDIT      17
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* Pantheios.Extras.Main header files */
#include <pantheios/extras/main/internal/common.h>

/* Pantheios header files */
#include <pantheios/pantheios.h>

/* STLSoft header files */
#include <platformstl/filesystem/path_functions.h>
#include <stlsoft/memory/auto_buffer.h>

/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION

STLSOFT_INLINE
void
pantheios_extras_main_cr_and_bailout_mPm_(
    char const*             programName
,   size_t                  programNameLen
,   PAN_CHAR_T const*       message
,   size_t                  messageLen
,   char const*             reason
,   size_t                  reasonLen
)
{
    pantheios_onBailOut4(PANTHEIOS_SEV_ALERT, "failed to initialise Pantheios diagnostic logging library", programName, reason);

/* NOTE: Can this be removed, since pantheios_onBailOut4 writes to stderr? Only when pantheios_onBailOut4() include program name in stderr output. */
    if (NULL == programName)
    {
        fprintf(stderr, "failed to initialise program: %.*s: %.*s\n", (int)messageLen, message, (int)reasonLen, reason);
    }
    else
    {
        fprintf(stderr, "%.*s: failed to initialise program: %.*s: %.*s\n", (int)programNameLen, programName, (int)messageLen, message, (int)reasonLen, reason);
    }
}

# ifdef PANTHEIOS_USE_WIDE_STRINGS

STLSOFT_INLINE
void
pantheios_extras_main_cr_and_bailout_wPm_(
    wchar_t const*          programName
,   size_t                  programNameLen
,   PAN_CHAR_T const*       message
,   size_t                  messageLen
,   char const*             reason
,   size_t                  reasonLen
)
{
#if 1

    pantheios_onBailOut3_w(PANTHEIOS_SEV_ALERT, message, programName);
#else

    pantheios_onBailOut4_w(PANTHEIOS_SEV_ALERT, message, programName, reason);
#endif

    /* NOTE: Can this be removed, since pantheios_onBailOut4 writes to stderr? Only when pantheios_onBailOut4() include program name in stderr output. */

    if (NULL == programName)
    {
        fwprintf(stderr, L"failed to initialise program: %.*s: %.*S\n", (int)messageLen, message, (int)reasonLen, reason);
    }
    else
    {
        fwprintf(stderr, L"%.*s: failed to initialise program: %.*s: %.*S\n", (int)programNameLen, programName, (int)messageLen, message, (int)reasonLen, reason);
    }
}
# endif /* PANTHEIOS_USE_WIDE_STRINGS */
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

/** Invokes the given <code>main()</code>-like function within the scope of
 * initialisation/uninitialisation of the Pantheios library.
 *
 * Consider the following example:
\htmlonly
<pre>
  int <strong>main0</strong>(int argc, char const* const* argv)
  {
    . . . // your "real" main()
  }
  int main(int argc, char* argv[])
  {
    return <strong>pantheios_extras_main_invoke</strong>(argc, argv, main0, "myprogram", NULL);
  }
</pre>
\endhtmlonly
 *
 * \param argc The <code>argc</code> parameter of <code>main()</code>.
 * \param argv The <code>argv</code> parameter of <code>main()</code>.
 * \param pfnMain The <code>main()</code>-like function to be invoked.
 * \param programName Optional program name. May be <code>NULL</code>.
 * \param reserved Reserved for future use. Must be <code>NULL</code>.
 *
 * \return <code>EXIT_FAILURE</code> if the Pantheios library cannot be
 *   initialised; otherwise, the return value of <code>pfnMain</code>.
 *
 * \pre (NULL != argv)
 * \pre (NULL != pfnMain)
 * \pre (NULL == reserved)
 */
PANTHEIOS_EXTERN_C
STLSOFT_INLINE
int
pantheios_extras_main_invoke(
    int         argc
,   char**      argv
,   int       (*pfnMain)(int, char**)
,   char const* programName
,   void*       reserved
)
{
#ifndef PANTHEIOS_NO_NAMESPACE

    /* If this is used in a C++ compilation unit, we need to 'use' the
     * requisite symbols for the following code to be able to see them
     * and compile as it does in C compilation.
     */
    using namespace pantheios;
    using namespace pantheios::util;
#endif /* PANTHEIOS_NO_NAMESPACE */

    int const   r = pantheios_init();

    STLSOFT_SUPPRESS_UNUSED(reserved);

    if (r < 0)
    {
        PAN_CHAR_T const    message[]       =   PANTHEIOS_LITERAL_STRING("failed to initialise Pantheios diagnostic logging library");
        size_t const        messageLen      =   STLSOFT_NUM_ELEMENTS(message) - 1;
        char const* const   reason          =   pantheios_getInitCodeString(r);
        size_t const        reasonLen       =   pantheios_getInitCodeStringLength(r);
        size_t              lenProgramName;

        if (NULL != programName &&
            '\0' == programName[0])
        {
            programName     =   NULL;
            lenProgramName  =   0;
        }

        if (NULL == programName)
        {
#if STLSOFT_LEAD_VER >= 0x010a0000

# ifndef PLATFORMSTL_NO_NAMESPACE

            using namespace ::stlsoft;
            using namespace ::platformstl;
# endif
# if _STLSOFT_VER < 0x010a019a

            typedef stlsoft_C_string_slice_a_t      slice_t;
#else

            typedef stlsoft_C_string_slice_m_t      slice_t;
#endif

            slice_t const pn = platformstl_C_get_executable_name_from_path(argv[0]);

            programName     =   pn.ptr;
            lenProgramName  =   pn.len;
#else

            lenProgramName  =   0;
#endif
        }
        else
        {
            lenProgramName  =   strlen(programName);
        }

        pantheios_extras_main_cr_and_bailout_mPm_(
            programName, lenProgramName
        ,   message, messageLen
        ,   reason, reasonLen
        );

        return EXIT_FAILURE;
    }
    else
    {
        int const mr = pfnMain(argc, argv);

        pantheios_uninit();

        return mr;
    }
}


#if 0
#elif defined(PANTHEIOS_USE_WIDE_STRINGS) || \
      defined(PANTHEIOS_DOCUMENTATION_SKIP_SECTION)

/** Invokes the given wide-string <code>main()</code>-like function within
 * the scope of initialisation/uninitialisation of the Pantheios library.
 *
 * Consider the following example:
\htmlonly
<pre>
  int <strong>main0</strong>(int argc, wchar_t const* const* argv)
  {
    . . . // your "real" main()
  }
  int main(int argc, wchar_t* argv[])
  {
    return <strong>pantheios_extras_main_invoke</strong>(argc, argv, main0, L"myprogram", NULL);
  }
</pre>
\endhtmlonly
 *
 * \param argc The <code>argc</code> parameter of wide-string <code>main()</code>.
 * \param argv The <code>argv</code> parameter of wide-string <code>main()</code>.
 * \param pfnMain The wide-string <code>main()</code>-like function to be invoked.
 * \param programName Optional program name. May be <code>NULL</code>.
 * \param reserved Reserved for future use. Must be <code>NULL</code>.
 *
 * \return <code>EXIT_FAILURE</code> if the Pantheios library cannot be
 *   initialised; otherwise, the return value of <code>pfnMain</code>.
 *
 * \pre (NULL != argv)
 * \pre (NULL != pfnMain)
 * \pre (NULL == reserved)
 */
PANTHEIOS_EXTERN_C
STLSOFT_INLINE
int
pantheios_extras_main_invoke_w(
    int             argc
,   wchar_t**       argv
,   int           (*pfnMain)(int, wchar_t**)
,   wchar_t const*  programName
,   void*           reserved
)
{
#ifndef PANTHEIOS_NO_NAMESPACE
    /* If this is used in a C++ compilation unit, we need to 'use' the
     * requisite symbols for the following code to be able to see them
     * and compile as it does in C compilation.
     */
    using namespace pantheios;
    using namespace pantheios::util;
#endif /* PANTHEIOS_NO_NAMESPACE */

    int const   r = pantheios_init();

    STLSOFT_SUPPRESS_UNUSED(reserved);

    if (r < 0)
    {
        PAN_CHAR_T const    message[]       =   PANTHEIOS_LITERAL_STRING("failed to initialise Pantheios diagnostic logging library");
        size_t const        messageLen      =   STLSOFT_NUM_ELEMENTS(message) - 1;
        char const* const   reason          =   pantheios_getInitCodeString(r);
        size_t const        reasonLen       =   pantheios_getInitCodeStringLength(r);
        size_t              lenProgramName;

        if (NULL != programName &&
            '\0' == programName[0])
        {
            programName     =   NULL;
            lenProgramName  =   0;
        }

        if (NULL == programName)
        {
#ifndef PLATFORMSTL_NO_NAMESPACE

            using namespace ::stlsoft;
            using namespace ::platformstl;
#endif

            typedef stlsoft_C_string_slice_w_t      slice_t;

            slice_t const pn = platformstl_C_get_executable_name_from_path_w(argv[0]);

            programName     =   pn.ptr;
            lenProgramName  =   pn.len;
        }
        else
        {
            lenProgramName  =   wcslen(programName);
        }

        pantheios_extras_main_cr_and_bailout_wPm_(
            programName, lenProgramName
        ,   message, messageLen
        ,   reason, reasonLen
        );

        return EXIT_FAILURE;
    }
    else
    {
        int const mr = pfnMain(argc, argv);

        pantheios_uninit();

        return mr;
    }
}
#endif /* PANTHEIOS_USE_WIDE_STRINGS */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !PANTHEIOS_EXTRAS_MAIN_INCL_PANTHEIOS_EXTRAS_MAIN_H_INVOKE */

/* ///////////////////////////// end of file //////////////////////////// */

