/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.cpp.main.1/test_throw_int_NO_CATCHALL.cpp
 *
 * Purpose: Unit-test of a variant of the `test_throw_int()` under the
 *          PANTHEIOS_EXTRAS_MAIN_NO_CATCHALL preprocessor option.
 *
 * Created: 24th October 2024
 * Updated: 24th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * feature control
 */

#define PANTHEIOS_EXTRAS_MAIN_NO_CATCHALL


// Need to #define all the functions in invoke.hpp, otherwise compiler optimisations and linker actions derail the distinct testing in this and peer files
#define conrep_                                             conrep___NO_CATCHALL__
#define conrep_exception_                                   conrep_exception___NO_CATCHALL__
#define init_and_invoke_                                    init_and_invoke___NO_CATCHALL__
#define invoke                                              invoke__NO_CATCHALL__
#define invoke_and_catch_                                   invoke_and_catch___NO_CATCHALL__
#define log_sas_1_impl_                                     log_sas_1_impl___NO_CATCHALL__
#define on_catchall_                                        on_catchall___NO_CATCHALL__
#define on_exception_                                       on_exception___NO_CATCHALL__
#define on_oom_                                             on_oom___NO_CATCHALL__
#define on_pan_init_fail_                                   on_pan_init_fail___NO_CATCHALL__
#define prepare_invoker_m_                                  prepare_invoker_m___NO_CATCHALL__
#define prepare_invoker_w_                                  prepare_invoker_w___NO_CATCHALL__
#define verify_name_and_invoke_m_                           verify_name_and_invoke_m___NO_CATCHALL__


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* /////////////////////////////////////
 * hook includes
 */

#include <pantheios/pantheios.h>


/* /////////////////////////////////////
 * test component header file include(s)
 */

#include <pantheios/extras/main.hpp>


/* /////////////////////////////////////
 * general includes
 */

/* xTests header files */
#include <xtests/xtests.h>


/* /////////////////////////////////////////////////////////////////////////
 * test data
 */

namespace
{

    static char*        args[]  =   { "arg0", NULL };
    static int          argc    =   STLSOFT_NUM_ELEMENTS(args) - 1;
    static char**       argv    =   args;
#ifdef PANTHEIOS_USE_WIDE_STRINGS

    static wchar_t*     wargs[] =   { L"arg0", NULL };
    static int          wargc   =   STLSOFT_NUM_ELEMENTS(wargs) - 1;
    static wchar_t**    wargv   =   wargs;
#endif /* PANTHEIOS_USE_WIDE_STRINGS */
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

extern "C"
void test_throw_int_NO_CATCHALL(void)
{
    struct inner
    {
        static int fn(int, char**)
        {
            throw 12345;

            return EXIT_SUCCESS;
        };
    };

    try
    {
        pantheios::extras::main::invoke(argc, argv, &inner::fn);

        XTESTS_TEST_FAIL("should not get here");
    }
    catch (int& x)
    {
        XTESTS_TEST_INTEGER_EQUAL(12345, x);
    }
}
#ifdef PANTHEIOS_USE_WIDE_STRINGS

extern "C"
void test_throw_int_NO_CATCHALL_w(void)
{
    struct inner
    {
        static int fn(int, wchar_t* [])
        {
            throw 12345;

            return EXIT_SUCCESS;
        };
    };

    try
    {
        pantheios::extras::main::invoke(wargc, wargv, &inner::fn);

        XTESTS_TEST_FAIL("should not get here");
    }
    catch (int& x)
    {
        XTESTS_TEST_INTEGER_EQUAL(12345, x);
    }
}
#endif /* PANTHEIOS_USE_WIDE_STRINGS */


/* ///////////////////////////// end of file //////////////////////////// */

