/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.cpp.main.1.cpp
 *
 * Purpose: Implementation file for the test.unit.cpp.main.1 library.
 *
 * Created: 11th January 2011
 * Updated: 24th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * feature control
 */

#define PANTHEIOS_EXTRAS_MAIN_USE_CATCHALL


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* /////////////////////////////////////
 * hook includes
 */

#include <stdio.h>

namespace pantheios {

namespace util {

    template<
        typename T0
    ,   typename T1
    ,   typename T2
    ,   typename T3
    >
    void onBailOut_stub(
        T0 const&
    ,   T1 const&
    ,   T2 const&
    ,   T3 const&
    )
    {}

    template<
        typename T0
    ,   typename T1
    ,   typename T2
    >
    void onBailOut_stub(
        T0 const&
    ,   T1 const&
    ,   T2 const&
    )
    {}
} /* namespace util */
} /* namespace pantheios */

namespace
{

    static FILE* stderr_stub = NULL;
} /* anonymous namespace */

#include <pantheios/pantheios.h>

# define onBailOut                                          onBailOut_stub
# ifdef stderr
#  undef stderr
# endif
# define stderr                                             stderr_stub


/* /////////////////////////////////////
 * test component header file include(s)
 */

#include <pantheios/extras/main.hpp>


/* /////////////////////////////////////
 * general includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/smartptr/scoped_handle.hpp>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

extern "C" {

    void test_throw_int_NO_CATCHALL(void);
    void test_throw_int_USE_CATCHALL(void);
#ifdef PANTHEIOS_USE_WIDE_STRINGS

    void test_throw_int_NO_CATCHALL_w(void);
    void test_throw_int_USE_CATCHALL_w(void);
#endif /* PANTHEIOS_USE_WIDE_STRINGS */
} /* extern "C" */

namespace
{

  static void test_returns_EXIT_SUCCESS(void);
  static void test_returns_EXIT_FAILURE(void);
  static void test_throws_std_runtime_error(void);
  static void test_throws_std_bad_alloc(void);
#ifdef PANTHEIOS_USE_WIDE_STRINGS

  static void test_returns_EXIT_SUCCESS_w(void);
  static void test_returns_EXIT_FAILURE_w(void);
  static void test_throws_std_runtime_error_w(void);
  static void test_throws_std_bad_alloc_w(void);
#endif /* PANTHEIOS_USE_WIDE_STRINGS */
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * Constants & Globals
 */

extern "C" PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.unit.cpp.main.1");

static char const STUB_FILE_NAME[] = "test.unit.cpp.main.1.stub_file";


/* /////////////////////////////////////////////////////////////////////////
 * main
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    stderr_stub = ::fopen(STUB_FILE_NAME, "w");

    stlsoft::scoped_handle<char const*> scoper_file(STUB_FILE_NAME, ::remove);
    stlsoft::scoped_handle<FILE*>       scoper_file_handle(stderr_stub, ::fclose);

    if (XTESTS_START_RUNNER("test.unit.cpp.main.1", verbosity))
    {
        XTESTS_RUN_CASE(test_returns_EXIT_SUCCESS);
        XTESTS_RUN_CASE(test_returns_EXIT_FAILURE);
        XTESTS_RUN_CASE(test_throws_std_runtime_error);
        XTESTS_RUN_CASE(test_throws_std_bad_alloc);
        XTESTS_RUN_CASE(test_throw_int_NO_CATCHALL);
        XTESTS_RUN_CASE(test_throw_int_USE_CATCHALL);
#ifdef PANTHEIOS_USE_WIDE_STRINGS

        XTESTS_RUN_CASE(test_returns_EXIT_SUCCESS_w);
        XTESTS_RUN_CASE(test_returns_EXIT_FAILURE_w);
        XTESTS_RUN_CASE(test_throws_std_runtime_error_w);
        XTESTS_RUN_CASE(test_throws_std_bad_alloc_w);
        XTESTS_RUN_CASE(test_throw_int_NO_CATCHALL_w);
        XTESTS_RUN_CASE(test_throw_int_USE_CATCHALL_w);
#endif /* PANTHEIOS_USE_WIDE_STRINGS */

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


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

namespace
{


static void test_returns_EXIT_SUCCESS()
{
    struct inner
    {
        static int fn(int argc, char** argv)
        {
            XTESTS_TEST_INTEGER_EQUAL(1, argc);
            XTESTS_TEST_MULTIBYTE_STRING_EQUAL("arg0", argv[0]);
            XTESTS_TEST_POINTER_EQUAL(NULL, argv[1]);

            return EXIT_SUCCESS;
        }
    };

    int r = pantheios::extras::main::invoke(argc, argv, &inner::fn);

    XTESTS_TEST_INTEGER_EQUAL(EXIT_SUCCESS, r);
}

static void test_returns_EXIT_FAILURE()
{
    struct inner
    {
        static int fn(int, char**)
        {
          return EXIT_FAILURE;
        };
    };

    int r = pantheios::extras::main::invoke(argc, argv, &inner::fn);

    XTESTS_TEST_INTEGER_EQUAL(EXIT_FAILURE, r);
}

static void test_throws_std_runtime_error()
{
    struct inner
    {
        static int fn(int, char**)
        {
            throw std::runtime_error("oops");

            return EXIT_SUCCESS;
        };
    };

    int r = pantheios::extras::main::invoke(argc, argv, &inner::fn);

    XTESTS_TEST_INTEGER_EQUAL(EXIT_FAILURE, r);
}

static void test_throws_std_bad_alloc()
{
    struct inner
    {
        static int fn(int, char**)
        {
            throw std::bad_alloc();

            return EXIT_SUCCESS;
        };
    };

    int r = pantheios::extras::main::invoke(argc, argv, &inner::fn);

    XTESTS_TEST_INTEGER_EQUAL(EXIT_FAILURE, r);
}
#ifdef PANTHEIOS_USE_WIDE_STRINGS

static void test_returns_EXIT_SUCCESS_w()
{
    struct inner
    {
        static int fn(int argc, wchar_t* argv[])
        {
            XTESTS_TEST_INTEGER_EQUAL(1, argc);
            XTESTS_TEST_WIDE_STRING_EQUAL(L"arg0", argv[0]);
            XTESTS_TEST_POINTER_EQUAL(NULL, argv[1]);

            return EXIT_SUCCESS;
        }
    };

    int r = pantheios::extras::main::invoke(wargc, wargv, &inner::fn);

    XTESTS_TEST_INTEGER_EQUAL(EXIT_SUCCESS, r);
}

static void test_returns_EXIT_FAILURE_w()
{
    struct inner
    {
        static int fn(int, wchar_t* [])
        {
          return EXIT_FAILURE;
        };
    };

    int r = pantheios::extras::main::invoke(wargc, wargv, &inner::fn);

    XTESTS_TEST_INTEGER_EQUAL(EXIT_FAILURE, r);
}

static void test_throws_std_runtime_error_w()
{
    struct inner
    {
        static int fn(int, wchar_t* [])
        {
            throw std::runtime_error("oops");

            return EXIT_SUCCESS;
        };
    };

    int r = pantheios::extras::main::invoke(wargc, wargv, &inner::fn);

    XTESTS_TEST_INTEGER_EQUAL(EXIT_FAILURE, r);
}

static void test_throws_std_bad_alloc_w()
{
    struct inner
    {
        static int fn(int, wchar_t* [])
        {
            throw std::bad_alloc();

            return EXIT_SUCCESS;
        };
    };

    int r = pantheios::extras::main::invoke(wargc, wargv, &inner::fn);

    XTESTS_TEST_INTEGER_EQUAL(EXIT_FAILURE, r);
}
#endif /* PANTHEIOS_USE_WIDE_STRINGS */
} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

