/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.cpp.main.1/test_throw_int_USE_CATCHALL.cpp
 *
 * Purpose: Unit-test of a variant of the `test_throw_int()` under the
 *          PANTHEIOS_EXTRAS_MAIN_USE_CATCHALL preprocessor option.
 *
 * Created: 24th October 2024
 * Updated: 24th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * feature control
 */

#define PANTHEIOS_EXTRAS_MAIN_USE_CATCHALL

// Need to #define all the functions in invoke.hpp, otherwise compiler optimisations and linker actions derail the distinct testing in this and peer files
#define conrep_                                             conrep___USE_CATCHALL__
#define conrep_exception_                                   conrep_exception___USE_CATCHALL__
#define init_and_invoke_                                    init_and_invoke___USE_CATCHALL__
#define invoke                                              invoke__USE_CATCHALL__
#define invoke_and_catch_                                   invoke_and_catch___USE_CATCHALL__
#define log_sas_1_impl_                                     log_sas_1_impl___USE_CATCHALL__
#define on_catchall_                                        on_catchall___USE_CATCHALL__
#define on_exception_                                       on_exception___USE_CATCHALL__
#define on_oom_                                             on_oom___USE_CATCHALL__
#define on_pan_init_fail_                                   on_pan_init_fail___USE_CATCHALL__
#define prepare_invoker_m_                                  prepare_invoker_m___USE_CATCHALL__
#define prepare_invoker_w_                                  prepare_invoker_w___USE_CATCHALL__
#define verify_name_and_invoke_m_                           verify_name_and_invoke_m___USE_CATCHALL__


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* /////////////////////////////////////
 * hook includes
 */

namespace pantheios {

namespace core {

    extern "C"
    void exitProcess_stub___NO_CATCHALL__(int sc);
} /* namespace core */
} /* namespace pantheios */

#include <pantheios/pantheios.h>

# define exitProcess                                        exitProcess_stub___NO_CATCHALL__


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
 * hook implementations
 */

namespace
{

    static int exit_status_stub = 0;
} /* anonymous namespace */

namespace pantheios {

namespace core {

    extern "C"
    void exitProcess_stub___NO_CATCHALL__(int sc)
    {
        exit_status_stub = sc;
    }
} /* namespace core */
} /* namespace pantheios */


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
void test_throw_int_USE_CATCHALL(void)
{
    struct inner
    {
        static int fn(int, char**)
        {
            throw 12345;

            return EXIT_SUCCESS;
        };
    };

    int r = pantheios::extras::main::invoke(argc, argv, &inner::fn);

    XTESTS_TEST_INTEGER_EQUAL(EXIT_FAILURE, r);

    XTESTS_TEST_INTEGER_EQUAL(EXIT_FAILURE, exit_status_stub);
}
#ifdef PANTHEIOS_USE_WIDE_STRINGS

extern "C"
void test_throw_int_USE_CATCHALL_w(void)
{
    struct inner
    {
        static int fn(int, wchar_t* [])
        {
            throw 12345;

            return EXIT_SUCCESS;
        };
    };

    int r = pantheios::extras::main::invoke(wargc, wargv, &inner::fn);

    XTESTS_TEST_INTEGER_EQUAL(EXIT_FAILURE, r);

    XTESTS_TEST_INTEGER_EQUAL(EXIT_FAILURE, exit_status_stub);
}
#endif /* PANTHEIOS_USE_WIDE_STRINGS */


/* ///////////////////////////// end of file //////////////////////////// */

