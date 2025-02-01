/* /////////////////////////////////////////////////////////////////////////
 * File:    pantheios/extras/main/internal/common.h
 *
 * Purpose: Definition of common features header for the
 *          Pantheios.Extras.Main library.
 *
 * Created: 6th January 2011
 * Updated: 31st January 2025
 *
 * Home:    http://www.pantheios.org/
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2011-2019, Matthew Wilson and Synesis Software
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


/** \file pantheios/extras/main/internal/common.h
 * [C, C++] Definition of common features header for the
 *   \ref group__library__pantheios_extras_main "Pantheios.Extras.Main" library.
 */

#ifndef PANTHEIOS_EXTRAS_MAIN_INCL_PANTHEIOS_EXTRAS_MAIN_INTERNAL_H_COMMON
#define PANTHEIOS_EXTRAS_MAIN_INCL_PANTHEIOS_EXTRAS_MAIN_INTERNAL_H_COMMON

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# define PANTHEIOS_EXTRAS_MAIN_VER_PANTHEIOS_EXTRAS_MAIN_INTERNAL_H_COMMON_MAJOR    1
# define PANTHEIOS_EXTRAS_MAIN_VER_PANTHEIOS_EXTRAS_MAIN_INTERNAL_H_COMMON_MINOR    0
# define PANTHEIOS_EXTRAS_MAIN_VER_PANTHEIOS_EXTRAS_MAIN_INTERNAL_H_COMMON_REVISION 13
# define PANTHEIOS_EXTRAS_MAIN_VER_PANTHEIOS_EXTRAS_MAIN_INTERNAL_H_COMMON_EDIT     16
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <pantheios/pantheios.h>

#include <pantheios/extras/main/internal/stlsoft.h>


/* /////////////////////////////////////////////////////////////////////////
 * compatibility checks
 */

#if PANTHEIOS_VER < 0x010001de
# error Pantheios.Extras.Main required Pantheios 1.0.1 beta 221, or later
#endif /* !PANTHEIOS_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

/** \def PANTHEIOS_EXTRAS_MAIN_VER_MAJOR
 * The major version number of Pantheios.Extras.Main
 */

/** \def PANTHEIOS_EXTRAS_MAIN_VER_MINOR
 * The minor version number of Pantheios.Extras.Main
 */

/** \def PANTHEIOS_EXTRAS_MAIN_VER_REVISION
 * The revision version number of Pantheios.Extras.Main
 */

/** \def PANTHEIOS_EXTRAS_MAIN_VER
 * The current composite version number of Pantheios.Extras.Main
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# define PANTHEIOS_EXTRAS_MAIN_VER_0_1_1_ALPHA_1            0x00010101
# define PANTHEIOS_EXTRAS_MAIN_VER_0_1_1_ALPHA_2            0x00010102
# define PANTHEIOS_EXTRAS_MAIN_VER_0_1_1_ALPHA_3            0x00010103
# define PANTHEIOS_EXTRAS_MAIN_VER_0_1_1_ALPHA_4            0x00010104
# define PANTHEIOS_EXTRAS_MAIN_VER_0_1_1_ALPHA_5            0x00010105
# define PANTHEIOS_EXTRAS_MAIN_VER_0_1_1                    0x000101ff
# define PANTHEIOS_EXTRAS_MAIN_VER_0_1_2                    0x000102ff
# define PANTHEIOS_EXTRAS_MAIN_VER_0_1_3                    0x000103ff
# define PANTHEIOS_EXTRAS_MAIN_VER_0_2_0                    0x000200ff
# define PANTHEIOS_EXTRAS_MAIN_VER_0_2_1_ALPHA_1            0x00020141
# define PANTHEIOS_EXTRAS_MAIN_VER_0_2_1_ALPHA_2            0x00020142
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

#define PANTHEIOS_EXTRAS_MAIN_VER_MAJOR                     0
#define PANTHEIOS_EXTRAS_MAIN_VER_MINOR                     2
#define PANTHEIOS_EXTRAS_MAIN_VER_REVISION                  1

#define PANTHEIOS_EXTRAS_MAIN_VER                           PANTHEIOS_EXTRAS_MAIN_VER_0_2_1_ALPHA_2


/* /////////////////////////////////////////////////////////////////////////
 * inclusion
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !PANTHEIOS_EXTRAS_MAIN_INCL_PANTHEIOS_EXTRAS_MAIN_INTERNAL_H_COMMON */

/* ///////////////////////////// end of file //////////////////////////// */

