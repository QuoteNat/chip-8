#include "chip8.hpp"

Chip8::Chip8(std::string romPath) {
    std::streampos size;
    char * romBuffer;
    std::ifstream romFile;
    romFile.open(romPath, std::ios::ate | std::ios::binary | std::ios::in);
    // first 512 bytes are reserved for the interpreter itself
    if (romFile.is_open()) {
        size = romFile.tellg();
        romBuffer = new char [size];
        romFile.seekg(0, std::ios::beg);
        romFile.read(romBuffer, size);
        romFile.close();

        std::cout << "Read " << romPath << std::endl;
        // read romBuffer into program memory
        for (int i=0; i<size; i++) {
            std::cout << romBuffer[i];
            memory[i+512] = romBuffer[i];
        }
    } else {
        std::cerr << "Failed to read rom file!" << std::endl;
    }
}