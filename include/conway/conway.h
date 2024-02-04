#pragma once

namespace conway {

  /**
   * @brief A class for simulations based on Conway's Game of Life
   */
  class Conway {
    short width;
    short height;
    char* cells;

  public:
    /**
     * @brief Creates a new Conway's Game of Life
     * @param width Width of the cell map
     * @param height Height of the cell map
     */
    Conway(short width, short height);

    /**
     * @brief Destructs this Conway's Game of Life
     */
    ~Conway();

    /**
     * @brief Prints the cell map
     */
    void print();
  };

}  // namespace conway
