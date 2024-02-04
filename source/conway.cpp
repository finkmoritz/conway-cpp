#include <conway/conway.h>

#include <iostream>

using namespace conway;

Conway::Conway(short _width, short _height) : width(std::move(_width)), height(std::move(_height)) {
  cells = new char[_width * _height]();
}

Conway::~Conway() { delete[] cells; }

Conway::Conway(Conway &other) : width(other.width), height(other.height) {
  cells = new char[other.width * other.height]();
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
