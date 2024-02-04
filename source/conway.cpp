#include <conway/conway.h>

#include <iostream>
#include <list>

using namespace conway;

Conway::Conway(unsigned short _width, unsigned short _height)
    : width(std::move(_width)), height(std::move(_height)) {
  cells = new char[_width * _height]();

  for (unsigned short i = 0; i < _width * _height; ++i) {
    change_list.push_back(i);
  }
}

Conway::~Conway() { delete[] cells; }

Conway::Conway(Conway& other) : width(other.width), height(other.height) {
  cells = new char[other.width * other.height]();
  change_list = std::list<unsigned short>(other.change_list);
}

void Conway::print() {
  for (unsigned short y = 0; y < height; ++y) {
    for (unsigned short x = 0; x < width; ++x) {
      std::cout << (cells[y * width + x] & 0x01) << " ";
    }
    std::cout << std::endl;
  }
}

bool Conway::is_cell_on(unsigned short x, unsigned short y) { return cells[y * width + x] & 0x01; }

void Conway::set_cell_on(unsigned short x, unsigned short y) {
  char* cell = cells + y * width + x;

  *cell |= 0x01;

  if (y > 0) {
    if (x > 0) cell[-width - 1] += 2;
    cell[-width] += 2;
    if (x < width - 1) cell[-width + 1] += 2;
  }

  if (x > 0) cell[-1] += 2;
  if (x < width - 1) cell[+1] += 2;

  if (y < height - 1) {
    if (x > 0) cell[+width - 1] += 2;
    cell[+width] += 2;
    if (x < width - 1) cell[+width + 1] += 2;
  }
}

void Conway::set_cell_off(unsigned short x, unsigned short y) {
  char* cell = cells + y * width + x;

  *cell &= ~0x01;

  if (y > 0) {
    if (x > 0) cell[-width - 1] -= 2;
    cell[-width] -= 2;
    if (x < width - 1) cell[-width + 1] -= 2;
  }

  if (x > 0) cell[-1] -= 2;
  if (x < width - 1) cell[+1] -= 2;

  if (y < height - 1) {
    if (x > 0) cell[+width - 1] -= 2;
    cell[+width] -= 2;
    if (x < width - 1) cell[+width + 1] -= 2;
  }
}

void Conway::toggle_cell(unsigned short x, unsigned short y) {
  if (is_cell_on(x, y)) {
    set_cell_off(x, y);
  } else {
    set_cell_on(x, y);
  }
}

unsigned short Conway::get_neighbour_count(unsigned short x, unsigned short y) {
  return cells[y * width + x] >> 1;
}

void Conway::next_generation() {
  change_list.remove_if([this](int index) {
    unsigned short neighbourCount = cells[index] >> 1;
    if (is_cell_on(index % width, index / width)) {
      return neighbourCount == 2 || neighbourCount == 3;
    } else {
      return neighbourCount != 3;
    }
  });

  for (unsigned short index : change_list) {
    toggle_cell(index % width, index / width);
  }
}
