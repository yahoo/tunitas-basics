// -*- c++ -*- 54ae9c5b-49f4-416e-841a-cac19b207806
#pragma once
#include <httpserver>
namespace httpserver {
  template<typename CHILD> using Resource = httpserver::http_resource<CHILD>;
}
