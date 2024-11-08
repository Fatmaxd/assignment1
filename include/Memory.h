#ifndef MEMORY_H
#define MEMORY_H

#include <vector>

class Memory {
public:
    static const int MEMORY_SIZE = 16;

    Memory();  // Constructor to initialize memory with default values (e.g., zero)

    void store(int address, int value);  // Store a value in memory at a specific address
    int load(int address);  // Load a value from memory at a specific address

private:
    int memory[MEMORY_SIZE];  // Array to hold memory values
};

#endif // MEMORY_H
