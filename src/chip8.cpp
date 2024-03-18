#include "chip8.hpp"

Chip8::Chip8(std::string romPath) : memory{0},
                                    displayBuffer{0},
                                    counter{512},
                                    soundRegister{0},
                                    delayRegister{0},
                                    V{0},
                                    I{0}
{
    std::streampos size;
    char *romBuffer;
    std::ifstream romFile;
    romFile.open(romPath, std::ios::ate | std::ios::binary | std::ios::in);
    // first 512 bytes are reserved for the interpreter itself
    if (romFile.is_open())
    {
        size = romFile.tellg();
        romBuffer = new char[size];
        romFile.seekg(0, std::ios::beg);
        romFile.read(romBuffer, size);
        romFile.close();

        std::cout << "Read " << romPath << std::endl;
        // read romBuffer into program memory
        for (int i = 0; i < size; i++)
        {
            memory[i + 512] = romBuffer[i];
        }
    }
    else
    {
        std::cerr << "Failed to read rom file!" << std::endl;
    }
}

void Chip8::cycle()
{
    unsigned char byte1 = memory[counter];
    unsigned char byte2 = memory[counter + 1];
    // combine the first 2 bytes into a single instruction
    unsigned short instruction = short(byte1 << 8) + byte2;
    std::cout << std::hex << instruction << std::endl;
    std::cout << std::hex << (instruction >> 12) << std::endl;
    // instructions with a leading 0
    if ((instruction >> 12) == 0x0)
    {
        std::cout << "Leading 0 instruction\n";
        if (instruction == 0x00e0)
        {
            std::cout << "Clear screen\n";
        }
    }
}

bool Chip8::execute()
{
    sf::RenderWindow window(sf::VideoMode(64, 32), "Chip8");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        cycle();

        window.display();
    }

    return false;
}