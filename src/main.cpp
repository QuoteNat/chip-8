#include <iostream>
#include <string>
#include "chip8.hpp"

int main(int argc, char* argv[]) {
  std::string romPath;
  // Leaving max arguments at 1 until arguments other than the rom path are needed
  for (int i=1; i < 2; i++) {
    romPath = std::string(argv[i]);
    std::cout << romPath << std::endl;
  }

  Chip8 chip8 = Chip8(romPath);
  return 0;
}
