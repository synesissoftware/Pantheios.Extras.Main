/* /////////////////////////////////////////////////////////////////////////
 * File:        pantheios/extras/main/invoke.hpp
 *
 * Purpose:     Definition of the pantheios::extras::main::invoke overloads.
 *
 * Created:     29th December 2010
 * Updated:     10th January 2017
 *
 * Home:        http://www.pantheios.org/
 *
 * Copyright (c) 2010-2017, Matthew Wilson and Synesis Software
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
 * - Neither the name(s) of Matthew Wilson and Synesis Software nor the
 *   names of any contributors may be used to endorse or promote products
 *   derived from this software without specific prior written permission.
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


/** \file pantheios/extras/main/invoke.hpp
 * [C++ only] Definition of the pantheios::extras::main::invoke() overloads,
 *   as part of the
 *   \ref group__library__pantheios_extras_main "Pantheios.Extras.Main" library.
 */

#ifndef PANTHEIOS_EXTRAS_MAIN_INCL_PANTHEIOS_EXTRAS_MAIN_HPP_INVOKE
#define PANTHEIOS_EXTRAS_MAIN_INCL_PANTHEIOS_EXTRAS_MAIN_HPP_INVOKE

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# define PANTHEIOS_EXTRAS_MAIN_VER_PANTHEIOS_EXTRAS_MAIN_HPP_INVOKE_MAJOR       1
# define PANTHEIOS_EXTRAS_MAIN_VER_PANTHEIOS_EXTRAS_MAIN_HPP_INVOKE_MINOR       5
# define PANTHEIOS_EXTRAS_MAIN_VER_PANTHEIOS_EXTRAS_MAIN_HPP_INVOKE_REVISION    2
# define PANTHEIOS_EXTRAS_MAIN_VER_PANTHEIOS_EXTRAS_MAIN_HPP_INVOKE_EDIT        30
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* Pantheios.Extras.Main header files */
#include <pantheios/extras/main/internal/common.hpp>

/* Pantheios header files */
#include <pantheios/pantheios.h>
#include <pantheios/internal/safestr.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>
#if STLSOFT_LEAD_VER >= 0x010a0000
# include <platformstl/filesystem/path_functions.h>
#endif
#ifdef __AFX_H__
# include <mfcstl/shims/access/string/CException.hpp>
#endif /* __AFX_H__*/
#include <stlsoft/smartptr/scoped_handle.hpp>
#include <stlsoft/shims/access/string/std/exception.hpp>

/* Standard C header files */
#include <new>
#include <stdexcept>

/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * feature control
 */

/* The manner in which Pantheios.Extras.Main reacts to unknown exceptions
 * - via the <code>catch(...) {}</code> clause - is determined by the
 * following user-definable pre-processor symbols:
 *
 * - PANTHEIOS_EXTRAS_MAIN_NO_CATCHALL
 * - PANTHEIOS_EXTRAS_MAIN_USE_CATCHALL
 * - PANTHEIOS_EXTRAS_MAIN_CATCHALL_ABSORB_UNKNOWN_EXCEPTIONS
 * - PANTHEIOS_EXTRAS_MAIN_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS
 *
 *
 * These apply according to the following rules:
 *
 * 1. If PANTHEIOS_EXTRAS_MAIN_NO_CATCHALL is explicitly specified, no
 *    catch-all functionality is enabled, regardless of any other
 *    circumstances.
 *
 * 2. Except for rule 1, if PANTHEIOS_EXTRAS_MAIN_USE_CATCHALL is explicitly
 *    specified, catch-all functionality is enabled, regardless of any other
 *    circumstances.
 *
 * 3. If neither PANTHEIOS_EXTRAS_MAIN_NO_CATCHALL nor
 *    PANTHEIOS_EXTRAS_MAIN_USE_CATCHALL are explicitly specified, then the
 *    presence of the pre-processor symbol NDEBUG will determine which is
 *    implicitly defined:
 *
 *      if NDEBUG      => PANTHEIOS_EXTRAS_MAIN_USE_CATCHALL
 *      else (!NDEBUG) => PANTHEIOS_EXTRAS_MAIN_NO_CATCHALL
 *
 * 4. Only in the case where PANTHEIOS_EXTRAS_MAIN_USE_CATCHALL is defined
 *    (either 2 or 3+NDEBUG), the symbols
 *    PANTHEIOS_EXTRAS_MAIN_CATCHALL_ABSORB_UNKNOWN_EXCEPTIONS and
 *    PANTHEIOS_EXTRAS_MAIN_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS take effect,
 *    as described in 4.1-4.3. Note that in all cases, the catch-all clause
 *    issues diagnostic logging statement and contingent report prior to
 *    taking the further action.
 *
 * 4.1. If PANTHEIOS_EXTRAS_MAIN_CATCHALL_ABSORB_UNKNOWN_EXCEPTIONS is
 *      defined, then the catch-all clause will do nothing with the caught
 *      exception, resulting in the program returning
 *      <code>EXIT_FAILURE</code>.
 * 4.2. If PANTHEIOS_EXTRAS_MAIN_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS is
 *      defined, then the catch-all clause will issue a <code>throw;</code>
 *      statement, rethrowing the caught exception.
 * 4.3. If neither is defined, then the catch-all clause will issue a call
 *      to <code>pantheios::core::exitProcess()</code>, passing
 *      <code>EXIT_FAILURE</code> to designate the program exit status. This
 *      call will result in an immediate exit to the program, and non-local
 *      object destructors will not be invoked. Although this is not
 *      "desired", it is the most sensible, since a program that is in
 *      receipt of an unknown exception may not be in a state suitable for
 *      further execution (including deallocation of resources in non-local
 *      object destructors).
 */

#if defined(PANTHEIOS_EXTRAS_MAIN_NO_CATCHALL)
 /* 1. */
# ifdef PANTHEIOS_EXTRAS_MAIN_USE_CATCHALL
#  undef PANTHEIOS_EXTRAS_MAIN_USE_CATCHALL
# endif /* PANTHEIOS_EXTRAS_MAIN_USE_CATCHALL */
# ifdef PANTHEIOS_EXTRAS_MAIN_CATCHALL_ABSORB_UNKNOWN_EXCEPTIONS
#  undef PANTHEIOS_EXTRAS_MAIN_CATCHALL_ABSORB_UNKNOWN_EXCEPTIONS
# endif /* PANTHEIOS_EXTRAS_MAIN_CATCHALL_ABSORB_UNKNOWN_EXCEPTIONS */
# ifdef PANTHEIOS_EXTRAS_MAIN_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS
#  undef PANTHEIOS_EXTRAS_MAIN_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS
# endif /* PANTHEIOS_EXTRAS_MAIN_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS */

#elif defined(PANTHEIOS_EXTRAS_MAIN_USE_CATCHALL)
 /* 2. */
# ifdef PANTHEIOS_EXTRAS_MAIN_NO_CATCHALL
#  error Pre-processor logic is in error
# endif /* PANTHEIOS_EXTRAS_MAIN_NO_CATCHALL */

#else /* ? PANTHEIOS_EXTRAS_MAIN_NO_CATCHALL || PANTHEIOS_EXTRAS_MAIN_USE_CATCHALL */
 /* 3. */
# ifdef PANTHEIOS_EXTRAS_MAIN_NO_CATCHALL
#  error Pre-processor logic is in error
# endif /* PANTHEIOS_EXTRAS_MAIN_NO_CATCHALL */
# ifdef PANTHEIOS_EXTRAS_MAIN_USE_CATCHALL
#  error Pre-processor logic is in error
# endif /* PANTHEIOS_EXTRAS_MAIN_USE_CATCHALL */

# ifdef NDEBUG
#  define PANTHEIOS_EXTRAS_MAIN_USE_CATCHALL
# else /* ? NDEBUG */
#  define PANTHEIOS_EXTRAS_MAIN_NO_CATCHALL
# endif /* NDEBUG */

#endif /* PANTHEIOS_EXTRAS_MAIN_NO_CATCHALL || PANTHEIOS_EXTRAS_MAIN_USE_CATCHALL */


#ifdef PANTHEIOS_EXTRAS_MAIN_USE_CATCHALL
 /* 4. */
# ifdef PANTHEIOS_EXTRAS_MAIN_NO_CATCHALL
#  error Pre-processor logic is in error
# endif /* PANTHEIOS_EXTRAS_MAIN_NO_CATCHALL */

# if defined(PANTHEIOS_EXTRAS_MAIN_CATCHALL_ABSORB_UNKNOWN_EXCEPTIONS)
 /* 4.1 */
#  if defined(PANTHEIOS_EXTRAS_MAIN_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
#   error Define at most one of PANTHEIOS_EXTRAS_MAIN_CATCHALL_ABSORB_UNKNOWN_EXCEPTIONS and PANTHEIOS_EXTRAS_MAIN_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS
#  endif

# elif defined (PANTHEIOS_EXTRAS_MAIN_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
/* 4.2 */
#  if defined(PANTHEIOS_EXTRAS_MAIN_CATCHALL_ABSORB_UNKNOWN_EXCEPTIONS)
#   error Define at most one of PANTHEIOS_EXTRAS_MAIN_CATCHALL_ABSORB_UNKNOWN_EXCEPTIONS and PANTHEIOS_EXTRAS_MAIN_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS
#  endif

# else /* PANTHEIOS_EXTRAS_MAIN_CATCHALL_ABSORB_UNKNOWN_EXCEPTIONS || PANTHEIOS_EXTRAS_MAIN_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS */
/* 4.1 */

# endif /* PANTHEIOS_EXTRAS_MAIN_CATCHALL_ABSORB_UNKNOWN_EXCEPTIONS || PANTHEIOS_EXTRAS_MAIN_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS */

#endif /* PANTHEIOS_EXTRAS_MAIN_USE_CATCHALL */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

namespace pantheios
{
namespace extras
{
namespace main
{

/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION

namespace ximpl_invoke
{
    // TODO: put these workers in an 'internal' file ?

    struct invoker
    {
    public:
        virtual int invoke() = 0;
    };

    struct main_invoker
        : public invoker
    {
    public: // Construction
        main_invoker(
            int                 argc
        ,   char const* const*  argv
        ,   int (STLSOFT_CDECL* pfnMain)(int, char const* const*)
        )
            : argc(argc)
            , argv(argv)
            , pfnMain(pfnMain)
        {}
    private:
        main_invoker(main_invoker const& ); // proscribed
        void operator =(main_invoker const& ); // proscribed

    public: // Overriddes
        /* virtual */ int invoke()
        {
            return (*pfnMain)(argc, argv);
        }

    private: // Fields
        int const                 argc;
        char const* const* const  argv;
        int (STLSOFT_CDECL* const pfnMain)(int, char const* const*);
    };

# ifdef PANTHEIOS_USE_WIDE_STRINGS
    struct wmain_invoker
        : public invoker
    {
    public: // Construction
        wmain_invoker(
            int                     argc
        ,   wchar_t const* const*   argv
        ,   int     (STLSOFT_CDECL* pfnMain)(int, wchar_t const* const*)
        )
            : argc(argc)
            , argv(argv)
            , pfnMain(pfnMain)
        {}
    private:
        wmain_invoker(main_invoker const& ); // proscribed
        void operator =(wmain_invoker const& ); // proscribed

    public: // Overriddes
        /* virtual */ int invoke()
        {
            return (*pfnMain)(argc, argv);
        }

    private: // Fields
        int const                     argc;
        wchar_t const* const* const   argv;
        int     (STLSOFT_CDECL* const pfnMain)(int, wchar_t const* const*);
    };
# endif /* PANTHEIOS_USE_WIDE_STRINGS */


    inline
    void
    log_sas_1_impl_(
        int                 severity
    ,   PAN_CHAR_T const*   s
    ,   size_t              n
    )
    {
        pantheios::pan_slice_t slice(s, n);

        pantheios::core::pantheios_log_n(severity, 1u, &slice);
    }
    template <typename A0>
    void
    log_sas_1_(
        int                 severity
    ,   A0 const&           a0
    )
    {
        log_sas_1_impl_(
            severity
# ifdef PANTHEIOS_USE_WIDE_STRINGS
        ,   stlsoft_ns_qual(c_str_data_w)(a0)
        ,   stlsoft_ns_qual(c_str_len_w)(a0)
# else /* ? PANTHEIOS_USE_WIDE_STRINGS */
        ,   stlsoft_ns_qual(c_str_data_a)(a0)
        ,   stlsoft_ns_qual(c_str_len_a)(a0)
# endif /* PANTHEIOS_USE_WIDE_STRINGS */
        );
    }

    inline
    void
    conrep_exception_(
        int                 /* severity */
    ,   char const*         programName_m
    ,   char const*         msg
    ,   size_t const        msgLen
    )
    {
        if(NULL == programName_m)
        {
            fprintf(stderr, "%.*s\n", int(msgLen), msg);
        }
        else
        {
            STLSOFT_ASSERT('\0' != programName_m[0]);

            fprintf(stderr, "%s: %.*s\n", programName_m, int(msgLen), msg);
        }
    }

    inline
    void
    conrep_(
        int                 severity
    ,   char const*         programName_m
    ,   char const*         msg
    )
    {
        conrep_exception_(severity, programName_m, stlsoft_ns_qual(c_str_data_a)(msg), stlsoft_ns_qual(c_str_len_a)(msg));
    }

    // Following are DL+CR handlers for the three exception types:
    //
    // * out-of-memory
    // * (root) exception)
    // * catch-all
    //
    // and for Pantheios initialisation failure

    inline
    void
    on_pan_init_fail_(
        int                 severity
    ,   char const*         programName_m
    ,   char const*         reason
    )
    {
        pantheios::util::onBailOut(severity, "failed to initialise Pantheios diagnostic logging library", programName_m, reason);

        /* NOTE: Can this be removed, since pantheios_onBailOut4() writes to stderr? Only when pantheios_onBailOut4() include program name in stderr output. */
        if(NULL == programName_m)
        {
            fprintf(stderr, "failed to initialise program: failed to initialise Pantheios diagnostic logging library: %s\n", reason);
        }
        else
        {
            STLSOFT_ASSERT('\0' != programName_m[0]);

            fprintf(stderr, "%s: failed to initialise program: failed to initialise Pantheios diagnostic logging library: %s\n", programName_m, reason);
        }
    }

    inline
    void
    on_oom_(
        int                 severity
    ,   char const*         programName_m
    )
    {
        pantheios::logputs(severity, PANTHEIOS_LITERAL_STRING("out of memory"));

        conrep_(severity, programName_m, "out of memory");
    }

    inline
    void
    on_exception_(
        int                     severity
    ,   char const*             programName_m
    ,   std::exception const&   x
    )
    {
# ifdef PANTHEIOS_USE_WIDE_STRINGS
        log_sas_1_(severity, x);
# else /* ? PANTHEIOS_USE_WIDE_STRINGS */
        pantheios::logputs(severity, x.what());
# endif /* PANTHEIOS_USE_WIDE_STRINGS */

        conrep_exception_(
            severity
        ,   programName_m
        ,   stlsoft_ns_qual(c_str_data_a)(x)
        ,   stlsoft_ns_qual(c_str_len_a)(x)
        );
    }

# ifdef __AFX_H__
    inline
    void
    on_exception_(
        int                     severity
    ,   char const*             programName_m
    ,   CException const&       x
    )
    {
        log_sas_1_(severity, x);

        conrep_exception_(
            severity
        ,   programName_m
        ,   stlsoft_ns_qual(c_str_data_a)(x)
        ,   stlsoft_ns_qual(c_str_len_a)(x)
        );
    }
# endif /* __AFX_H__*/

    inline
    void
    on_catchall_(
        int                 severity
    ,   char const*         programName_m
    )
    {
        pantheios::logputs(severity, PANTHEIOS_LITERAL_STRING("unexpected unknown failure"));

        conrep_(severity, programName_m, "unexpected unknown failure");
    }


    inline
    int
    invoke_and_catch_(
        ximpl_invoke::invoker&  invoker
    ,   char const*             programName
    )
    {
        try
        {
            return invoker.invoke();
        }
        catch(std::bad_alloc&)
        {
            on_oom_(PANTHEIOS_SEV_ALERT, programName);
        }
# ifdef __AFX_H__
        catch(CMemoryException* px)
        {
            px->Delete();

            on_oom_(PANTHEIOS_SEV_ALERT, programName);
        }
# endif /* __AFX_H__*/
        catch(std::exception& x)
        {
            on_exception_(PANTHEIOS_SEV_ALERT, programName, x);
        }
# ifdef __AFX_H__
        catch(CException* px)
        {
            struct CException_deleter
            {
            public:
                CException_deleter(CException* px)
                    : m_px(px)
                {}
                ~CException_deleter() throw()
                {
                    m_px->Delete();
                }
            private:
                CException_deleter& operator =(CException_deleter const&)
                {   return *this;   }

            private:
                CException* const m_px;
            } instance(px);

            on_exception_(PANTHEIOS_SEV_ALERT, programName, *px);
        }
# endif /* __AFX_H__*/
# ifdef PANTHEIOS_EXTRAS_MAIN_USE_CATCHALL
        catch(...)
        {
            on_catchall_(PANTHEIOS_SEV_EMERGENCY, programName);

            // In general, the only sensible reaction to receipt of an
            // unknown exception is to die immediately. Since invoke()
            // is (or should be) the outermost scope of the program, we
            // do not need to forcibly invoke exit, as that's just about 
#  if defined(PANTHEIOS_EXTRAS_MAIN_CATCHALL_ABSORB_UNKNOWN_EXCEPTIONS)
            ;
#  elif defined(PANTHEIOS_EXTRAS_MAIN_CATCHALL_RETHROW_UNKNOWN_EXCEPTIONS)
            throw;
#  else
            pantheios::core::exitProcess(EXIT_FAILURE);
#  endif
        }
# endif /* PANTHEIOS_EXTRAS_MAIN_USE_CATCHALL */

        return EXIT_FAILURE;
    }

    inline
    int
    init_and_invoke_(
        ximpl_invoke::invoker&  invoker
    ,   char const*             programName_inferred
    ,   char const*             programName_given
    )
    {
        // Tasks:
        //
        // 1. Initialise Pantheios
        // 2. Invoke real "main()", and handle failure(s)
        //
        // Notes: Even though Pantheios in C++ mode will likely already have
        // been initialised, we do so again because it is benign to repeat
        // it, and horrible if it's been suspended for some reason.

        int r = pantheios::init();

        if(r < 0)
        {
            char const* const reason = pantheios::getInitCodeString(r);

            on_pan_init_fail_(PANTHEIOS_SEV_ALERT, programName_inferred, reason);

            return EXIT_FAILURE;
        }
        else
        {
            stlsoft::scoped_handle<void>  scoper1(pantheios::uninit);

            if(NULL == programName_given)
            {
                PAN_CHAR_T const* const programName = pantheios_getProcessIdentity();

# ifdef PANTHEIOS_USE_WIDE_STRINGS
                char    programName_m[1001];
#  ifdef PANTHEIOS_USING_SAFE_STR_FUNCTIONS
                size_t  cch;
                if(0 == ::wcstombs_s(&cch, programName_m, STLSOFT_NUM_ELEMENTS(programName_m), programName, STLSOFT_NUM_ELEMENTS(programName_m) - 1u))
#  else /* ? PANTHEIOS_USING_SAFE_STR_FUNCTIONS */
                size_t  cch = ::wcstombs(programName_m, programName, STLSOFT_NUM_ELEMENTS(programName_m) - 1u);

                if(static_cast<size_t>(-1) != cch)
#  endif /* PANTHEIOS_USING_SAFE_STR_FUNCTIONS */
                {
                    programName_m[cch] = '\0';

                    return invoke_and_catch_(invoker, programName_m);
                }

# else /* ? PANTHEIOS_USE_WIDE_STRINGS */

                programName_inferred = programName;

# endif /* PANTHEIOS_USE_WIDE_STRINGS */
            }

            return invoke_and_catch_(invoker, programName_inferred);
        }
    }

    inline
    int
    verify_name_and_invoke_m_(
        ximpl_invoke::invoker&  invoker
    ,   char const*             programName
    ,   char const*             arg0
    )
    {
        char const* const programName_given = programName;

        if(NULL == programName)
        {
            if(NULL != arg0) // this check only in case conversion from wide fails
            {
# if STLSOFT_LEAD_VER >= 0x010a0000
                programName = platformstl_ns_qual(get_executable_name_from_path)(arg0).ptr;
# else
                programName = arg0;
# endif
            }
        }

        return init_and_invoke_(invoker, programName, programName_given);
    }

    inline
    int
    prepare_invoker_m_(
        int                 argc
    ,   char const* const*  argv
    ,   int (STLSOFT_CDECL* pfnMain)(int, char const* const*)
    ,   char const*         programName
    )
    {
        ximpl_invoke::main_invoker  invoker(argc, argv, pfnMain);

        if( NULL != programName &&
            '\0' == programName[0])
        {
            programName = NULL;
        }

        return verify_name_and_invoke_m_(invoker, programName, argv[0]);
    }

    inline
    int
    prepare_invoker_m_(
        int                 argc
    ,   char**              argv
    ,   int (STLSOFT_CDECL* pfnMain)(int, char**)
    ,   char const*         programName
    )
    {
        return prepare_invoker_m_(argc, argv, reinterpret_cast<int (STLSOFT_CDECL*)(int, char const* const*)>(pfnMain), programName);
    }


# ifdef PANTHEIOS_USE_WIDE_STRINGS

    inline
    int
    prepare_invoker_w_(
        int                     argc
    ,   wchar_t const* const*   argv
    ,   int (STLSOFT_CDECL*     pfnMain)(int, wchar_t const* const*)
    ,   char const*             programName
    )
    {
        ximpl_invoke::wmain_invoker invoker(argc, argv, pfnMain);

        if( NULL != programName &&
            '\0' == programName[0])
        {
            programName = NULL;
        }

        if(NULL != programName)
        {
            return verify_name_and_invoke_m_(invoker, programName, NULL);
        }
        else
        {
            wchar_t const* const    arg0    =   argv[0];
            char                    arg0_[1 + _MAX_PATH];
#  ifdef PANTHEIOS_USING_SAFE_STR_FUNCTIONS
            size_t                  cch;
            if(0 == ::wcstombs_s(&cch, arg0_, STLSOFT_NUM_ELEMENTS(arg0_), arg0, STLSOFT_NUM_ELEMENTS(arg0_) - 1u))
#  else /* ? PANTHEIOS_USING_SAFE_STR_FUNCTIONS */
            size_t const            cch     =   ::wcstombs(arg0_, arg0, STLSOFT_NUM_ELEMENTS(arg0_) - 1u);

            if(static_cast<size_t>(-1) != cch)
#  endif /* PANTHEIOS_USING_SAFE_STR_FUNCTIONS */
            {
                arg0_[cch] = '\0';

                return verify_name_and_invoke_m_(invoker, NULL, arg0_);
            }

            return verify_name_and_invoke_m_(invoker, NULL, NULL);
        }
    }

    inline
    int
    prepare_invoker_w_(
        int                     argc
    ,   wchar_t const* const*   argv
    ,   int (STLSOFT_CDECL*     pfnMain)(int, wchar_t const* const*)
    ,   wchar_t const*          programName
    )
    {
        if( NULL != programName &&
            '\0' == programName[0])
        {
            programName = NULL;
        }

        if(NULL != programName)
        {
            char    programName_m[1001];
#  ifdef PANTHEIOS_USING_SAFE_STR_FUNCTIONS
            size_t  cch;
            if(0 == ::wcstombs_s(&cch, programName_m, STLSOFT_NUM_ELEMENTS(programName_m), programName, STLSOFT_NUM_ELEMENTS(programName_m) - 1u))
#  else /* ? PANTHEIOS_USING_SAFE_STR_FUNCTIONS */
            size_t  cch = ::wcstombs(programName_m, programName, STLSOFT_NUM_ELEMENTS(programName_m) - 1u);

            if(static_cast<size_t>(-1) != cch)
#  endif /* PANTHEIOS_USING_SAFE_STR_FUNCTIONS */
            {
                programName_m[cch] = '\0';

                return prepare_invoker_w_(argc, argv, pfnMain, programName_m);
            }
        }

        return prepare_invoker_w_(argc, argv, pfnMain, static_cast<char const*>(NULL));
    }

    inline
    int
    prepare_invoker_w_(
        int                     argc
    ,   wchar_t**               argv
    ,   int (STLSOFT_CDECL*     pfnMain)(int, wchar_t**)
    ,   wchar_t const*          programName
    )
    {
        return prepare_invoker_w_(argc, argv, reinterpret_cast<int (STLSOFT_CDECL*)(int, wchar_t const* const*)>(pfnMain), programName);
    }

# endif /* PANTHEIOS_USE_WIDE_STRINGS */

} /* namespace ximpl_invoke */

#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

/** Invokes the given <code>main()</code>-like function within the scope of
 * initialisation/uninitialisation of the Pantheios library, catching
 * any exceptions and translating them into diagnostic log statements
 * (using Pantheios' logging API) and contingent action (to stderr).
 *
 * Consider the following example:
\htmlonly
<pre>
  int <strong>main0</strong>(int argc, char const* const* argv)
  {
    . . . // your "real" main()
  }
  int main((int argc, char** argv)
  {
    return <strong>::pantheios::extras::main::invoke</strong>(argc, argv, main0, "myprogram");
  }
</pre>
\endhtmlonly
 *
 * \param argc The <code>argc</code> parameter of <code>main()</code>.
 * \param argv The <code>argv</code> parameter of <code>main()</code>.
 * \param pfnMain The <code>main()</code>-like function to be invoked.
 * \param programName Optional program name. May be <code>NULL</code>.
 *
 * \return <code>EXIT_FAILURE</code> if the Pantheios library cannot be
 *   initialised; otherwise, the return value of <code>pfnMain</code>.
 *
 * \pre (NULL != argv)
 * \pre (NULL != pfnMain)
 */
inline
int
invoke(
    int                 argc
,   char const* const*  argv
,   int (STLSOFT_CDECL* pfnMain)(int, char const* const*)
,   char const*         programName
)
{
    return ximpl_invoke::prepare_invoker_m_(argc, argv, pfnMain, programName);
}

/** Invokes the given <code>main()</code>-like function within the scope of
 * initialisation/uninitialisation of the Pantheios library, catching
 * any exceptions and translating them into diagnostic log statements
 * (using Pantheios' logging API) and contingent action (to stderr).
 *
 * Consider the following example:
\htmlonly
<pre>
  int <strong>main0</strong>(int argc, char** argv)
  {
    . . . // your "real" main()
  }
  int main((int argc, char** argv)
  {
    return <strong>::pantheios::extras::main::invoke</strong>(argc, argv, main0, "myprogram");
  }
</pre>
\endhtmlonly
 *
 * \param argc The <code>argc</code> parameter of <code>main()</code>.
 * \param argv The <code>argv</code> parameter of <code>main()</code>.
 * \param pfnMain The <code>main()</code>-like function to be invoked.
 * \param programName Optional program name. May be <code>NULL</code>.
 *
 * \return <code>EXIT_FAILURE</code> if the Pantheios library cannot be
 *   initialised; otherwise, the return value of <code>pfnMain</code>.
 *
 * \pre (NULL != argv)
 * \pre (NULL != pfnMain)
 */
inline
int
invoke(
    int                 argc
,   char**              argv
,   int (STLSOFT_CDECL* pfnMain)(int, char**)
,   char const*         programName
)
{
    return ximpl_invoke::prepare_invoker_m_(argc, argv, pfnMain, programName);
}

/** Invokes the given <code>main()</code>-like function within the scope of
 * initialisation/uninitialisation of the Pantheios library, catching
 * any exceptions and translating them into diagnostic log statements
 * (using Pantheios' logging API) and contingent action (to stderr).
 *
 * Consider the following example:
\htmlonly
<pre>
  extern "C" PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = "myprogram";

  int <strong>main0</strong>(int argc, char const* const* argv)
  {
    . . . // your "real" main()
  }
  int main((int argc, char** argv)
  {
    return <strong>::pantheios::extras::main::invoke</strong>(argc, argv, main0);
  }
</pre>
\endhtmlonly
 *
 * \param argc The <code>argc</code> parameter of <code>main()</code>.
 * \param argv The <code>argv</code> parameter of <code>main()</code>.
 * \param pfnMain The <code>main()</code>-like function to be invoked.
 *
 * \return <code>EXIT_FAILURE</code> if the Pantheios library cannot be
 *   initialised; otherwise, the return value of <code>pfnMain</code>.
 *
 * \pre (NULL != argv)
 * \pre (NULL != pfnMain)
 */
inline
int
invoke(
    int                 argc
,   char const* const*  argv
,   int (STLSOFT_CDECL* pfnMain)(int, char const* const*)
)
{
    return ximpl_invoke::prepare_invoker_m_(argc, argv, pfnMain, NULL);
}

/** Invokes the given <code>main()</code>-like function within the scope of
 * initialisation/uninitialisation of the Pantheios library, catching
 * any exceptions and translating them into diagnostic log statements
 * (using Pantheios' logging API) and contingent action (to stderr).
 *
 * Consider the following example:
\htmlonly
<pre>
  extern "C" PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = "myprogram";

  int <strong>main0</strong>(int argc, char** argv)
  {
    . . . // your "real" main()
  }
  int main((int argc, char** argv)
  {
    return <strong>::pantheios::extras::main::invoke</strong>(argc, argv, main0);
  }
</pre>
\endhtmlonly
 *
 * \param argc The <code>argc</code> parameter of <code>main()</code>.
 * \param argv The <code>argv</code> parameter of <code>main()</code>.
 * \param pfnMain The <code>main()</code>-like function to be invoked.
 *
 * \return <code>EXIT_FAILURE</code> if the Pantheios library cannot be
 *   initialised; otherwise, the return value of <code>pfnMain</code>.
 *
 * \pre (NULL != argv)
 * \pre (NULL != pfnMain)
 */
inline
int
invoke(
    int                 argc
,   char**              argv
,   int (STLSOFT_CDECL* pfnMain)(int, char**)
)
{
    return ximpl_invoke::prepare_invoker_m_(argc, argv, pfnMain, NULL);
}


/* /////////////////////////////////////////////////////////////////////////
 * widestring forms
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# ifdef PANTHEIOS_USE_WIDE_STRINGS

inline
int
invoke(
    int                     argc
,   wchar_t const* const*   argv
,   int (STLSOFT_CDECL*     pfnMain)(int, wchar_t const* const*)
,   wchar_t const*          programName
)
{
    return ximpl_invoke::prepare_invoker_w_(argc, argv, pfnMain, programName);
}

inline
int
invoke(
    int                 argc
,   wchar_t**           argv
,   int (STLSOFT_CDECL* pfnMain)(int, wchar_t**)
,   wchar_t const*      programName
)
{
    return ximpl_invoke::prepare_invoker_w_(argc, argv, pfnMain, programName);
}

inline
int
invoke(
    int                     argc
,   wchar_t const* const*   argv
,   int (STLSOFT_CDECL*     pfnMain)(int, wchar_t const* const*)
)
{
    return ximpl_invoke::prepare_invoker_w_(argc, argv, pfnMain, static_cast<char const*>(NULL));
}

inline
int
invoke(
    int                 argc
,   wchar_t**           argv
,   int (STLSOFT_CDECL* pfnMain)(int, wchar_t**)
)
{
    return ximpl_invoke::prepare_invoker_w_(argc, argv, pfnMain, NULL);
}

# endif /* PANTHEIOS_USE_WIDE_STRINGS */
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

} // namespace main
} // namespace extras
} // namespace pantheios

/* /////////////////////////////////////////////////////////////////////////
 * inclusion
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !PANTHEIOS_EXTRAS_MAIN_INCL_PANTHEIOS_EXTRAS_MAIN_HPP_INVOKE */

/* ///////////////////////////// end of file //////////////////////////// */
