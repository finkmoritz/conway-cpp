#include <conway/conway.h>
#include <conway/version.h>

#include <cxxopts.hpp>

auto main(int argc, char** argv) -> int {
  cxxopts::Options options(*argv, "Simulate Conway's Game of Life");

  short width;
  short height;

  // clang-format off
  options.add_options()
    ("h,help", "Show help")
    ("v,version", "Print the current version number")
    ("width", "Set the width of the cell map", cxxopts::value(width)->default_value("8"))
    ("height", "Set the height of the cell map", cxxopts::value(height)->default_value("8"))
  ;
  // clang-format on

  auto result = options.parse(argc, argv);

  if (result["help"].as<bool>()) {
    std::cout << options.help() << std::endl;
    return 0;
  }

  if (result["version"].as<bool>()) {
    std::cout << "Conway, version " << CONWAY_VERSION << std::endl;
    return 0;
  }

  if (width < 1) {
    std::cerr << "Option 'width' must be a positive number!" << std::endl;
    return 1;
  }

  if (height < 1) {
    std::cerr << "Option 'height' must be a positive number!" << std::endl;
    return 1;
  }

  conway::Conway conway(width, height);
  conway.print();

  return 0;
}
