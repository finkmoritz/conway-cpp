#include <doctest/doctest.h>
#include <conway/conway.h>
#include <conway/version.h>

#include <string>

TEST_CASE("Conway") {
  using namespace conway;

  Conway conway("Tests");

  CHECK(conway.greet(LanguageCode::EN) == "Hello, Tests!");
  CHECK(conway.greet(LanguageCode::DE) == "Hallo Tests!");
  CHECK(conway.greet(LanguageCode::ES) == "¡Hola Tests!");
  CHECK(conway.greet(LanguageCode::FR) == "Bonjour Tests!");
}

TEST_CASE("Conway version") {
  static_assert(std::string_view(CONWAY_VERSION) == std::string_view("1.0"));
  CHECK(std::string(CONWAY_VERSION) == std::string("1.0"));
}
