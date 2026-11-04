# Pantheios.Extras.Main <!-- omit in toc -->

Git access to the [Pantheios](http://pantheios.org/) **Extras** library **Pantheios.Extras.Main**, which provides a suite of functions that simplify the implementation of ```main()```, including:
 - (un)initialisation of Pantheios library; and
 - catching of unhandled exceptions and issuing of diagnostic log statements and contingent reports

![C/C++](https://img.shields.io/badge/C%2FC%2B%2B-00599C?style=flat&logo=c%2B%2B&logoColor=white)
[![License](https://img.shields.io/badge/License-BSD_3--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)
[![GitHub release](https://img.shields.io/github/v/release/synesissoftware/Pantheios.Extras.Main.svg)](https://github.com/synesissoftware/Pantheios.Extras.Main/releases/latest)
[![Last Commit](https://img.shields.io/github/last-commit/synesissoftware/Pantheios.Extras.Main)](https://github.com/synesissoftware/Pantheios.Extras.Main/commits/master)
[![CI](https://github.com/synesissoftware/Pantheios.Extras.Main/actions/workflows/ci.yml/badge.svg)](https://github.com/synesissoftware/Pantheios.Extras.Main/actions/workflows/ci.yml)


## Table of Contents <!-- omit in toc -->

- [Introduction](#introduction)
- [Developer Experience](#developer-experience)
- [Installation](#installation)
- [Components](#components)
  - [C API / core library](#c-api--core-library)
  - [C++ API](#c-api)
- [Examples](#examples)
- [Project Information](#project-information)
  - [Where to get help](#where-to-get-help)
  - [Contribution guidelines](#contribution-guidelines)
  - [Dependencies](#dependencies)
    - [Development dependencies](#development-dependencies)
  - [Related projects](#related-projects)
  - [License](#license)


## Introduction

**Pantheios.Extras.Main** invokes a program's `main` (and `wmain` / MFC entry points) inside Pantheios initialisation and uninitialisation, and reports unhandled exceptions.


## Developer Experience

**STLSoft** 1.11.5 and **Pantheios** 1.0.1 must already be installed (or visible to CMake). The shortest build is:

```bash
./prepare_cmake.sh
./build_cmake.sh
```

```cpp
#include <pantheios/extras/main.hpp>
#include <stdlib.h>

extern "C" char const PANTHEIOS_FE_PROCESS_IDENTITY[] = "myprogram";

int main0(int argc, char* argv[])
{
    return EXIT_SUCCESS;
}

int main(int argc, char* argv[])
{
    return pantheios::extras::main::invoke(argc, argv, main0);
}
```

Further build and install paths are in [INSTALL.md](./INSTALL.md).


## Installation

Detailed instructions - via **CMake**, via bundling, via custom makefile
parameters - are provided in the accompanying [INSTALL.md](./INSTALL.md)
file.


## Components

### C API / core library

```C
int
pantheios_extras_main_invoke(
    int         argc
,   char*       argv[]
,   int       (*pfnMain)(int, char*[])
,   char const* programName
,   void*       reserved
);
```


### C++ API

```C
int
invoke(
    int                 argc
,   char*               argv[]
,   int (STLSOFT_CDECL* pfnMain)(int, char*[])
,   char const*         programName
);

int
invoke(
    int                 argc
,   char*               argv[]
,   int (STLSOFT_CDECL* pfnMain)(int, char*[])
);
```


## Examples

Examples are provided in the ```examples``` directory, along with a markdown description for each.


## Project Information

### Where to get help

[GitHub Page](https://github.com/synesissoftware/Pantheios.Extras.Main "GitHub Page")


### Contribution guidelines

Defect reports, feature requests, and pull requests are welcome on https://github.com/synesissoftware/Pantheios.Extras.Main.


### Dependencies

* [b64](http://github.com/synesissoftware/b64/) (optional);
* [Pantheios](http://github.com/synesissoftware/Pantheios/);
* [STLSoft 1.11](http://github.com/synesissoftware/STLSoft/);


#### Development dependencies

* [xTests](http://github.com/synesissoftware/xTests/);


### Related projects

Projects in which **Pantheios.Extras.Main** is used include:

T.B.C.


Projects in which **Pantheios.Extras.Main** is used for testing include:

T.B.C.


### License

**Pantheios.Extras.Main** is released under the 3-clause BSD license. See [LICENSE](./LICENSE) for details.


<!-- ########################### end of file ########################### -->

