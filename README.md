[comment]: <> (this is really -*- markdown -*-)

The basic data structures and utilities used throughout the Tunitas family of projects.

# Language: C++

Using C++2a, C++2b, as close to the limit of the language as the tooling
will allow.  Especially focusing on Concepts, Ranges and Modules TS.

See [C++ Experimental Features](https://en.cppreference.com/w/cpp/experimental).

Where the language is "not ready" then polyfill with script kiddies or other tooling crutches are used.

# The Basics

## `namespace tunitas`

   * `tunitas.Outcome' provides function outcome
   * `tunitas::outcome::Success` where success is signle and the concept of a type that be used with `tunitas::Outcome`

## `namespace tunitas::exception`

   * ```tunitas.exception.Quitting''' leave the application.

Namespace naming convention: singular (as in "an exception")

## `namespace tunitas::option`

   * ```tunitas.option.Args''' the analog of ```argv'''
   
Namespace naming convention: singular (as in "an option")

## `namespace tunitas::required`

Contains concepts

   * `tunitas::required::Default_Constructible` the concept of a type which is default constructible.
   * `tunitas::required::Move_Constructible` the concept of a type which is move constructible.
   * `tunitas::required::Outcome` the concept of a type that be used with `tunitas::Outcome`.
   * `tunitas::required::Stringable` the concept of a type convertible into `std::string`.

Namespace naming convention: past tense (so it is distinct from the `requires` keyword)

# The Libraries

Static and DSO forms.

Especially following the best practices defined in Ulrich Drepper's opus [How To Write Shared Libraries](https://software.intel.com/sites/default/files/m/a/1/e/dsohowto.pdf), 2011-12-10 (47 pages).
