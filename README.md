# Tunitas Basics

This repository contains the basic data structures and utilities used throughout the Tunitas family of projects.

The main body of documentation for the Tunitas family of components and services can be found 
on the [wiki](https://wiki.tunitas.technology/), the [web](https://www.tunitas.technology/),
also with the
[packaging](https://git.tunitas.technology/build/packaging.git)[upstream](https://github.com/yahoo/tunitas-packaging)
and with the build system
[temerarious-flagship](https://git.tunitas.technology/build/temerarious-flagship.git)[upstream](https://github.com/yahoo/temerarious-flagship]).
The overview and administrative declarations herein are necessarily summary in nature.
The declarations and definitions in the packaging and build system areas are complete and should be interpreted as superceding these when the two are in conflict.

Current work with modern-generation tooling, <em>e.g.</em> circa Fedora 36+ and GCC 12+, is occurring around the <em>v2-themed</em> feature branches.
## Table of Contents

- [Background](#background)
- [Dependencies](#dependencies)
- [Installation](#installation)
- [Configuration](#configuration)
- [Build](#build)
- [Usage](#usage)
- [Security](#security)
- [Contribute](#contribute)
- [License](#license)
- [Origin of the Name](#Origin_of_the_name)

## Background

The _basics_ package provides common code which is used in client side (command-line or batch operations) as well as common server-side code.  The components are organized according to namespace and segregated into separate libraries.  These are typically delivered as shared libraries (DSOs) but may be built as static libraries (archives).

## Dependencies

The [configuration](#configuration) step will check for many but not all required packages and operating system features.  There is a list of known
[package dependencies](https://git.tunitas.technology/components/basics/tree/master/PACKAGES.md)[upstream](https://github.com/yahoo/tunitas-basics/blob/master/PACKAGES.md)
which you will need to install beyond your base operating system.

Generally, the dependencies are among:
- Certain other components of the Tunitas system; <em>e.g.</em> the [Temerarious Flagship](https://github.com/yahoo/temerarious-flagship).
- A modern C++ development environment; meaning C++23, C++2B, C++20, C++2a in descending order of preference.
- A recent Fedora 30+, or RHEL8+, but any reasonable recent Linux distro should suffice.

The Tunitas project was developed on Fedora 27 through Fedora <em>mid thirties</em> using GCC 7 and GCC 8 with `-fconcepts` and at least `-std=c++1z`.  The code has progressively been enhanced to use C++20 and CC++2b features as they become available.  More details on the development environment and the build system can be found in
[temerarious-flagship](https://git.tunitas.technology/build/temerarious-flagship/tree/master/README.md)[upstream](https://github.com/yahoo/temerarious-flagship/blob/master/README.md).

## Installation

You may install this repo and its dependents by running something approximating (choose one):

``` bash
git clone https://git.tunitas.technology/components/basics.git
git clone https://github.com/yahoo/tunitas-basics.git
```

This will create a directory called `tunitas-basics` and download the contents of this repo to it.

Alternatively, if your organization already has made available the packaged version, then the following recipe will install the service:

``` bash
sudo dnf install tunitas-basics
```

## Configuration

The build system is based upon [GNU Autotools](https://www.gnu.org/software/automake/manual/html_node/index.html).

The configuration of the repo consists of two steps which must be done once.
1. `./buildconf`
2. `./configure`

The first step performs some crude assessments of the build environment and creates the site-specific `configure'. Of course `configure --help` will explain the build options.  The general options to `configure` are widely [documented](https://www.gnu.org/prep/standards/html_node/Configuration.html).

The `buildconf` component is boilerplate and can be updated from 
[temerarious-flagship](https://git.tunitas.technology/build/temerarious-flagship/tree/master/bc/template.autotools-buildconf)
[upstream](https://github.com/yahoo/temerarious-flagship/blob/master/bc/template.autotools-buildconf)
as needed.  The 
[Tunitas Build System](https://git.tunitas.technology/build/temerarious-flagship.git)[upstream](https://github.com/yahoo/temerarious-flagship)
should be available in `/opt/tunitas` and the template at `/opt/tunitas/share/temerarious-flagship/bc/template.autotools-buildconf`

## Build

To build and install this project, use the recipe shown following.  This will install the build system into `/opt/tunitas.`

``` bash
./buildconf &&
./configure &&
make &&
make check &&
make install &&
echo OK DONE
```

A shortcut is `./maintenance/nearby` which is not documented here.

## Usage

To compile with the Tunitas components the relevant compiler options are expected.
The `Makefile.am` of the other Tunitas-family packages contain appropriate settings.  These settings are enumerated in the following table:

| Variable | Default Value | Acceptable
| --- | --- |
| CPPFLAGS | -I/opt/tunitas/modules -I/opt/tunitas/include | |
| CXXFLAGS | -std=c++20 -fconcepts | -std=c++da -fconcepts |
| LDFLAGS | -L/opt/tunitas/lib64 -ltunitas | |

### Catalog of Components

A summary
[catalog of components](https://git.tunitas.technology/components/basics/Catalog-of-Components.md)[upstream](https://github.com/yahoo/tunitas-basics/Catalog-of-Components.md)
is provided separately.

### The Libraries

Static and DSO forms are built.

Their construction follows the best practices defined in Ulrich Drepper's opus [How To Write Shared Libraries](https://software.intel.com/sites/default/files/m/a/1/e/dsohowto.pdf), 2011-12-10 (47 pages).

### C++ and C++20

The Tunitas projects use C++23, C++2b, C++20, C++2a in descending order and any experimental extensions which are as close to the limit of the language as the tooling will allow.
Especially of interest are the language extensions supporting the Concepts, Ranges and Modules TS.
These are described in published language documentations such as [C++ Experimental Features](https://en.cppreference.com/w/cpp/experimental).
Where the language elements are "not ready" then polyfill has occurred with "script kiddies" or other tooling crutches are supplied as necessary.

More details can be found in the documentation for the build system,
[temerarious-flagship](https://git.tunitas.technology/build/temerarious-flagship.git)[upstream](https://github.com/yahoo/temerarious-flagship).

## Contribute

Please refer to
[contribution cinstructions](https://git.tunitas.technology/components/basics/tree/master/Contributing.md)[upstream](https://github.com/yahoo/tunias-basics/blob/master/Contributing.md)
for information about how to get involved. We welcome issues, questions, and pull requests. Pull Requests are welcome.

## Maintainers
- Wendell Baker <wbaker@yahooinc.com>
- The Tunitas Team at Yahoo.

You may contact us at least at <tunitas@yahooinc.com>

## Security

There are no special security concerns in the components of this repository.

## License

This project is licensed under the terms of the [Apache 2.0](LICENSE-Apache-2.0) open source license.
Please refer to
[LICENSE](https://git.tunitas.technology/components/basics/tree/master/LICENSE)[upstream](https://github.com/yahoo/tunitas-basics/blob/master/LICENSE)
for the full terms.

## Origin Of The Name

Tunitas is a [creek](https://en.wikipedia.org/wiki/Tunitas_Creek) and also a small [unincorporated portion](https://en.wikipedia.org/wiki/Tunitas,_California) of San Mateo County, California.
