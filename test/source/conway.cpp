#include <conway/conway.h>
#include <conway/version.h>
#include <doctest/doctest.h>

#include <string>

TEST_CASE("Version") { CHECK(std::string(CONWAY_VERSION) == std::string("1.0")); }

TEST_CASE("Constructor") {
  using namespace conway;

  Conway conway(1, 1);
}

TEST_CASE("Copy Constructor") {
  using namespace conway;

  short width = 3;
  short height = 3;
  Conway conway(width, height);
  Conway other(conway);

  for (short y = 0; y < height; ++y) {
    for (short x = 0; x < width; ++x) {
      CHECK(conway.isCellOn(x, y) == other.isCellOn(x, y));
    }
  }
}

TEST_CASE("IsCellOn") {
  using namespace conway;

  short width = 3;
  short height = 3;
  Conway conway(width, height);

  for (short y = 0; y < height; ++y) {
    for (short x = 0; x < width; ++x) {
      CHECK(!conway.isCellOn(x, y));
    }
  }
}
