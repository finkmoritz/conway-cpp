#include <conway/conway.h>
#include <conway/version.h>
#include <doctest/doctest.h>

#include <string>

TEST_CASE("Conway constructor") {
  using namespace conway;

  Conway conway(3, 3);
}

TEST_CASE("Conway version") {
  static_assert(std::string_view(CONWAY_VERSION) == std::string_view("1.0"));
  CHECK(std::string(CONWAY_VERSION) == std::string("1.0"));
}
