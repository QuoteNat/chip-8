#pragma once

#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <iostream>
#include <stack>

/**
 * Represents a Chip-8 interpreter
 */
class Chip8
{
private:
    // Chip 8 RAM
    unsigned char memory[4096];
    bool displayBuffer[64 * 32];
    // Stores addresses that subroutines return to after completing
    std::stack<short> stack;
    // Program counter for the currently executing address
    short counter;
    // REGISTERS
    unsigned char soundRegister;
    unsigned char delayRegister;
    // general purpose registers
    unsigned char V[16];
    // generally used for memory addresses
    short I;

public:
    /**
     * Initializes a chip8 interpreter with a given rom
     * @param rom The path to the chip8 rom to be run.
     */
    Chip8(std::string romPath);
};