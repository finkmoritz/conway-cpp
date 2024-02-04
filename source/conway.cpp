#include <conway/conway.h>

#include <iostream>
#include <list>

using namespace conway;

Conway::Conway(short _width, short _height) : width(std::move(_width)), height(std::move(_height)) {
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
  for (short y = 0; y < height; ++y) {
    for (short x = 0; x < width; ++x) {
      std::cout << (cells[y * width + x] & 0x01) << " ";
    }
    std::cout << std::endl;
  }
}

bool Conway::isCellOn(short x, short y) { return cells[y * width + x] & 0x01; }

void Conway::setCellOn(short x, short y) {
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

void Conway::setCellOff(short x, short y) {
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

void Conway::toggleCell(short x, short y) {
  if (isCellOn(x, y)) {
    setCellOff(x, y);
  } else {
    setCellOn(x, y);
  }
}

short Conway::getNeighbourCount(short x, short y) { return cells[y * width + x] >> 1; }

void Conway::nextGeneration() {
  change_list.remove_if([this](int index) {
    unsigned short neighbourCount = cells[index] >> 1;
    if (isCellOn(index % width, index / width)) {
      return neighbourCount == 2 || neighbourCount == 3;
    } else {
      return neighbourCount != 3;
    }
  });

  for (unsigned short index : change_list) {
    toggleCell(index % width, index / width);
  }
}
