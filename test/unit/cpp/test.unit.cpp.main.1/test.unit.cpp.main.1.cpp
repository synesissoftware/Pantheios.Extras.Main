/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.cpp.main.1.cpp
 *
 * Purpose:     Implementation file for the test.unit.cpp.main.1 library.
 *
 * Created:     11th January 2011
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


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <stdio.h>

namespace pantheios
{
namespace util
{
  
  template<
    typename T0
  , typename T1
  , typename T2
  , typename T3
  >
  void onBailOut_stub(
    T0 const&
  , T1 const&
  , T2 const&
  , T3 const&
  )
  {}
  
  template<
    typename T0
  , typename T1
  , typename T2
  >
  void onBailOut_stub(
    T0 const&
  , T1 const&
  , T2 const&
  )
  {}

} /* namespace util */
} /* namespace pantheios */

namespace
{
  static FILE* stderr_stub = NULL;

} /* anonymous namespace */


# define onBailOut    onBailOut_stub
# ifdef stderr
#  undef stderr
# endif
# define stderr       stderr_stub

#include <pantheios/extras/main.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

  static void test_1_0(void);
  static void test_1_1(void);
  static void test_1_2(void);
  static void test_1_3(void);
  static void test_1_4(void);
  static void test_1_5(void);
  static void test_1_6(void);
  static void test_1_7(void);
  static void test_1_8(void);
  static void test_1_9(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Constants & Globals
 */

extern "C" PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.unit.cpp.main.1");

static char const STUB_FILE_NAME[] = "test.unit.cpp.main.1.stub_file";

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
  int retCode = EXIT_SUCCESS;
  int verbosity = 2;

  XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

  stderr_stub = ::fopen(STUB_FILE_NAME, "w");

  if(XTESTS_START_RUNNER("test.unit.cpp.main.1", verbosity))
  {
    XTESTS_RUN_CASE(test_1_0);
    XTESTS_RUN_CASE(test_1_1);
    XTESTS_RUN_CASE(test_1_2);
    XTESTS_RUN_CASE(test_1_3);
    XTESTS_RUN_CASE(test_1_4);
    XTESTS_RUN_CASE(test_1_5);
    XTESTS_RUN_CASE(test_1_6);
    XTESTS_RUN_CASE(test_1_7);
    XTESTS_RUN_CASE(test_1_8);
    XTESTS_RUN_CASE(test_1_9);

    XTESTS_PRINT_RESULTS();

    XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
  }

  ::fclose(stderr_stub);

  ::remove(STUB_FILE_NAME);

  return retCode;
}

/* /////////////////////////////////////////////////////////////////////////
 * Test function implementations
 */

namespace
{

    static char*    args[]  =   { "arg0", NULL };
    static int      argc    =   STLSOFT_NUM_ELEMENTS(args) - 1;
    static char**   argv    =   args;


static void test_1_0()
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



static void test_1_1()
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



static void test_1_2()
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

static void test_1_3()
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

static void test_1_4()
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
    catch(int& x)
    {
        XTESTS_TEST_INTEGER_EQUAL(12345, x);
    }
}

static void test_1_5()
{
}

static void test_1_6()
{
}

static void test_1_7()
{
}

static void test_1_8()
{
}

static void test_1_9()
{
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
