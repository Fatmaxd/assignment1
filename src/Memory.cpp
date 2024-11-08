#include "../include/Memory.h"  // Correct path from src to include


Memory::Memory() {
    // Initialize memory with zero
    for (int i = 0; i < MEMORY_SIZE; i++) {
        memory[i] = 0;
    }
}

void Memory::store(int address, int value) {
    if (address >= 0 && address < MEMORY_SIZE) {
        memory[address] = value;
    }
}

int Memory::load(int address) {
    if (address >= 0 && address < MEMORY_SIZE) {
        return memory[address];
    }
    return 0;  // Return zero if address is out of range
}
