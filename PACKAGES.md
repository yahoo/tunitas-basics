# Required Packages

This document contains an estimate of the tools, components their versions which you will need to build this repository.  More details can be found upstream in the the documentation for the lead repository, the Tunitas [Packaging](https://github.com/yahoo/tunitas-packaging/blob/master/PACKAGES.md), as well as the Tunitas Build System, [Temerarious Flagship](https://github.com/yahoo/temerarious-flagship/blob/master/README.md).  The mentions in this document pertain only to this repository, _Tunitas Basics_.

## Tunitas

* [tunitas-basics](https://github.com/yahoo/tunitas-basics) >= 2.0.0, common components of the Tunitas projects.
* [temerarious-flagship](https://github.com/yahoo/temerarious-flagship) >= 1.8.0, some build system components.

The lead repository for the Tunitas suite of services is [tunitas-packaging](https://github.com/yahoo/tunitas-packaging).

## Development Tooling

This is a C++ project.  The project approaches the upcoming C++23 standard, where available.<!-- if it's in the language or <em>gonna be in the language</em> then we use it, and so should you. -->

### C++ 2a, 20, 2b Compilers
* `gcc-c++` >= 11.0, get thee there.
* `gcc-c++` >= 10.3, expected.
* `gcc-c++` >= 9.3.1, possible through 2020-late, maybe, but probably not any more by the time you read this in 2021 & 2022.
* <strike>`gcc-c++` >= 8.2</strike>
* <strike>`gcc-c++` >= 7.2</strike>
* gcc-c++ with [C++ Modules TS](https://gcc.gnu.org/wiki/cxx-modules).

### Build Support
* The [GNU Autotools](https://www.gnu.org/software/automake/manual/html_node/index.html#Top)
    * `automake` >= 1.16
    * `autoconf` >= 2.69
    * `libtool` >= 2.4
    * `make` >= 4.2
* The Tunitas Build System
    * [temerarious-flagship](https://github.com/yahoo/temerarious-flagship) >= 1.6.0, some build system components.
    * As necessary, the individual [S.C.O.L.D.](https://www.scold-lang.org) [toolchain](https://git.scold-lang.org/core) and modules
        * [hypogeal-twilight](https://git.scold-lang.org/core/hypogeal-twilight) >= 0.45, fundamental build system components.
        * [incendiary-sophist](https://git.scold-lang.org/core/incendiary-sophist) >= 0.1, the test harness, is optional.
        * [anguish-answer](https://git.scold-lang.org/core/anguish-answer) >= 2.0, the preprocessor towards a [unitary build](https://mesonbuild.com/Unity-builds.html).
* `perl` prefer `perl` >= 5.28
    * and various perl modules, surely.
    * we work to remove other <em>mega-culture</em> IDE and interpreter systems from dependency chain of the build system; less perl and less python.<!-- autotools ... yeah we know, we've heard -->

##  Components

This section enumerates is a best-estimate abstraction of the component dependencies for [Tunitas Basics](https://github.com/yahoo/tunitas-basics).  A master list of dependencies for the Tunitas family of components and services can be found in the [packaging](https://github.com/yahoo/tunitas-packaging/blob/master/PACKAGES.md).

These packages are available via `dnf` or `yum`, if your machine is configured appropriately.

* `gcc-c++` >= 10.3
* `cppunit-devel` >= 1.14.0
* `jsoncpp-devel` >= 1.8.4

See the `addenda` directory or else see the separately-built & distributed packages: [json](https://git.scold-lang.org/modules/json), [nonstd](https://git.scold-lang.org/modules/nonstd), [options](https://git.scold-lang.org/modules/options), [posix](https://git.scold-lang.org/modules/posix), [std](https://git.scold-lang.org/modules/std), [string](https://git.scold-lang.org/modules/string), [sys](https://git.scold-lang.org/modules/sys); [cppunit](https://git.scold-lang.org/modules/cppunit), [rigging](https://git.scold-lang.org/modules/rigging).<!-- These will prune down in the future as certain of these packages collapse into fewer larger libraries -->

## Operating System

Development commenced on Fedora 27 and has continued across Fedora <em>late twenties</em> and into Fedora <em>mid-thirties</em>.

A recent Ubuntu should be fine.

## Availabilities

* [Fedora](https://getfedora.com)
    * Fedora 27-32, possible, but with appropriately modern `gcc-c++` <em>e.g.</em> GCC 10-series.
    * Fedora 33, available.
    * Fedora 34, current.
    * Fedora 35, get thee there.
* [Tunitas](https://github.com/yahoo/tunitas-packaging/blob/master/README.md)
    * <em>Release 01 (Famous Oak)</em>, current.
    * <em>Release 02 (Towering Redwood)</em>, forthcoming, the date is TBD.
* [S.C.O.L.D. C++](https://www.scold-lang.org) (Scalable Object Location Disaggregation)
    * <em>Release 02 (Maroon Iron Crow)</em>, possible.
    * <em>Release 03 (Red Mercury Goose)</em>, current
    * <em>Release 04 (Green Copper Heron)</em>, preferred.
