/* /////////////////////////////////////////////////////////////////////////
 * File:        pantheios/extras/main/internal/common.hpp
 *
 * Purpose:     Definition of common features header for the
 *              Pantheios.Extras.Main library for C++ compilation.
 *
 * Created:     6th January 2011
 * Updated:     17th January 2021
 *
 * Home:        http://www.pantheios.org/
 *
 * Copyright (c) 2019-2021, Matthew Wilson and Synesis Information Systems
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


/** \file pantheios/extras/main/internal/common.hpp
 * [C++] Definition of common features header for the
 *   \ref group__library__pantheios_extras_main "Pantheios.Extras.Main" library.
 */

#ifndef PANTHEIOS_EXTRAS_MAIN_INCL_PANTHEIOS_EXTRAS_MAIN_INTERNAL_HPP_COMMON
#define PANTHEIOS_EXTRAS_MAIN_INCL_PANTHEIOS_EXTRAS_MAIN_INTERNAL_HPP_COMMON

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# define PANTHEIOS_MAIN_EXTRAS_VER_PANTHEIOS_EXTRAS_MAIN_INTERNAL_HPP_COMMON_MAJOR    1
# define PANTHEIOS_MAIN_EXTRAS_VER_PANTHEIOS_EXTRAS_MAIN_INTERNAL_HPP_COMMON_MINOR    0
# define PANTHEIOS_MAIN_EXTRAS_VER_PANTHEIOS_EXTRAS_MAIN_INTERNAL_HPP_COMMON_REVISION 2
# define PANTHEIOS_MAIN_EXTRAS_VER_PANTHEIOS_EXTRAS_MAIN_INTERNAL_HPP_COMMON_EDIT     7
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <pantheios/extras/main/internal/common.h>

/* /////////////////////////////////////////////////////////////////////////
 * compatibility checks
 */

#if defined(PANTHEIOS_NO_NAMESPACE)
# error Pantheios.Extras.Main library does not (currently) support no-namespace operation
#endif /* !PANTHEIOS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

/** The <strong>Pantheios</strong> root namespace - <code>pantheios</code>.
 *
 * This namespace is used by the Pantheios main library.
 * <strong>Pantheios.Extras.Main</strong> elements are defined within the
 * <code>pantheios::extras::main</code> namespace
 */
namespace pantheios
{
/** The <strong>Pantheios::Extras</strong> root namespace - <code>pantheios::extras</code>.
 *
 * This namespace is used to contain all Pantheios::Extras projects.
 * <strong>Pantheios.Extras.Main</strong> elements are defined within the
 * <code>pantheios::extras::main</code> namespace
 */
namespace extras
{
/** The namespace used by the <strong>Pantheios.Extras.Main</strong>
 * library - <code>pantheios::extras::main</code>
 */
namespace main
{

} // namespace main
} // namespace extras
} // namespace pantheios

/* /////////////////////////////////////////////////////////////////////////
 * inclusion
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !PANTHEIOS_EXTRAS_MAIN_INCL_PANTHEIOS_EXTRAS_MAIN_INTERNAL_HPP_COMMON */

/* ///////////////////////////// end of file //////////////////////////// */

