#pragma once

#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <iostream>
#include <stack>
#include <bitset>

/// @brief A Chip8 interpreter/emulator.
class Chip8
{
private:
    /// Chip 8 RAM
    unsigned char memory[4096];
    bool displayBuffer[64 * 32];

    /// Stores addresses that subroutines return to after completing
    std::stack<short> stack;

    /// Program counter for the currently executing address
    short counter;

    unsigned char soundRegister;
    unsigned char delayRegister;

    /// general purpose registers
    unsigned char V[16];

    /// generally used for memory addresses
    short I;

    /// @brief Reads and executes a single opcode from memory
    void cycle();

public:
    /// @brief Creates a Chip8 object from a ROM file
    /// @param romPath The file path to the ROM to run
    Chip8(std::string romPath);

    /// @brief Run the main "game" loop
    /// @return True if there was an error, and false if there wasn't
    bool execute();
};