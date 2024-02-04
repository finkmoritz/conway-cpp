#pragma once

#include <list>

namespace conway {

  /**
   * @brief A class for simulations based on Conway's Game of Life
   */
  class Conway {
    unsigned short width;
    unsigned short height;
    char* cells;
    std::list<unsigned short> change_list;

  public:
    /**
     * @brief Creates a new Conway's Game of Life
     * @param width Width of the cell map
     * @param height Height of the cell map
     */
    Conway(unsigned short width, unsigned short height);

    /**
     * @brief Destructs this Conway's Game of Life
     */
    ~Conway();

    /**
     * @brief Copy constructor
     * @param other Object to copy from
     */
    Conway(Conway& other);

    /**
     * @brief Prints the cell map
     */
    void print();

    /**
     * @brief Returns true if the cell at the given coordinates is on
     */
    bool is_cell_on(unsigned short x, unsigned short y);

    /**
     * @brief Sets the cell at the given coordinates to the on state
     */
    void set_cell_on(unsigned short x, unsigned short y);

    /**
     * @brief Sets the cell at the given coordinates to the off state
     */
    void set_cell_off(unsigned short x, unsigned short y);

    /**
     * @brief Toggles the cell state at the given coordinates
     */
    void toggle_cell(unsigned short x, unsigned short y);

    /**
     * @brief Returns the number of live neighbour cells for the cells at the given coordinates
     */
    unsigned short get_neighbour_count(unsigned short x, unsigned short y);

    /**
     * @brief Computes the next generation
     */
    void next_generation();
  };

}  // namespace conway
