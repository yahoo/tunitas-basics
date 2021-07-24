<!-- [[TODO]] 

The intent is not to have this page be the authoritative representation of documentation for _The Basics_.
Nor is it to have Microsoft's GitHub portal be the authoritative rendering of the documentation facility.

[[TODO]] Move these to independent wiki pages following the wiki stylings of https://en.cppreference.com/w/cpp/iterator/projected

-->
# Catalog of Components

The Tunitas Basics package contains core components which are used across all the Tunitas projects.  The package supplies library components.

The components are oriented towards "app" and "server" use cases.
In this sense "app" means _command-line application_ and "server" means _background service_ or _daemon_.

Many of the components are type aliases for implementations which are defined in other namespaces, for example `namespace nonstd`.

A short survey of the components is provided here. You should consult the interface definitions for a complete enumeration

## `namespace tunitas`

   * `tunitas.Outcome` provides function outcome following (http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2019/p0323r8.html)[std::expected][std::expected](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2019/p0323r8.html)<!-- following https://www.markdownguide.org/basic-syntax/ -- First we learned nroff then we learned troff then we learned tex then we learned LaTeX and then XML then we learned HTML and XHTML and then HTML+tables and then HTML5+CSS and each time they said it would be simpler the next generation of markup markdown woven literate text layout programming languages ... and how we have to remember whether it is [text](link) or (text)[link] or [link](text) or [text](link).  So there's progress in computers after all -->
   * `tunitas.Success` where success is a singleton
   * `tunitas.Variant` a type-safe discriminated union, following `std::variant`, being `std::variant`
   * `tunitas.Visitor` a visitor for the `Variant`

## `namespace tunitas::app`

This namespace contains classes and functions useful for processing program command line options.

   * `tunitas.app.Configuration` capture program configuration variables
   * `tunitas.app.drop` drop (root) privileges
   * `tunitas.app.Pidfile` manage a daemon's _pidfile_, frequently found in `/run`
   * `tunitas.app.Program` capture the program's name

## `namespace tunitas::app::exception`

   * `tunitas.app.exception.Quitting` leave the application.
   * `tunitas.app.exception.Usage` the common ancestor of _usage_ exception.
   * `tunitas.app.exception.Version` the common ancestor of the _version_ exception.

Namespace naming convention: singular (as in "an exception")

## `namespace tunitas::app::options`

Following the `cli` package as it aggregates the packages `options` and others.

   * `tunitas.app.options.Args` the analog of `argv'
   * `tunitas.app.options.get_filepath` acquire a _filepath_ during options processing.
   * `tunitas.app.options.get_identifier` acquire an _identifier_ during options processing.
   * `tunitas.app.options.get_port` acquire an internet protocol _port_ number during options processing.
   * `tunitas.app.options.get_word` acquire an uninterpreted word during options processing.
   * `tunitas.app.options.Specification` a base class with the specification of common options.
   
The namespace naming convention here is at variance with the convention.  For historical reasons<!-- for security reasons, for "due to the ever-increasing complexity of VLSI design," or for any reason or for no reason at all --> the usage here is plural (as in _the options_) though our naming convention for the namespace would naturally prefer the singular (as in _option::Specification_).

## `namespace tunitas::app::words`

   * `tunitas.app.words.Filepath` process command line argument container for filesystem paths.
   * `tunitas.app.words.Strings` process command line argument container for uninterpreted words.

## `namespace tunitas::base64`

   * `tunitas.base64.decode` a base64 decoder
   * `tunitas.base64.encode` a base64 encoder

## `namespace tunitas::required`

Contains concepts, at least:

   * `tunitas::required::Container_Push_Back_Char` the concept of a container with a `push_back(char)` capability.
   * `tunitas::required::Default_Constructible` the concept of a type which is default constructible.
   * `tunitas::required::exception.app.Quitting` matches the `Quitting` exception.
   * `tunitas::required::Integer` 
   * `tunitas::required::Integral` 
   * `tunitas::required::Iterator_Producing` 
   * `tunitas::required::Move_Constructible` the concept of a type which is move constructible.
   * `tunitas::required::Outcomable` the concept of a type that be used with `tunitas::Outcome`.
   * `tunitas::required::Stringable` the concept of a type convertible into `std::string`.

The namespace naming convention is that the past tense is used for `required` whic is is distinct from the `requires` language keyword.

## `namespace tunitas::server`

These interfaces relate to the use of Tunitas in server contexts.

<b>These interfaces are destined to change to use [microhttpd++](https://git.tunitas.technology/all/services/microhttpd++.git)</b>.
In the current incarnation they support the interfaces of `module-httpserver`, which is the S.C.O.L.D. interface to [libhttpserver](https://github.com/etr/libhttpserver).

   * `tunitas.server.constants` some constants.
   * `tunitas.server.filters` common URL filters.
   * `tunitas.server.logs` common logging.
   * `tunitas.server.resources` the namespace around _resources_.
   * `tunitas.server.responses` the namespace around _responses.
   * `tunitas.server.service` the namespace around the _services_.

## `namespace tunitas::time`

   * `tunitas.time.Clock` the system clock
   * `tunitas.time.Duration` a time duration following `std::chrono::duration`
   * `tunitas.time.Point` a time point following `std::chrono::time_point`
   * `tunitas.time.put` is a picture-based time formatter accepting `Point` following `std::put_time`.

## `namespace tunitas::urlsafe`

   * `tunitas.urlsafe.decode` a URL-safe decoder.
   * `tunitas.urlsafe.encode` a URL-safe encoder.
