// This is -*- c++ -*- unto C++26
//
// The test proves that all this compiles
//
namespace tests::usage { }
#if !defined(__GNUC__)
#warning This is not gcc.  No clue.  Good Luck.
//
// nothing
//
#elif __GNUC__ <= 6
#error GCC7, GCC8 or more is required at this point
#elif __GNUC__ <= 7
// Declared to be in C++17 (but actually not yet ready)
// The use of the #ifdef...#endif signals the controversy altogether
#define __ready7__
#undef __ready8__
#undef __ready9__
#undef __ready10__
#undef __ready11__
#undef __ready12__
#elif __GNUC__ <= 8
// declared to be in C++17 (but actually not yet ready)
// observed on gcc (GCC) 8.2.1 20181105 (Red Hat 8.2.1-5)
#define __ready7__
#define __ready8__
#undef __ready9__
#undef __ready10__
#undef __ready11__
#undef __ready12__
#elif __GNUC__ <= 9
// declared to be in C++2a (but actually not yet ready)
#define __ready7__
#define __ready8__
#define __ready9__
#undef __ready10__
#undef __ready11__
#undef __ready12__
#elif __GNUC__ <= 10
// declared to be in C++2a (but actually not yet ready)
#define __ready7__
#define __ready8__
#define __ready9__
#define __ready10__
#undef __ready11__
#undef __ready12__
#elif __GNUC__ <= 11
// declared to be in C++2a (but actually not yet ready)
#define __ready7__
#define __ready8__
#define __ready9__
#define __ready10__
#define __ready11__
#undef __ready12__
#else
// declared to be in C++2b (but actually not yet ready)
#define __ready7__
#define __ready8__
#define __ready9__
#define __ready10__
#define __ready11__
#define __ready12__
#endif

#ifndef __ready8__
#warning NOT READY <std.from_chars> std::from_chars
#warning NOT READY <std.from_chars_result> std::from_chars_result
#warning NOT READY <std.to_chars> std::to_chars
#warning NOT READY <std.to_chars_result> std::to_chars_result
#else
#include <std.from_chars>
namespace tests::usage { using std::from_chars; }
#include <std.from_chars_result>
namespace tests::usage { using std::from_chars_result; }
#include <std.to_chars>
namespace tests::usage { using std::to_chars; }
#include <std.to_chars_result>
namespace tests::usage { using std::to_chars_result; }
#endif

#ifndef __ready10__
#warning NOT READY <std.bind_front> std::bind_front
#warning NOT READY <std.chars_format> std::chars_format
#else
#include <std.bind_front>
namespace tests::usage { using std::bind_front; }
#include <std.chars_format>
namespace tests::usage { using std::chars_format; }
#endif

#ifndef __ready8__
#warning NOT READY <std.filesystem.perm_options> std::filesystem::perm_options
#warning NOT READY <std.filesystem.proximate> std::filesystem::proximate
#warning NOT READY <std.filesystem.relative> std::filesystem::relative
#warning NOT READY <std.filesystem.weakly_canonical> std::filesystem::weakly_canonical
#else
#include <std.filesystem.perm_options>
namespace tests::usage { using std::filesystem::perm_options; }
#include <std.filesystem.proximate>
namespace tests::usage { using std::filesystem::proximate; }
#include <std.filesystem.relative>
namespace tests::usage { using std::filesystem::relative; }
#include <std.filesystem.weakly_canonical>
namespace tests::usage { using std::filesystem::weakly_canonical; }
#endif

//
// Unready module names
// C++17 and prior
//

// namespaces
#include <std.chrono>
namespace tests::usage { using namespace std::chrono; }
#include <std.chrono_literals>
namespace tests::usage { using namespace std::chrono_literals; }
#include <std.literals>
namespace tests::usage { using namespace std::literals; }
#include <std.literals.chrono_literals>
namespace tests::usage { using namespace std::literals::chrono_literals; }
#include <std.literals.string_literals>
namespace tests::usage { using namespace std::literals::string_literals; }
#include <std.literals.string_view_literals>
namespace tests::usage { using namespace std::literals::string_view_literals; }
#include <std.string_literals>
namespace tests::usage { using namespace std::string_literals; }
#include <std.string_view_literals>
namespace tests::usage { using namespace std::string_view_literals; }
#include <std.filesystem>
namespace tests::usage { using namespace std::filesystem; }
#include <std.placeholders>
namespace tests::usage { using namespace std::placeholders; }
#include <std.regex_constants>
namespace tests::usage { using namespace std::regex_constants; }

// types
#include <std.abs>
namespace tests::usage { using std::abs; }
#include <std.add_const>
namespace tests::usage { using std::add_const; }
#include <std.add_cv>
namespace tests::usage { using std::add_cv; }
#include <std.add_lvalue_reference>
namespace tests::usage { using std::add_lvalue_reference; }
#include <std.add_pointer>
namespace tests::usage { using std::add_pointer; }
#include <std.addressof>
namespace tests::usage { using std::addressof; }
#include <std.add_rvalue_reference>
namespace tests::usage { using std::add_rvalue_reference; }
#include <std.add_volatile>
namespace tests::usage { using std::add_volatile; }
#include <std.adjacent_find>
namespace tests::usage { using std::adjacent_find; }
#include <std.advance>
namespace tests::usage { using std::advance; }
#include <std.align>
namespace tests::usage { using std::align; }
#include <std.aligned_storage>
namespace tests::usage { using std::aligned_storage; }
#include <std.aligned_union>
namespace tests::usage { using std::aligned_union; }
#include <std.alignment_of>
namespace tests::usage { using std::alignment_of; }
#include <std.allocate_shared>
namespace tests::usage { using std::allocate_shared; }
#include <std.allocator>
namespace tests::usage { using std::allocator; }
#include <std.allocator_arg>
namespace tests::usage { using std::allocator_arg; }
#include <std.allocator_arg_t>
namespace tests::usage { using std::allocator_arg_t; }
#include <std.allocator_traits>
namespace tests::usage { using std::allocator_traits; }
#include <std.any_cast>
namespace tests::usage { using std::any_cast; }
#include <std.all_of>
namespace tests::usage { using std::all_of; }
#include <std.any_of>
namespace tests::usage { using std::any_of; }
#include <std.array>
namespace tests::usage { using std::array; }
#include <std.atomic>
namespace tests::usage { using std::atomic; }
#include <std.atto>
namespace tests::usage { using std::atto; }
#include <std.auto_ptr>
namespace tests::usage { using std::auto_ptr; }
#include <std.auto_ptr_ref>
namespace tests::usage { using std::auto_ptr_ref; }
#include <std.bad_any_cast>
namespace tests::usage { using std::bad_any_cast; }
#include <std.back_inserter>
namespace tests::usage { using std::back_inserter; }
#include <std.back_insert_iterator>
namespace tests::usage { using std::back_insert_iterator; }
#include <std.bad_alloc>
namespace tests::usage { using std::bad_alloc; }
#include <std.bad_cast>
namespace tests::usage { using std::bad_cast; }
#include <std.bad_exception>
namespace tests::usage { using std::bad_exception; }
#include <std.bad_function_call>
namespace tests::usage { using std::bad_function_call; }
#include <std.bad_optional_access>
namespace tests::usage { using std::bad_optional_access; }
#include <std.bad_typeid>
namespace tests::usage { using std::bad_typeid; }
#include <std.bad_variant_access>
namespace tests::usage { using std::bad_variant_access; }
#include <std.bad_weak_ptr>
namespace tests::usage { using std::bad_weak_ptr; }
#include <std.basic_filebuf>
namespace tests::usage { using std::basic_filebuf; }
#include <std.basic_fstream>
namespace tests::usage { using std::basic_fstream; }
#include <std.basic_ifstream>
namespace tests::usage { using std::basic_ifstream; }
#include <std.basic_ios>
namespace tests::usage { using std::basic_ios; }
#include <std.basic_iostream>
namespace tests::usage { using std::basic_iostream; }
#include <std.basic_istream>
namespace tests::usage { using std::basic_istream; }
#include <std.basic_istringstream>
namespace tests::usage { using std::basic_istringstream; }
#include <std.basic_ofstream>
namespace tests::usage { using std::basic_ofstream; }
#include <std.basic_ostream>
namespace tests::usage { using std::basic_ostream; }
#include <std.basic_ostringstream>
namespace tests::usage { using std::basic_ostringstream; }
#include <std.basic_regex>
namespace tests::usage { using std::basic_regex; }
#include <std.basic_streambuf>
namespace tests::usage { using std::basic_streambuf; }
#include <std.basic_string>
namespace tests::usage { using std::basic_string; }
#include <std.basic_stringbuf>
namespace tests::usage { using std::basic_stringbuf; }
#include <std.basic_stringstream>
namespace tests::usage { using std::basic_stringstream; }
#include <std.basic_string_view>
namespace tests::usage { using std::basic_string_view; }
#include <std.begin>
namespace tests::usage { using std::begin; }
#include <std.bernoulli_distribution>
namespace tests::usage { using std::bernoulli_distribution; }
#include <std.bidirectional_iterator_tag>
namespace tests::usage { using std::bidirectional_iterator_tag; }
#include <std.binary_function>
namespace tests::usage { using std::binary_function; }
#include <std.binary_negate>
namespace tests::usage { using std::binary_negate; }
#include <std.binary_search>
namespace tests::usage { using std::binary_search; }
#include <std.bind>
namespace tests::usage { using std::bind; }
#include <std.binder1st>
namespace tests::usage { using std::binder1st; }
#include <std.binder2nd>
namespace tests::usage { using std::binder2nd; }
#include <std.binomial_distribution>
namespace tests::usage { using std::binomial_distribution; }
#include <std.bit_and>
namespace tests::usage { using std::bit_and; }
#include <std.bit_not>
namespace tests::usage { using std::bit_not; }
#include <std.bit_or>
namespace tests::usage { using std::bit_or; }
#include <std.bit_xor>
namespace tests::usage { using std::bit_xor; }
#include <std.bitset>
namespace tests::usage { using std::bitset; }
#include <std.boolalpha>
namespace tests::usage { using std::boolalpha; }
#include <std.boyer_moore_horspool_searcher>
namespace tests::usage { using std::boyer_moore_horspool_searcher; }
#include <std.boyer_moore_searcher>
namespace tests::usage { using std::boyer_moore_searcher; }
#include <std.byte>
namespace tests::usage { using std::byte; }
#include <std.calloc>
namespace tests::usage { using std::calloc; }
#include <std.cauchy_distribution>
namespace tests::usage { using std::cauchy_distribution; }
#include <std.cbegin>
namespace tests::usage { using std::cbegin; }
#include <std.cend>
namespace tests::usage { using std::cend; }
#include <std.centi>
namespace tests::usage { using std::centi; }
#include <std.cerr>
namespace tests::usage { using std::cerr; }
#include <std.char_traits>
namespace tests::usage { using std::char_traits; }
#include <std.chi_squared_distribution>
namespace tests::usage { using std::chi_squared_distribution; }
#include <std.chrono.duration>
namespace tests::usage { using std::chrono::duration; }
#include <std.chrono.duration_cast>
namespace tests::usage { using std::chrono::duration_cast; }
#include <std.chrono.high_resolution_clock>
namespace tests::usage { using std::chrono::high_resolution_clock; }
#include <std.chrono.hours>
namespace tests::usage { using std::chrono::hours; }
#include <std.chrono.microseconds>
namespace tests::usage { using std::chrono::microseconds; }
#include <std.chrono.milliseconds>
namespace tests::usage { using std::chrono::milliseconds; }
#include <std.chrono.minutes>
namespace tests::usage { using std::chrono::minutes; }
#include <std.chrono.nanoseconds>
namespace tests::usage { using std::chrono::nanoseconds; }
#include <std.chrono.seconds>
namespace tests::usage { using std::chrono::seconds; }
#include <std.chrono.system_clock>
namespace tests::usage { using std::chrono::system_clock; }
#include <std.chrono.time_point>
namespace tests::usage { using std::chrono::time_point; }
#include <std.chrono.time_point_cast>
namespace tests::usage { using std::chrono::time_point_cast; }
#include <std.cin>
namespace tests::usage { using std::cin; }
#include <std.clog>
namespace tests::usage { using std::clog; }
#include <std.cmatch>
namespace tests::usage { using std::cmatch; }
#include <std.common_type>
namespace tests::usage { using std::common_type; }
#include <std.conditional>
namespace tests::usage { using std::conditional; }
#include <std.const_pointer_cast>
namespace tests::usage { using std::const_pointer_cast; }
#include <std.copy>
namespace tests::usage { using std::copy; }
#include <std.copy_backward>
namespace tests::usage { using std::copy_backward; }
#include <std.copy_if>
namespace tests::usage { using std::copy_if; }
#include <std.copy_n>
namespace tests::usage { using std::copy_n; }
#include <std.count>
namespace tests::usage { using std::count; }
#include <std.count_if>
namespace tests::usage { using std::count_if; }
#include <std.cout>
namespace tests::usage { using std::cout; }
#include <std.crbegin>
namespace tests::usage { using std::crbegin; }
#include <std.cref>
namespace tests::usage { using std::cref; }
#include <std.crend>
namespace tests::usage { using std::crend; }
#include <std.csub_match>
namespace tests::usage { using std::csub_match; }
#include <std.current_exception>
namespace tests::usage { using std::current_exception; }
#include <std.dec>
namespace tests::usage { using std::dec; }
#include <std.deca>
namespace tests::usage { using std::deca; }
#include <std.decay>
namespace tests::usage { using std::decay; }
#include <std.deci>
namespace tests::usage { using std::deci; }
#include <std.declare_no_pointers>
namespace tests::usage { using std::declare_no_pointers; }
#include <std.declare_reachable>
namespace tests::usage { using std::declare_reachable; }
#include <std.declval>
namespace tests::usage { using std::declval; }
#include <std.default_delete>
namespace tests::usage { using std::default_delete; }
#include <std.defaultfloat>
namespace tests::usage { using std::defaultfloat; }
#include <std.default_random_engine>
namespace tests::usage { using std::default_random_engine; }
#include <std.default_searcher>
namespace tests::usage { using std::default_searcher; }
#include <std.deque>
namespace tests::usage { using std::deque; }
#include <std.discard_block_engine>
namespace tests::usage { using std::discard_block_engine; }
#include <std.discrete_distribution>
namespace tests::usage { using std::discrete_distribution; }
#include <std.distance>
namespace tests::usage { using std::distance; }
#include <std.divides>
namespace tests::usage { using std::divides; }
#include <std.domain_error>
namespace tests::usage { using std::domain_error; }
#include <std.dynamic_pointer_cast>
namespace tests::usage { using std::dynamic_pointer_cast; }
#include <std.empty>
namespace tests::usage { using std::empty; }
#include <std.enable_if>
namespace tests::usage { using std::enable_if; }
#include <std.enable_shared_from_this>
namespace tests::usage { using std::enable_shared_from_this; }
#include <std.end>
namespace tests::usage { using std::end; }
#include <std.endl>
namespace tests::usage { using std::endl; }
#include <std.ends>
namespace tests::usage { using std::ends; }
#include <std.equal>
namespace tests::usage { using std::equal; }
#include <std.equal_range>
namespace tests::usage { using std::equal_range; }
#include <std.equal_to>
namespace tests::usage { using std::equal_to; }
#include <std.errc>
namespace tests::usage { using std::errc; }
#include <std.error_category>
namespace tests::usage { using std::error_category; }
#include <std.error_code>
namespace tests::usage { using std::error_code; }
#include <std.error_condition>
namespace tests::usage { using std::error_condition; }
#include <std.exa>
namespace tests::usage { using std::exa; }
#include <std.exception>
namespace tests::usage { using std::exception; }
#include <std.exception_ptr>
namespace tests::usage { using std::exception_ptr; }
#include <std.exponential_distribution>
namespace tests::usage { using std::exponential_distribution; }
#include <std.extent>
namespace tests::usage { using std::extent; }
#include <std.extreme_value_distribution>
namespace tests::usage { using std::extreme_value_distribution; }
#include <std.false_type>
namespace tests::usage { using std::false_type; }
#include <std.femto>
namespace tests::usage { using std::femto; }
#include <std.filebuf>
namespace tests::usage { using std::filebuf; }
#include <std.filesystem.absolute>
namespace tests::usage { using std::filesystem::absolute; }
#include <std.filesystem.canonical>
namespace tests::usage { using std::filesystem::canonical; }
#include <std.filesystem.copy>
namespace tests::usage { using std::filesystem::copy; }
#include <std.filesystem.copy_file>
namespace tests::usage { using std::filesystem::copy_file; }
#include <std.filesystem.copy_options>
namespace tests::usage { using std::filesystem::copy_options; }
#include <std.filesystem.copy_symlink>
namespace tests::usage { using std::filesystem::copy_symlink; }
#include <std.filesystem.create_directories>
namespace tests::usage { using std::filesystem::create_directories; }
#include <std.filesystem.create_directory>
namespace tests::usage { using std::filesystem::create_directory; }
#include <std.filesystem.create_directory_symlink>
namespace tests::usage { using std::filesystem::create_directory_symlink; }
#include <std.filesystem.create_hard_link>
namespace tests::usage { using std::filesystem::create_hard_link; }
#include <std.filesystem.create_symlink>
namespace tests::usage { using std::filesystem::create_symlink; }
#include <std.filesystem.current_path>
namespace tests::usage { using std::filesystem::current_path; }
#include <std.filesystem.directory_entry>
namespace tests::usage { using std::filesystem::directory_entry; }
#include <std.filesystem.directory_iterator>
namespace tests::usage { using std::filesystem::directory_iterator; }
#include <std.filesystem.directory_options>
namespace tests::usage { using std::filesystem::directory_options; }
#include <std.filesystem.equivalent>
namespace tests::usage { using std::filesystem::equivalent; }
#include <std.filesystem.exists>
namespace tests::usage { using std::filesystem::exists; }
#include <std.filesystem.file_size>
namespace tests::usage { using std::filesystem::file_size; }
#include <std.filesystem.file_status>
namespace tests::usage { using std::filesystem::file_status; }
#include <std.filesystem.filesystem_error>
namespace tests::usage { using std::filesystem::filesystem_error; }
#include <std.filesystem.file_time_type>
namespace tests::usage { using std::filesystem::file_time_type; }
#include <std.filesystem.file_type>
namespace tests::usage { using std::filesystem::file_type; }
#include <std.filesystem.hard_link_count>
namespace tests::usage { using std::filesystem::hard_link_count; }
#include <std.filesystem.is_block_file>
namespace tests::usage { using std::filesystem::is_block_file; }
#include <std.filesystem.is_character_file>
namespace tests::usage { using std::filesystem::is_character_file; }
#include <std.filesystem.is_directory>
namespace tests::usage { using std::filesystem::is_directory; }
#include <std.filesystem.is_empty>
namespace tests::usage::filesystem { using std::filesystem::is_empty; }
#include <std.filesystem.is_fifo>
namespace tests::usage { using std::filesystem::is_fifo; }
#include <std.filesystem.is_other>
namespace tests::usage { using std::filesystem::is_other; }
#include <std.filesystem.is_regular_file>
namespace tests::usage { using std::filesystem::is_regular_file; }
#include <std.filesystem.is_socket>
namespace tests::usage { using std::filesystem::is_socket; }
#include <std.filesystem.is_symlink>
namespace tests::usage { using std::filesystem::is_symlink; }
#include <std.filesystem.last_write_time>
namespace tests::usage { using std::filesystem::last_write_time; }
#include <std.filesystem.path>
namespace tests::usage { using std::filesystem::path; }
#include <std.filesystem.permissions>
namespace tests::usage { using std::filesystem::permissions; }
#include <std.filesystem.perms>
namespace tests::usage { using std::filesystem::perms; }
#include <std.filesystem.read_symlink>
namespace tests::usage { using std::filesystem::read_symlink; }
#include <std.filesystem.recursive_directory_iterator>
namespace tests::usage { using std::filesystem::recursive_directory_iterator; }
#include <std.filesystem.remove>
namespace tests::usage { using std::filesystem::remove; }
#include <std.filesystem.remove_all>
namespace tests::usage { using std::filesystem::remove_all; }
#include <std.filesystem.rename>
namespace tests::usage { using std::filesystem::rename; }
#include <std.filesystem.resize_file>
namespace tests::usage { using std::filesystem::resize_file; }
#include <std.filesystem.space>
namespace tests::usage { using std::filesystem::space; }
#include <std.filesystem.space_info>
namespace tests::usage { using std::filesystem::space_info; }
#include <std.filesystem.status>
namespace tests::usage { using std::filesystem::status; }
#include <std.filesystem.status_known>
namespace tests::usage { using std::filesystem::status_known; }
#include <std.filesystem.symlink_status>
namespace tests::usage { using std::filesystem::symlink_status; }
#include <std.filesystem.temp_directory_path>
namespace tests::usage { using std::filesystem::temp_directory_path; }
#include <std.fill>
namespace tests::usage { using std::fill; }
#include <std.fill_n>
namespace tests::usage { using std::fill_n; }
#include <std.find>
namespace tests::usage { using std::find; }
#include <std.find_end>
namespace tests::usage { using std::find_end; }
#include <std.find_first_of>
namespace tests::usage { using std::find_first_of; }
#include <std.find_if>
namespace tests::usage { using std::find_if; }
#include <std.find_if_not>
namespace tests::usage { using std::find_if_not; }
#include <std.fisher_f_distribution>
namespace tests::usage { using std::fisher_f_distribution; }
#include <std.fixed>
namespace tests::usage { using std::fixed; }
#include <std.float_denorm_style>
namespace tests::usage { using std::float_denorm_style; }
#include <std.float_round_style>
namespace tests::usage { using std::float_round_style; }
#include <std.flush>
namespace tests::usage { using std::flush; }
#include <std.for_each>
namespace tests::usage { using std::for_each; }
#ifndef __ready10__
#warning NOT READY <std.format>
#else
#include <std.format>
namespace tests::usage { using std::format; }
#endif
#include <std.forward>
namespace tests::usage { using std::forward; }
#include <std.forward_as_tuple>
namespace tests::usage { using std::forward_as_tuple; }
#include <std.forward_iterator_tag>
namespace tests::usage { using std::forward_iterator_tag; }
#include <std.forward_list>
namespace tests::usage { using std::forward_list; }
#include <std.fpos>
namespace tests::usage { using std::fpos; }
#include <std.free>
namespace tests::usage { using std::free; }
#include <std.front_inserter>
namespace tests::usage { using std::front_inserter; }
#include <std.front_insert_iterator>
namespace tests::usage { using std::front_insert_iterator; }
#include <std.fstream>
namespace tests::usage { using std::fstream; }
#include <std.function>
namespace tests::usage { using std::function; }
#include <std.gamma_distribution>
namespace tests::usage { using std::gamma_distribution; }
#include <std.generate>
namespace tests::usage { using std::generate; }
#include <std.generate_canonical>
namespace tests::usage { using std::generate_canonical; }
#include <std.generate_n>
namespace tests::usage { using std::generate_n; }
#include <std.generic_category>
namespace tests::usage { using std::generic_category; }
#include <std.geometric_distribution>
namespace tests::usage { using std::geometric_distribution; }
#include <std.get>
namespace tests::usage { using std::get; }
#include <std.get_deleter>
namespace tests::usage { using std::get_deleter; }
#include <std.get_if>
namespace tests::usage { using std::get_if; }
#include <std.getline>
namespace tests::usage { using std::getline; }
#include <std.get_money>
namespace tests::usage { using std::get_money; }
#include <std.get_pointer_safety>
namespace tests::usage { using std::get_pointer_safety; }
#include <std.get_temporary_buffer>
namespace tests::usage { using std::get_temporary_buffer; }
#include <std.get_terminate>
namespace tests::usage { using std::get_terminate; }
#include <std.get_time>
namespace tests::usage { using std::get_time; }
#include <std.get_unexpected>
namespace tests::usage { using std::get_unexpected; }
#include <std.giga>
namespace tests::usage { using std::giga; }
#include <std.gmtime>
namespace tests::usage { using std::gmtime; }
#include <std.greater>
namespace tests::usage { using std::greater; }
#include <std.greater_equal>
namespace tests::usage { using std::greater_equal; }
#include <std.hash>
namespace tests::usage { using std::hash; }
#include <std.has_virtual_destructor>
namespace tests::usage { using std::has_virtual_destructor; }
#include <std.hecto>
namespace tests::usage { using std::hecto; }
#include <std.hex>
namespace tests::usage { using std::hex; }
#include <std.hexfloat>
namespace tests::usage { using std::hexfloat; }
#include <std.holds_alternative>
namespace tests::usage { using std::holds_alternative; }
#include <std.ifstream>
namespace tests::usage { using std::ifstream; }
#include <std.ignore>
namespace tests::usage { using std::ignore; }
#include <std.includes>
namespace tests::usage { using std::includes; }
#include <std.independent_bits_engine>
namespace tests::usage { using std::independent_bits_engine; }
#include <std.initializer_list>
namespace tests::usage { using std::initializer_list; }
#include <std.in_place>
namespace tests::usage { using std::in_place; }
#include <std.in_place_index>
namespace tests::usage { using std::in_place_index; }
#include <std.in_place_index_t>
namespace tests::usage { using std::in_place_index_t; }
#include <std.inplace_merge>
namespace tests::usage { using std::inplace_merge; }
#include <std.in_place_t>
namespace tests::usage { using std::in_place_t; }
#include <std.in_place_type>
namespace tests::usage { using std::in_place_type; }
#include <std.in_place_type_t>
namespace tests::usage { using std::in_place_type_t; }
#include <std.input_iterator_tag>
namespace tests::usage { using std::input_iterator_tag; }
#include <std.inserter>
namespace tests::usage { using std::inserter; }
#include <std.insert_iterator>
namespace tests::usage { using std::insert_iterator; }
#include <std.int16_t>
namespace tests::usage { using std::int16_t; }
#include <std.int32_t>
namespace tests::usage { using std::int32_t; }
#include <std.int64_t>
namespace tests::usage { using std::int64_t; }
#include <std.int8_t>
namespace tests::usage { using std::int8_t; }
#include <std.integral_constant>
namespace tests::usage { using std::integral_constant; }
#include <std.internal>
namespace tests::usage { using std::internal; }
#include <std.intmax_t>
namespace tests::usage { using std::intmax_t; }
#include <std.invalid_argument>
namespace tests::usage { using std::invalid_argument; }
#include <std.invoke>
namespace tests::usage { using std::invoke; }
#include <std.io_errc>
namespace tests::usage { using std::io_errc; }
#include <std.ios>
namespace tests::usage { using std::ios; }
#include <std.ios_base>
namespace tests::usage { using std::ios_base; }
#include <std.iostream>
namespace tests::usage { using std::iostream; }
#include <std.iostream_category>
namespace tests::usage { using std::iostream_category; }
#include <std.is_abstract>
namespace tests::usage { using std::is_abstract; }
#include <std.isalnum>
namespace tests::usage { using std::isalnum; }
#include <std.isalpha>
namespace tests::usage { using std::isalpha; }
#include <std.is_arithmetic>
namespace tests::usage { using std::is_arithmetic; }
#include <std.is_array>
namespace tests::usage { using std::is_array; }
#include <std.is_assignable>
namespace tests::usage { using std::is_assignable; }
#include <std.is_base_of>
namespace tests::usage { using std::is_base_of; }
#include <std.is_bind_expression>
namespace tests::usage { using std::is_bind_expression; }
#include <std.isblank>
namespace tests::usage { using std::isblank; }
#include <std.is_class>
namespace tests::usage { using std::is_class; }
#include <std.iscntrl>
namespace tests::usage { using std::iscntrl; }
#include <std.is_compound>
namespace tests::usage { using std::is_compound; }
#include <std.is_const>
namespace tests::usage { using std::is_const; }
#include <std.is_constructible>
namespace tests::usage { using std::is_constructible; }
#include <std.is_convertible>
namespace tests::usage { using std::is_convertible; }
#include <std.is_copy_assignable>
namespace tests::usage { using std::is_copy_assignable; }
#include <std.is_copy_constructible>
namespace tests::usage { using std::is_copy_constructible; }
#include <std.is_default_constructible>
namespace tests::usage { using std::is_default_constructible; }
#include <std.is_destructible>
namespace tests::usage { using std::is_destructible; }
#include <std.isdigit>
namespace tests::usage { using std::isdigit; }
#include <std.is_empty>
namespace tests::usage { using std::is_empty; }
#include <std.is_enum>
namespace tests::usage { using std::is_enum; }
#include <std.is_error_code_enum>
namespace tests::usage { using std::is_error_code_enum; }
#include <std.is_error_condition_enum>
namespace tests::usage { using std::is_error_condition_enum; }
#include <std.is_final>
namespace tests::usage { using std::is_final; }
#include <std.is_floating_point>
namespace tests::usage { using std::is_floating_point; }
#include <std.is_function>
namespace tests::usage { using std::is_function; }
#include <std.is_fundamental>
namespace tests::usage { using std::is_fundamental; }
#include <std.isgraph>
namespace tests::usage { using std::isgraph; }
#include <std.is_heap>
namespace tests::usage { using std::is_heap; }
#include <std.is_heap_until>
namespace tests::usage { using std::is_heap_until; }
#include <std.is_integral>
namespace tests::usage { using std::is_integral; }
#include <std.is_literal_type>
namespace tests::usage { using std::is_literal_type; }
#include <std.islower>
namespace tests::usage { using std::islower; }
#include <std.is_lvalue_reference>
namespace tests::usage { using std::is_lvalue_reference; }
#include <std.is_member_function_pointer>
namespace tests::usage { using std::is_member_function_pointer; }
#include <std.is_member_object_pointer>
namespace tests::usage { using std::is_member_object_pointer; }
#include <std.is_member_pointer>
namespace tests::usage { using std::is_member_pointer; }
#include <std.is_move_assignable>
namespace tests::usage { using std::is_move_assignable; }
#include <std.is_move_constructible>
namespace tests::usage { using std::is_move_constructible; }
#include <std.is_nothrow_assignable>
namespace tests::usage { using std::is_nothrow_assignable; }
#include <std.is_nothrow_constructible>
namespace tests::usage { using std::is_nothrow_constructible; }
#include <std.is_nothrow_copy_assignable>
namespace tests::usage { using std::is_nothrow_copy_assignable; }
#include <std.is_nothrow_copy_constructible>
namespace tests::usage { using std::is_nothrow_copy_constructible; }
#include <std.is_nothrow_default_constructible>
namespace tests::usage { using std::is_nothrow_default_constructible; }
#include <std.is_nothrow_destructible>
namespace tests::usage { using std::is_nothrow_destructible; }
#include <std.is_nothrow_move_assignable>
namespace tests::usage { using std::is_nothrow_move_assignable; }
#include <std.is_nothrow_move_constructible>
namespace tests::usage { using std::is_nothrow_move_constructible; }
#include <std.is_null_pointer>
namespace tests::usage { using std::is_null_pointer; }
#include <std.is_object>
namespace tests::usage { using std::is_object; }
#include <std.is_partitioned>
namespace tests::usage { using std::is_partitioned; }
#include <std.is_permutation>
namespace tests::usage { using std::is_permutation; }
#include <std.is_placeholder>
namespace tests::usage { using std::is_placeholder; }
#include <std.is_pod>
namespace tests::usage { using std::is_pod; }
#include <std.is_pointer>
namespace tests::usage { using std::is_pointer; }
#include <std.is_polymorphic>
namespace tests::usage { using std::is_polymorphic; }
#include <std.isprint>
namespace tests::usage { using std::isprint; }
#include <std.ispunct>
namespace tests::usage { using std::ispunct; }
#include <std.is_reference>
namespace tests::usage { using std::is_reference; }
#include <std.is_rvalue_reference>
namespace tests::usage { using std::is_rvalue_reference; }
#include <std.is_same>
namespace tests::usage { using std::is_same; }
#include <std.is_scalar>
namespace tests::usage { using std::is_scalar; }
#include <std.is_signed>
namespace tests::usage { using std::is_signed; }
#include <std.is_sorted>
namespace tests::usage { using std::is_sorted; }
#include <std.is_sorted_until>
namespace tests::usage { using std::is_sorted_until; }
#include <std.isspace>
namespace tests::usage { using std::isspace; }
#include <std.is_standard_layout>
namespace tests::usage { using std::is_standard_layout; }
#include <std.istream>
namespace tests::usage { using std::istream; }
#include <std.istreambuf_iterator>
namespace tests::usage { using std::istreambuf_iterator; }
#include <std.istream_iterator>
namespace tests::usage { using std::istream_iterator; }
#include <std.istringstream>
namespace tests::usage { using std::istringstream; }
#include <std.is_trivial>
namespace tests::usage { using std::is_trivial; }
#include <std.is_trivially_assignable>
namespace tests::usage { using std::is_trivially_assignable; }
#include <std.is_trivially_constructible>
namespace tests::usage { using std::is_trivially_constructible; }
#include <std.is_trivially_copyable>
namespace tests::usage { using std::is_trivially_copyable; }
#include <std.is_trivially_copy_assignable>
namespace tests::usage { using std::is_trivially_copy_assignable; }
#include <std.is_trivially_copy_constructible>
namespace tests::usage { using std::is_trivially_copy_constructible; }
#include <std.is_trivially_default_constructible>
namespace tests::usage { using std::is_trivially_default_constructible; }
#include <std.is_trivially_destructible>
namespace tests::usage { using std::is_trivially_destructible; }
#include <std.is_trivially_move_assignable>
namespace tests::usage { using std::is_trivially_move_assignable; }
#include <std.is_trivially_move_constructible>
namespace tests::usage { using std::is_trivially_move_constructible; }
#include <std.is_union>
namespace tests::usage { using std::is_union; }
#include <std.is_unsigned>
namespace tests::usage { using std::is_unsigned; }
#include <std.isupper>
namespace tests::usage { using std::isupper; }
#include <std.is_void>
namespace tests::usage { using std::is_void; }
#include <std.is_volatile>
namespace tests::usage { using std::is_volatile; }
#include <std.isxdigit>
namespace tests::usage { using std::isxdigit; }
#include <std.iterator>
namespace tests::usage { using std::iterator; }
#include <std.iterator_traits>
namespace tests::usage { using std::iterator_traits; }
#include <std.iter_swap>
namespace tests::usage { using std::iter_swap; }
#include <std.kilo>
namespace tests::usage { using std::kilo; }
#include <std.knuth_b>
namespace tests::usage { using std::knuth_b; }
#include <std.left>
namespace tests::usage { using std::left; }
#include <std.length_error>
namespace tests::usage { using std::length_error; }
#include <std.less>
namespace tests::usage { using std::less; }
#include <std.less_equal>
namespace tests::usage { using std::less_equal; }
#include <std.lexicographical_compare>
namespace tests::usage { using std::lexicographical_compare; }
#include <std.linear_congruential_engine>
namespace tests::usage { using std::linear_congruential_engine; }
#include <std.list>
namespace tests::usage { using std::list; }
#include <std.localtime>
namespace tests::usage { using std::localtime; }
#include <std.lock_guard>
namespace tests::usage { using std::lock_guard; }
#include <std.logical_and>
namespace tests::usage { using std::logical_and; }
#include <std.logical_not>
namespace tests::usage { using std::logical_not; }
#include <std.logical_or>
namespace tests::usage { using std::logical_or; }
#include <std.logic_error>
namespace tests::usage { using std::logic_error; }
#include <std.lognormal_distribution>
namespace tests::usage { using std::lognormal_distribution; }
#include <std.lower_bound>
namespace tests::usage { using std::lower_bound; }
#include <std.make_error_code>
namespace tests::usage { using std::make_error_code; }
#include <std.make_error_condition>
namespace tests::usage { using std::make_error_condition; }
#include <std.make_exception_ptr>
namespace tests::usage { using std::make_exception_ptr; }
#include <std.make_heap>
namespace tests::usage { using std::make_heap; }
#include <std.make_move_iterator>
namespace tests::usage { using std::make_move_iterator; }
#include <std.make_optional>
namespace tests::usage { using std::make_optional; }
#include <std.make_ostream_joiner>
namespace tests::usage { using std::make_ostream_joiner; }
#include <std.make_pair>
namespace tests::usage { using std::make_pair; }
#include <std.make_reverse_iterator>
namespace tests::usage { using std::make_reverse_iterator; }
#include <std.make_shared>
namespace tests::usage { using std::make_shared; }
#include <std.make_signed>
namespace tests::usage { using std::make_signed; }
#include <std.make_tuple>
namespace tests::usage { using std::make_tuple; }
#include <std.make_unique>
namespace tests::usage { using std::make_unique; }
#include <std.make_unsigned>
namespace tests::usage { using std::make_unsigned; }
#include <std.malloc>
namespace tests::usage { using std::malloc; }
#include <std.map>
namespace tests::usage { using std::map; }
#include <std.match_results>
namespace tests::usage { using std::match_results; }
#include <std.max>
namespace tests::usage { using std::max; }
#include <std.max_element>
namespace tests::usage { using std::max_element; }
#include <std.mega>
namespace tests::usage { using std::mega; }
#include <std.mem_fn>
namespace tests::usage { using std::mem_fn; }
#include <std.merge>
namespace tests::usage { using std::merge; }
#include <std.mersenne_twister_engine>
namespace tests::usage { using std::mersenne_twister_engine; }
#include <std.micro>
namespace tests::usage { using std::micro; }
#include <std.milli>
namespace tests::usage { using std::milli; }
#include <std.min>
namespace tests::usage { using std::min; }
#include <std.min_element>
namespace tests::usage { using std::min_element; }
#include <std.minmax>
namespace tests::usage { using std::minmax; }
#include <std.minmax_element>
namespace tests::usage { using std::minmax_element; }
#include <std.minstd_rand>
namespace tests::usage { using std::minstd_rand; }
#include <std.minstd_rand0>
namespace tests::usage { using std::minstd_rand0; }
#include <std.minus>
namespace tests::usage { using std::minus; }
#include <std.mismatch>
namespace tests::usage { using std::mismatch; }
#include <std.modulus>
namespace tests::usage { using std::modulus; }
#include <std.monostate>
namespace tests::usage { using std::monostate; }
#include <std.move>
namespace tests::usage { using std::move; }
#include <std.move_backward>
namespace tests::usage { using std::move_backward; }
#include <std.move_iterator>
namespace tests::usage { using std::move_iterator; }
#ifndef __ready10__
#warning NOT READY <std.move_sentinel>
#else
#include <std.move_sentinel>
namespace tests::usage { using std::move_sentinel; }
#endif
#include <std.mt19937>
namespace tests::usage { using std::mt19937; }
#include <std.mt19937_64>
namespace tests::usage { using std::mt19937_64; }
#include <std.multimap>
namespace tests::usage { using std::multimap; }
#include <std.multiplies>
namespace tests::usage { using std::multiplies; }
#include <std.multiset>
namespace tests::usage { using std::multiset; }
#include <std.mutex>
namespace tests::usage { using std::mutex; }
#include <std.nano>
namespace tests::usage { using std::nano; }
#include <std.negate>
namespace tests::usage { using std::negate; }
#include <std.negative_binomial_distribution>
namespace tests::usage { using std::negative_binomial_distribution; }
#include <std.nested_exception>
namespace tests::usage { using std::nested_exception; }
#include <std.next>
namespace tests::usage { using std::next; }
#include <std.next_permutation>
namespace tests::usage { using std::next_permutation; }
#include <std.noboolalpha>
namespace tests::usage { using std::noboolalpha; }
#include <std.none_of>
namespace tests::usage { using std::none_of; }
#include <std.normal_distribution>
namespace tests::usage { using std::normal_distribution; }
#include <std.noshowbase>
namespace tests::usage { using std::noshowbase; }
#include <std.noshowpoint>
namespace tests::usage { using std::noshowpoint; }
#include <std.noshowpos>
namespace tests::usage { using std::noshowpos; }
#include <std.noskipws>
namespace tests::usage { using std::noskipws; }
#include <std.not1>
namespace tests::usage { using std::not1; }
#include <std.not2>
namespace tests::usage { using std::not2; }
#include <std.not_equal_to>
namespace tests::usage { using std::not_equal_to; }
#include <std.not_fn>
namespace tests::usage { using std::not_fn; }
#include <std.nothrow>
namespace tests::usage { using std::nothrow; }
#include <std.nothrow_t>
namespace tests::usage { using std::nothrow_t; }
#include <std.nounitbuf>
namespace tests::usage { using std::nounitbuf; }
#include <std.nouppercase>
namespace tests::usage { using std::nouppercase; }
#include <std.nth_element>
namespace tests::usage { using std::nth_element; }
#include <std.nullopt>
namespace tests::usage { using std::nullopt; }
#include <std.nullopt_t>
namespace tests::usage { using std::nullopt_t; }
#include <std.nullptr_t>
namespace tests::usage { using std::nullptr_t; }
#include <std.numeric_limits>
namespace tests::usage { using std::numeric_limits; }
#include <std.oct>
namespace tests::usage { using std::oct; }
#include <std.ofstream>
namespace tests::usage { using std::ofstream; }
#include <std.optional>
namespace tests::usage { using std::optional; }
#include <std.ostream>
namespace tests::usage { using std::ostream; }
#include <std.ostreambuf_iterator>
namespace tests::usage { using std::ostreambuf_iterator; }
#include <std.ostream_iterator>
namespace tests::usage { using std::ostream_iterator; }
#include <std.ostream_joiner>
namespace tests::usage { using std::ostream_joiner; }
#include <std.ostringstream>
namespace tests::usage { using std::ostringstream; }
#include <std.out_of_range>
namespace tests::usage { using std::out_of_range; }
#include <std.output_iterator_tag>
namespace tests::usage { using std::output_iterator_tag; }
#include <std.overflow_error>
namespace tests::usage { using std::overflow_error; }
#include <std.owner_less>
namespace tests::usage { using std::owner_less; }
#include <std.pair>
namespace tests::usage { using std::pair; }
#include <std.partial_sort>
namespace tests::usage { using std::partial_sort; }
#include <std.partial_sort_copy>
namespace tests::usage { using std::partial_sort_copy; }
#include <std.partition>
namespace tests::usage { using std::partition; }
#include <std.partition_copy>
namespace tests::usage { using std::partition_copy; }
#include <std.partition_point>
namespace tests::usage { using std::partition_point; }
#include <std.peta>
namespace tests::usage { using std::peta; }
#include <std.pico>
namespace tests::usage { using std::pico; }
#include <std.piecewise_constant_distribution>
namespace tests::usage { using std::piecewise_constant_distribution; }
#include <std.piecewise_linear_distribution>
namespace tests::usage { using std::piecewise_linear_distribution; }
#include <std.plus>
namespace tests::usage { using std::plus; }
#include <std.pointer_safety>
namespace tests::usage { using std::pointer_safety; }
#include <std.pointer_traits>
namespace tests::usage { using std::pointer_traits; }
#include <std.poisson_distribution>
namespace tests::usage { using std::poisson_distribution; }
#include <std.pop_heap>
namespace tests::usage { using std::pop_heap; }
#include <std.prev>
namespace tests::usage { using std::prev; }
#include <std.prev_permutation>
namespace tests::usage { using std::prev_permutation; }
#include <std.ptrdiff_t>
namespace tests::usage { using std::ptrdiff_t; }
#include <std.push_heap>
namespace tests::usage { using std::push_heap; }
#include <std.put_money>
namespace tests::usage { using std::put_money; }
#include <std.put_time>
namespace tests::usage { using std::put_time; }
#include <std.queue>
namespace tests::usage { using std::queue; }
#include <std.quoted>
namespace tests::usage { using std::quoted; }
#include <std.random_access_iterator_tag>
namespace tests::usage { using std::random_access_iterator_tag; }
#include <std.random_device>
namespace tests::usage { using std::random_device; }
#include <std.random_shuffle>
namespace tests::usage { using std::random_shuffle; }
#include <std.range_error>
namespace tests::usage { using std::range_error; }
#include <std.rank>
namespace tests::usage { using std::rank; }
#include <std.ranlux24>
namespace tests::usage { using std::ranlux24; }
#include <std.ranlux24_base>
namespace tests::usage { using std::ranlux24_base; }
#include <std.ranlux48>
namespace tests::usage { using std::ranlux48; }
#include <std.ranlux48_base>
namespace tests::usage { using std::ranlux48_base; }
#include <std.ratio>
namespace tests::usage { using std::ratio; }
#include <std.ratio_add>
namespace tests::usage { using std::ratio_add; }
#include <std.ratio_divide>
namespace tests::usage { using std::ratio_divide; }
#include <std.ratio_equal>
namespace tests::usage { using std::ratio_equal; }
#include <std.ratio_greater>
namespace tests::usage { using std::ratio_greater; }
#include <std.ratio_greater_equal>
namespace tests::usage { using std::ratio_greater_equal; }
#include <std.ratio_less>
namespace tests::usage { using std::ratio_less; }
#include <std.ratio_less_equal>
namespace tests::usage { using std::ratio_less_equal; }
#include <std.ratio_multiply>
namespace tests::usage { using std::ratio_multiply; }
#include <std.ratio_not_equal>
namespace tests::usage { using std::ratio_not_equal; }
#include <std.ratio_subtract>
namespace tests::usage { using std::ratio_subtract; }
#include <std.raw_storage_iterator>
namespace tests::usage { using std::raw_storage_iterator; }
#include <std.rbegin>
namespace tests::usage { using std::rbegin; }
#include <std.realloc>
namespace tests::usage { using std::realloc; }
#include <std.ref>
namespace tests::usage { using std::ref; }
#include <std.reference_wrapper>
namespace tests::usage { using std::reference_wrapper; }
#include <std.regex>
namespace tests::usage { using std::regex; }
#include <std.regex_constants.error_type>
namespace tests::usage { using std::regex_constants::error_type; }
#include <std.regex_constants.match_flag_type>
namespace tests::usage { using std::regex_constants::match_flag_type; }
#include <std.regex_constants.syntax_option_type>
namespace tests::usage { using std::regex_constants::syntax_option_type; }
#include <std.regex_error>
namespace tests::usage { using std::regex_error; }
#include <std.regex_iterator>
namespace tests::usage { using std::regex_iterator; }
#include <std.regex_match>
namespace tests::usage { using std::regex_match; }
#include <std.regex_replace>
namespace tests::usage { using std::regex_replace; }
#include <std.regex_search>
namespace tests::usage { using std::regex_search; }
#include <std.regex_token_iterator>
namespace tests::usage { using std::regex_token_iterator; }
#include <std.regex_traits>
namespace tests::usage { using std::regex_traits; }
#include <std.remove>
namespace tests::usage { using std::remove; }
#include <std.remove_all_extents>
namespace tests::usage { using std::remove_all_extents; }
#include <std.remove_const>
namespace tests::usage { using std::remove_const; }
#include <std.remove_copy>
namespace tests::usage { using std::remove_copy; }
#include <std.remove_copy_if>
namespace tests::usage { using std::remove_copy_if; }
#ifndef __ready10__
#warning NOT READY <std.remove_cvref>
#else
#include <std.remove_cvref>
namespace tests::usage { using std::remove_cvref; }
#endif
#include <std.remove_cv>
namespace tests::usage { using std::remove_cv; }
#include <std.remove_extent>
namespace tests::usage { using std::remove_extent; }
#include <std.remove_if>
namespace tests::usage { using std::remove_if; }
#include <std.remove_pointer>
namespace tests::usage { using std::remove_pointer; }
#include <std.remove_reference>
namespace tests::usage { using std::remove_reference; }
#include <std.remove_volatile>
namespace tests::usage { using std::remove_volatile; }
#include <std.rend>
namespace tests::usage { using std::rend; }
#include <std.replace>
namespace tests::usage { using std::replace; }
#include <std.replace_copy>
namespace tests::usage { using std::replace_copy; }
#include <std.replace_copy_if>
namespace tests::usage { using std::replace_copy_if; }
#include <std.replace_if>
namespace tests::usage { using std::replace_if; }
#include <std.resetiosflags>
namespace tests::usage { using std::resetiosflags; }
#include <std.result_of>
namespace tests::usage { using std::result_of; }
#include <std.rethrow_exception>
namespace tests::usage { using std::rethrow_exception; }
#include <std.rethrow_if_nested>
namespace tests::usage { using std::rethrow_if_nested; }
#include <std.return_temporary_buffer>
namespace tests::usage { using std::return_temporary_buffer; }
#include <std.reverse>
namespace tests::usage { using std::reverse; }
#include <std.reverse_copy>
namespace tests::usage { using std::reverse_copy; }
#include <std.reverse_iterator>
namespace tests::usage { using std::reverse_iterator; }
#include <std.right>
namespace tests::usage { using std::right; }
#include <std.rotate>
namespace tests::usage { using std::rotate; }
#include <std.rotate_copy>
namespace tests::usage { using std::rotate_copy; }
#include <std.runtime_error>
namespace tests::usage { using std::runtime_error; }
#include <std.scientific>
namespace tests::usage { using std::scientific; }
#include <std.search>
namespace tests::usage { using std::search; }
#include <std.search_n>
namespace tests::usage { using std::search_n; }
#include <std.seed_seq>
namespace tests::usage { using std::seed_seq; }
#include <std.set>
namespace tests::usage { using std::set; }
#include <std.setbase>
namespace tests::usage { using std::setbase; }
#include <std.set_difference>
namespace tests::usage { using std::set_difference; }
#include <std.setfill>
namespace tests::usage { using std::setfill; }
#include <std.set_intersection>
namespace tests::usage { using std::set_intersection; }
#include <std.setiosflags>
namespace tests::usage { using std::setiosflags; }
#include <std.setprecision>
namespace tests::usage { using std::setprecision; }
#include <std.set_symmetric_difference>
namespace tests::usage { using std::set_symmetric_difference; }
#include <std.set_terminate>
namespace tests::usage { using std::set_terminate; }
#include <std.set_unexpected>
namespace tests::usage { using std::set_unexpected; }
#include <std.set_union>
namespace tests::usage { using std::set_union; }
#include <std.setw>
namespace tests::usage { using std::setw; }
#include <std.shared_ptr>
namespace tests::usage { using std::shared_ptr; }
#include <std.showbase>
namespace tests::usage { using std::showbase; }
#include <std.showpoint>
namespace tests::usage { using std::showpoint; }
#include <std.showpos>
namespace tests::usage { using std::showpos; }
#include <std.shuffle>
namespace tests::usage { using std::shuffle; }
#include <std.shuffle_order_engine>
namespace tests::usage { using std::shuffle_order_engine; }
#include <std.size>
namespace tests::usage { using std::size; }
#include <std.size_t>
namespace tests::usage { using std::size_t; }
#include <std.skipws>
namespace tests::usage { using std::skipws; }
#include <std.smatch>
namespace tests::usage { using std::smatch; }
#include <std.sort>
namespace tests::usage { using std::sort; }
#include <std.sort_heap>
namespace tests::usage { using std::sort_heap; }
#include <std.ssize_t>
namespace tests::usage { using std::ssize_t; }
#include <std.ssub_match>
namespace tests::usage { using std::ssub_match; }
#include <std.stable_partition>
namespace tests::usage { using std::stable_partition; }
#include <std.stable_sort>
namespace tests::usage { using std::stable_sort; }
#include <std.stack>
namespace tests::usage { using std::stack; }
#include <std.static_pointer_cast>
namespace tests::usage { using std::static_pointer_cast; }
#include <std.stod>
namespace tests::usage { using std::stod; }
#include <std.stof>
namespace tests::usage { using std::stof; }
#include <std.stoi>
namespace tests::usage { using std::stoi; }
#include <std.stol>
namespace tests::usage { using std::stol; }
#include <std.stold>
namespace tests::usage { using std::stold; }
#include <std.stoll>
namespace tests::usage { using std::stoll; }
#include <std.stoul>
namespace tests::usage { using std::stoul; }
#include <std.stoull>
namespace tests::usage { using std::stoull; }
#include <std.strcat>
namespace tests::usage { using std::strcat; }
#include <std.strcmp>
namespace tests::usage { using std::strcmp; }
#include <std.strcpy>
namespace tests::usage { using std::strcpy; }
#include <std.streambuf>
namespace tests::usage { using std::streambuf; }
#include <std.streamoff>
namespace tests::usage { using std::streamoff; }
#include <std.streampos>
namespace tests::usage { using std::streampos; }
#include <std.streamsize>
namespace tests::usage { using std::streamsize; }
#include <std.strftime>
namespace tests::usage { using std::strftime; }
#include <std.string>
namespace tests::usage { using std::string; }
#include <std.stringbuf>
namespace tests::usage { using std::stringbuf; }
#include <std.stringstream>
namespace tests::usage { using std::stringstream; }
#include <std.string_view>
namespace tests::usage { using std::string_view; }
#include <std.strlen>
namespace tests::usage { using std::strlen; }
#include <std.strncat>
namespace tests::usage { using std::strncat; }
#include <std.strncmp>
namespace tests::usage { using std::strncmp; }
#include <std.strncpy>
namespace tests::usage { using std::strncpy; }
#include <std.student_t_distribution>
namespace tests::usage { using std::student_t_distribution; }
#include <std.sub_match>
namespace tests::usage { using std::sub_match; }
#include <std.subtract_with_carry_engine>
namespace tests::usage { using std::subtract_with_carry_engine; }
#include <std.swap>
namespace tests::usage { using std::swap; }
#include <std.swap_ranges>
namespace tests::usage { using std::swap_ranges; }
#include <std.system_category>
namespace tests::usage { using std::system_category; }
#include <std.system_error>
namespace tests::usage { using std::system_error; }
#include <std.tera>
namespace tests::usage { using std::tera; }
#include <std.terminate>
namespace tests::usage { using std::terminate; }
#include <std.terminate_handler>
namespace tests::usage { using std::terminate_handler; }
#include <std.throw_with_nested>
namespace tests::usage { using std::throw_with_nested; }
#include <std.tie>
namespace tests::usage { using std::tie; }
#include <std.time>
namespace tests::usage { using std::time; }
#include <std.time_t>
namespace tests::usage { using std::time_t; }
#include <std.tm>
namespace tests::usage { using std::tm; }
#include <std.to_integer>
namespace tests::usage { using std::to_integer; }
#include <std.tolower>
namespace tests::usage { using std::tolower; }
#include <std.to_string>
namespace tests::usage { using std::to_string; }
#include <std.toupper>
namespace tests::usage { using std::toupper; }
#include <std.transform>
namespace tests::usage { using std::transform; }
#include <std.true_type>
namespace tests::usage { using std::true_type; }
#include <std.tuple>
namespace tests::usage { using std::tuple; }
#include <std.tuple_cat>
namespace tests::usage { using std::tuple_cat; }
#include <std.tuple_element>
namespace tests::usage { using std::tuple_element; }
#include <std.tuple_size>
namespace tests::usage { using std::tuple_size; }
#include <std.type_info>
namespace tests::usage { using std::type_info; }
#include <std.u16string_view>
namespace tests::usage { using std::u16string_view; }
#include <std.u32string_view>
namespace tests::usage { using std::u32string_view; }
#include <std.uint16_t>
namespace tests::usage { using std::uint16_t; }
#include <std.uint32_t>
namespace tests::usage { using std::uint32_t; }
#include <std.uint64_t>
namespace tests::usage { using std::uint64_t; }
#include <std.uint8_t>
namespace tests::usage { using std::uint8_t; }
#include <std.uintmax_t>
namespace tests::usage { using std::uintmax_t; }
#include <std.unary_function>
namespace tests::usage { using std::unary_function; }
#include <std.unary_negate>
namespace tests::usage { using std::unary_negate; }
#include <std.uncaught_exception>
namespace tests::usage { using std::uncaught_exception; }
#include <std.uncaught_exceptions>
namespace tests::usage { using std::uncaught_exceptions; }
#include <std.undeclare_no_pointers>
namespace tests::usage { using std::undeclare_no_pointers; }
#include <std.undeclare_reachable>
namespace tests::usage { using std::undeclare_reachable; }
#include <std.underflow_error>
namespace tests::usage { using std::underflow_error; }
#include <std.underlying_type>
namespace tests::usage { using std::underlying_type; }
#include <std.unexpected>
namespace tests::usage { using std::unexpected; }
#include <std.unexpected_handler>
namespace tests::usage { using std::unexpected_handler; }
#include <std.uniform_int_distribution>
namespace tests::usage { using std::uniform_int_distribution; }
#include <std.uniform_real_distribution>
namespace tests::usage { using std::uniform_real_distribution; }
#include <std.uninitialized_copy>
namespace tests::usage { using std::uninitialized_copy; }
#include <std.uninitialized_copy_n>
namespace tests::usage { using std::uninitialized_copy_n; }
#include <std.uninitialized_fill>
namespace tests::usage { using std::uninitialized_fill; }
#include <std.uninitialized_fill_n>
namespace tests::usage { using std::uninitialized_fill_n; }
#include <std.unique>
namespace tests::usage { using std::unique; }
#include <std.unique_copy>
namespace tests::usage { using std::unique_copy; }
#include <std.unique_ptr>
namespace tests::usage { using std::unique_ptr; }
#include <std.unitbuf>
namespace tests::usage { using std::unitbuf; }
#include <std.unordered_map>
namespace tests::usage { using std::unordered_map; }
#include <std.unordered_set>
namespace tests::usage { using std::unordered_set; }
#include <std.upper_bound>
namespace tests::usage { using std::upper_bound; }
#include <std.uppercase>
namespace tests::usage { using std::uppercase; }
#include <std.uses_allocator>
namespace tests::usage { using std::uses_allocator; }
#include <std.variant>
namespace tests::usage { using std::variant; }
#include <std.variant_alternative>
namespace tests::usage { using std::variant_alternative; }
#include <std.variant_alternative_t>
namespace tests::usage { using std::variant_alternative_t; }
#include <std.variant_npos>
namespace tests::usage { using std::variant_npos; }
#include <std.variant_size>
namespace tests::usage { using std::variant_size; }
#include <std.variant_size_v>
namespace tests::usage { using std::variant_size_v; }
#include <std.vector>
namespace tests::usage { using std::vector; }
#include <std.visit>
namespace tests::usage { using std::visit; }
#include <std.wcerr>
namespace tests::usage { using std::wcerr; }
#include <std.wcin>
namespace tests::usage { using std::wcin; }
#include <std.wclog>
namespace tests::usage { using std::wclog; }
#include <std.wcmatch>
namespace tests::usage { using std::wcmatch; }
#include <std.wcout>
namespace tests::usage { using std::wcout; }
#include <std.wcsub_match>
namespace tests::usage { using std::wcsub_match; }
#include <std.weak_ptr>
namespace tests::usage { using std::weak_ptr; }
#include <std.weibull_distribution>
namespace tests::usage { using std::weibull_distribution; }
#include <std.wfilebuf>
namespace tests::usage { using std::wfilebuf; }
#include <std.wfstream>
namespace tests::usage { using std::wfstream; }
#include <std.wifstream>
namespace tests::usage { using std::wifstream; }
#include <std.wios>
namespace tests::usage { using std::wios; }
#include <std.wiostream>
namespace tests::usage { using std::wiostream; }
#include <std.wistream>
namespace tests::usage { using std::wistream; }
#include <std.wistringstream>
namespace tests::usage { using std::wistringstream; }
#include <std.wofstream>
namespace tests::usage { using std::wofstream; }
#include <std.wostream>
namespace tests::usage { using std::wostream; }
#include <std.wostringstream>
namespace tests::usage { using std::wostringstream; }
#include <std.wregex>
namespace tests::usage { using std::wregex; }
#include <std.ws>
namespace tests::usage { using std::ws; }
#include <std.wsmatch>
namespace tests::usage { using std::wsmatch; }
#include <std.wssub_match>
namespace tests::usage { using std::wssub_match; }
#include <std.wstreambuf>
namespace tests::usage { using std::wstreambuf; }
#include <std.wstreampos>
namespace tests::usage { using std::wstreampos; }
#include <std.wstring>
namespace tests::usage { using std::wstring; }
#include <std.wstringbuf>
namespace tests::usage { using std::wstringbuf; }
#include <std.wstringstream>
namespace tests::usage { using std::wstringstream; }
#include <std.wstring_view>
namespace tests::usage { using std::wstring_view; }

//
// newish
//
#ifndef __ready10__
#warning NOT READY <std.as_bytes>
#warning NOT READY <std.as_writable_bytes>
#warning NOT READY <std.span>
#warning NOT READY <std.endian>
#warning NOT READY <std.dynamic_extent>
#warning NOT READY <std.hardware_constructive_interference_size>
#warning NOT READY <std.hardware_destructive_interference_size>
#else
#include <std.as_bytes>
namespace tests::usage { using std::as_bytes; }
#include <std.as_writable_bytes>
namespace tests::usage { using std::as_writable_bytes; }
#include <std.span>
namespace tests::usage { using std::span; }
#include <std.endian>
namespace tests::usage { using std::endian; }
#include <std.dynamic_extent>
namespace tests::usage { using std::dynamic_extent; }
#include <std.hardware_constructive_interference_size>
namespace tests::usage { using std::hardware_constructive_interference_size; }
#include <std.hardware_destructive_interference_size>
namespace tests::usage { using std::hardware_destructive_interference_size; }
#endif

// [[FIXTHIS]]  sort these into place
#include <std.integer_sequence>
namespace tests::usage { using std::integer_sequence; }
#include <std.index_sequence>
namespace tests::usage { using std::index_sequence; }
#include <std.make_integer_sequence>
namespace tests::usage { using std::make_integer_sequence; }
#include <std.make_index_sequence>
namespace tests::usage { using std::make_index_sequence; }
#include <std.index_sequence_for>
namespace tests::usage { using std::index_sequence_for; }
#include <std.apply>
namespace tests::usage { using std::apply; }
#include <std.make_from_tuple>
namespace tests::usage { using std::make_from_tuple; }
#include <std.ostream_joiner>
namespace tests::usage { using std::ostream_joiner; }

#ifndef __ready10__
#warning NOT READY <std.u8string>
#warning NOT READY <std.u8string_view>
#warning NOT READY <std.u16string>
#warning NOT READY <std.u16string_view>
#warning NOT READY <std.u32string>
#warning NOT READY <std.u32string_view>
#else
#include <std.u8string>
namespace tests::usage { using std::u8string; }
#include <std.u8string_view>
namespace tests::usage { using std::u8string_view; }
#include <std.u16string>
namespace tests::usage { using std::u16string; }
#include <std.u16string_view>
namespace tests::usage { using std::u16string_view; }
#include <std.u32string>
namespace tests::usage { using std::u32string; }
#include <std.u32string_view>
namespace tests::usage { using std::u32string_view; }
#endif

#include <std.adopt_lock>
namespace tests::usage { using std::adopt_lock; }
#include <std.adopt_lock_t>
namespace tests::usage { using std::adopt_lock_t; }
#include <std.async>
namespace tests::usage { using std::async; }
#include <std.begin>
namespace tests::usage { using std::begin; }
#include <std.call_once>
namespace tests::usage { using std::call_once; }
#include <std.condition_variable>
namespace tests::usage { using std::condition_variable; }
#include <std.condition_variable_any>
namespace tests::usage { using std::condition_variable_any; }
#include <std.cv_status>
namespace tests::usage { using std::cv_status; }
#include <std.defer_lock>
namespace tests::usage { using std::defer_lock; }
#include <std.defer_lock_t>
namespace tests::usage { using std::defer_lock_t; }
#include <std.end>
namespace tests::usage { using std::end; }
#include <std.future>
namespace tests::usage { using std::future; }
#include <std.future_category>
namespace tests::usage { using std::future_category; }
#include <std.future_errc>
namespace tests::usage { using std::future_errc; }
#include <std.future_error>
namespace tests::usage { using std::future_error; }
#include <std.future_status>
namespace tests::usage { using std::future_status; }
#include <std.get>
namespace tests::usage { using std::get; }
#include <std.lock>
namespace tests::usage { using std::lock; }
#include <std.notify_all_at_thread_exit>
namespace tests::usage { using std::notify_all_at_thread_exit; }
#include <std.once_flag>
namespace tests::usage { using std::once_flag; }
#include <std.packaged_task>
namespace tests::usage { using std::packaged_task; }
#include <std.promise>
namespace tests::usage { using std::promise; }
#include <std.recursive_mutex>
namespace tests::usage { using std::recursive_mutex; }
#include <std.recursive_timed_mutex>
namespace tests::usage { using std::recursive_timed_mutex; }
#include <std.scoped_lock>
namespace tests::usage { using std::scoped_lock; }
#include <std.shared_future>
namespace tests::usage { using std::shared_future; }
#include <std.shared_lock>
namespace tests::usage { using std::shared_lock; }
#include <std.shared_mutex>
namespace tests::usage { using std::shared_mutex; }
#include <std.shared_timed_mutex>
namespace tests::usage { using std::shared_timed_mutex; }
#include <std.this_thread.get_id>
namespace tests::usage { using std::this_thread::get_id; }
#include <std.this_thread.sleep_for>
namespace tests::usage { using std::this_thread::sleep_for; }
#include <std.this_thread.sleep_until>
namespace tests::usage { using std::this_thread::sleep_until; }
#include <std.this_thread.yield>
namespace tests::usage { using std::this_thread::yield; }
#include <std.this_thread>
namespace tests::usage { using namespace std::this_thread; }
#include <std.thread>
namespace tests::usage { using std::thread; }
#include <std.timed_mutex>
namespace tests::usage { using std::timed_mutex; }
#include <std.try_lock>
namespace tests::usage { using std::try_lock; }
#include <std.try_to_lock>
namespace tests::usage { using std::try_to_lock; }
#include <std.try_to_lock_t>
namespace tests::usage { using std::try_to_lock_t; }
#include <std.unique_lock>
namespace tests::usage { using std::unique_lock; }

// invoke with a 'k'
// invocable with a 'c'
#include <std.is_invocable>
namespace tests::usage { using std::is_invocable; }
#include <std.is_invocable_r>
namespace tests::usage { using std::is_invocable_r; }
#include <std.is_nothrow_invocable>
namespace tests::usage { using std::is_nothrow_invocable; }
#include <std.is_nothrow_invocable_r>
namespace tests::usage { using std::is_nothrow_invocable_r; }

// 
// END test
//
auto main() -> int {
  std::cout << "OK (all good)\n";
  return 0;
}
