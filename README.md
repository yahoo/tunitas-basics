The basic data structures and utilities used throughout the Tunitas family of projects.

# Language: C++

Using C++2a, C++2b, as close to the limit of the language as the tooling
will allow.  Especially focusing on Concepts, Ranges and Modules TS.

See [C++ Experimental Features](https://en.cppreference.com/w/cpp/experimental).

Where the language is "not ready" then polyfill with script kiddies or other tooling crutches are used.

# The Classes

## namespace tunitas



## namespace tunitas.exception

   * ```tunitas.exception.Quitting''' leave the application.

Namespace naming convention: singular (as in "an exception")

## namespace tunitas.option

   * ```tunitas.option.Args''' the analog of ```argv'''
   
Namespace naming convention: singular (as in "an option")

# The Libraries

Static and DSO forms.

Especially following the best practices defined in Ulrich Drepper's opus [How To Write Shared Libraries](https://software.intel.com/sites/default/files/m/a/1/e/dsohowto.pdf), 2011-12-10 (47 pages).
