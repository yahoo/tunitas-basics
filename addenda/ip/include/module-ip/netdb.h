// This is C++ 23 -*- c++ -*- -std=c++23 in the stylings of the S.C.O.L.D. design method.
// For terms and provenance see the LICENSE file at the top of the repository.
#pragma once

 // provides __GNU_SOURCE
#include <module-ip/config.h>
// AVOID because other inline functions (e.g. in sys::posix) are wont to use this name
#undef VERSION

// What we came for, the #defines
#include <netdb.h>
