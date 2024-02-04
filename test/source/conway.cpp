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

  unsigned short width = 3;
  unsigned short height = 3;
  Conway conway(width, height);
  Conway other(conway);

  for (unsigned short y = 0; y < height; ++y) {
    for (unsigned short x = 0; x < width; ++x) {
      CHECK(conway.is_cell_on(x, y) == other.is_cell_on(x, y));
    }
  }
}

TEST_CASE("is_cell_on") {
  using namespace conway;

  unsigned short width = 3;
  unsigned short height = 3;
  Conway conway(width, height);

  for (unsigned short y = 0; y < height; ++y) {
    for (unsigned short x = 0; x < width; ++x) {
      CHECK(!conway.is_cell_on(x, y));
    }
  }
}

TEST_CASE("set_cell_on") {
  using namespace conway;

  Conway conway(1, 1);

  CHECK(!conway.is_cell_on(0, 0));

  conway.set_cell_on(0, 0);

  CHECK(conway.is_cell_on(0, 0));
}

TEST_CASE("set_cell_off") {
  using namespace conway;

  Conway conway(1, 1);

  CHECK(!conway.is_cell_on(0, 0));

  conway.set_cell_on(0, 0);

  CHECK(conway.is_cell_on(0, 0));

  conway.set_cell_off(0, 0);

  CHECK(!conway.is_cell_on(0, 0));
}

TEST_CASE("toggle_cell") {
  using namespace conway;

  Conway conway(1, 1);

  CHECK(!conway.is_cell_on(0, 0));

  conway.toggle_cell(0, 0);

  CHECK(conway.is_cell_on(0, 0));

  conway.toggle_cell(0, 0);

  CHECK(!conway.is_cell_on(0, 0));
}

TEST_CASE("get_neighbour_count") {
  using namespace conway;

  unsigned short width = 3;
  unsigned short height = 3;
  Conway conway(width, height);

  conway.set_cell_on(1, 1);

  CHECK(conway.get_neighbour_count(1, 1) == 0);

  for (unsigned short y = 0; y < height; ++y) {
    for (unsigned short x = 0; x < width; ++x) {
      if (x == 1 && y == 1) continue;
      CHECK(conway.get_neighbour_count(x, y) == 1);
    }
  }

  conway.set_cell_off(1, 1);

  for (unsigned short y = 0; y < height; ++y) {
    for (unsigned short x = 0; x < width; ++x) {
      CHECK(conway.get_neighbour_count(x, y) == 0);
    }
  }
}

TEST_CASE("get_neighbour_count (on boundary)") {
  using namespace conway;

  unsigned short width = 3;
  unsigned short height = 3;
  Conway conway(width, height);

  conway.set_cell_on(0, 0);

  CHECK(conway.get_neighbour_count(0, 0) == 0);
  CHECK(conway.get_neighbour_count(1, 0) == 1);
  CHECK(conway.get_neighbour_count(2, 0) == 0);
  CHECK(conway.get_neighbour_count(0, 1) == 1);
  CHECK(conway.get_neighbour_count(1, 1) == 1);
  CHECK(conway.get_neighbour_count(2, 1) == 0);
  CHECK(conway.get_neighbour_count(0, 2) == 0);
  CHECK(conway.get_neighbour_count(1, 2) == 0);
  CHECK(conway.get_neighbour_count(2, 2) == 0);

  conway.set_cell_off(0, 0);

  for (unsigned short y = 0; y < height; ++y) {
    for (unsigned short x = 0; x < width; ++x) {
      CHECK(conway.get_neighbour_count(x, y) == 0);
    }
  }
}

TEST_CASE("next_generation") {
  using namespace conway;

  Conway conway(3, 3);

  conway.set_cell_on(0, 1);
  conway.set_cell_on(1, 0);
  conway.set_cell_on(1, 1);

  conway.next_generation();

  CHECK(conway.is_cell_on(0, 0));
  CHECK(conway.is_cell_on(1, 0));
  CHECK(conway.is_cell_on(2, 0) == false);
  CHECK(conway.is_cell_on(0, 1));
  CHECK(conway.is_cell_on(1, 1));
  CHECK(conway.is_cell_on(2, 1) == false);
  CHECK(conway.is_cell_on(0, 2) == false);
  CHECK(conway.is_cell_on(1, 2) == false);
  CHECK(conway.is_cell_on(2, 2) == false);
}

TEST_CASE("next_generation #2") {
  using namespace conway;

  Conway conway(3, 3);

  conway.set_cell_on(1, 0);
  conway.set_cell_on(1, 1);
  conway.set_cell_on(2, 2);

  conway.next_generation();

  CHECK(conway.is_cell_on(0, 0) == false);
  CHECK(conway.is_cell_on(1, 0) == false);
  CHECK(conway.is_cell_on(2, 0) == false);
  CHECK(conway.is_cell_on(0, 1) == false);
  CHECK(conway.is_cell_on(1, 1));
  CHECK(conway.is_cell_on(2, 1));
  CHECK(conway.is_cell_on(0, 2) == false);
  CHECK(conway.is_cell_on(1, 2) == false);
  CHECK(conway.is_cell_on(2, 2) == false);
}
