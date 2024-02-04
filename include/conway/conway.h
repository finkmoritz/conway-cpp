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
    bool isCellOn(short x, short y);

    /**
     * @brief Sets the cell at the given coordinates to the on state
     */
    void setCellOn(short x, short y);

    /**
     * @brief Returns the number of live neighbour cells for the cells at the given coordinates
     */
    short getNeighbourCount(short x, short y);
  };

}  // namespace conway
