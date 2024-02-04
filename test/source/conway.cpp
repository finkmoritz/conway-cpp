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

TEST_CASE("SetCellOn") {
  using namespace conway;

  Conway conway(1, 1);

  CHECK(!conway.isCellOn(0, 0));

  conway.setCellOn(0, 0);

  CHECK(conway.isCellOn(0, 0));
}

TEST_CASE("SetCellOff") {
  using namespace conway;

  Conway conway(1, 1);

  CHECK(!conway.isCellOn(0, 0));

  conway.setCellOn(0, 0);

  CHECK(conway.isCellOn(0, 0));

  conway.setCellOff(0, 0);

  CHECK(!conway.isCellOn(0, 0));
}

TEST_CASE("GetNeighbourCount") {
  using namespace conway;

  short width = 3;
  short height = 3;
  Conway conway(width, height);

  conway.setCellOn(1, 1);

  CHECK(conway.getNeighbourCount(1, 1) == 0);

  for (short y = 0; y < height; ++y) {
    for (short x = 0; x < width; ++x) {
      if (x == 1 && y == 1) continue;
      CHECK(conway.getNeighbourCount(x, y) == 1);
    }
  }

  conway.setCellOff(1, 1);

  for (short y = 0; y < height; ++y) {
    for (short x = 0; x < width; ++x) {
      CHECK(conway.getNeighbourCount(x, y) == 0);
    }
  }
}

TEST_CASE("GetNeighbourCount (on boundary)") {
  using namespace conway;

  short width = 3;
  short height = 3;
  Conway conway(width, height);

  conway.setCellOn(0, 0);

  CHECK(conway.getNeighbourCount(0, 0) == 0);
  CHECK(conway.getNeighbourCount(1, 0) == 1);
  CHECK(conway.getNeighbourCount(2, 0) == 0);
  CHECK(conway.getNeighbourCount(0, 1) == 1);
  CHECK(conway.getNeighbourCount(1, 1) == 1);
  CHECK(conway.getNeighbourCount(2, 1) == 0);
  CHECK(conway.getNeighbourCount(0, 2) == 0);
  CHECK(conway.getNeighbourCount(1, 2) == 0);
  CHECK(conway.getNeighbourCount(2, 2) == 0);

  conway.setCellOff(0, 0);

  for (short y = 0; y < height; ++y) {
    for (short x = 0; x < width; ++x) {
      CHECK(conway.getNeighbourCount(x, y) == 0);
    }
  }
}
