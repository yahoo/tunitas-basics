# Catalog of Components

The Tunitas Basics package contains core components which are used across all the Tunitas projects.  The package supplies library components.

A short survey of the components is provided here. You should consult the interface definitions for a complete enumeration

## `namespace tunitas`

   * `tunitas.Outcome` provides function outcome
   * `tunitas.Success` where success is a singleton
   * `tunitas.Variant` a type-safe discriminated untion, following `std::variant`
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

   * `tunitas.app.options.Args` the analog of `argv'
   * `tunitas.app.options.get_filepath` acquire a _filepath_ during options processing.
   * `tunitas.app.options.get_identifier` acquire an _identifier_ during options processing.
   * `tunitas.app.options.get_port` acquire an internet protocol _port_ number during options processing.
   * `tunitas.app.options.get_word` acquire an uninterpreted word during options processing.
   * `tunitas.app.options.Specification` a base class with the specification of common options.
   
Namespace naming convention for historical reasons is the pluralsingular (as in "the options")

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
   * `tunitas::required::Outcomeable` the concept of a type that be used with `tunitas::Outcome`.
   * `tunitas::required::Stringable` the concept of a type convertible into `std::string`.

The namespace naming convention is that the past tense is used for `required` whic is is distinct from the `requires` language keyword.

## `namespace tunitas::server`

These interfaces relate to the use of Tunitas in server contexts.  They provide support for `module-httpserver`, the S.C.O.L.D. interface to [libhttpserver](https://github.com/etr/libhttpserver).

   * `tunitas.server.constants` some constants.
   * `tunitas.server.filters` common URL filters.
   * `tunitas.server.logs` common logging.
   * `tunitas.server.resources` the namespace around _resources_.
   * `tunitas.server.responses` the namespace around _responses.
   * `tunitas.server.service` the namespace around the _services_.

## `namespace tunitas::time`

   * `tunitas.urlsafe.Clock` the system clock
   * `tunitas.urlsafe.Duration` a time duration following `std::chrono::duration`
   * `tunitas.urlsafe.Point` a time point following `std::chrono::time_point`
   * `tunitas.urlsafe.put` is a picture-based time formatter accepting `Point`

## `namespace tunitas::urlsafe`

   * `tunitas.urlsafe.decode` a URL-safe decoder.
   * `tunitas.urlsafe.encode` a URL-safe encoder.
