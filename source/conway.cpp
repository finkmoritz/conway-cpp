#include <conway/conway.h>

#include <iostream>

using namespace conway;

Conway::Conway(short _width, short _height) : width(std::move(_width)), height(std::move(_height)) {
  cells = new char[_width * _height];
}

Conway::~Conway() { delete[] cells; }

void Conway::print() {
  for (short h = 0; h < height; ++h) {
    for (short w = 0; w < width; ++w) {
      std::cout << (cells[h * width + w] & 0x01) << " ";
    }
    std::cout << std::endl;
  }
}
