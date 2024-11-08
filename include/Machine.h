#ifndef MACHINE_H
#define MACHINE_H

#include "Memory.h"
#include "Register.h"
#include <vector>

class Machine {
public:
    static const int REGISTER_COUNT = 4;
    static const int MEMORY_SIZE = 16;

    Machine();  // Constructor to initialize the machine with memory, registers, and program counter

    void loadProgram(const std::vector<int>& program);  // Load program into memory
    void fetchAndExecute();  // Fetch and execute one instruction
    void display();  // Display the machine's state (memory, registers, etc.)

    

private:
    Memory memory;  // Memory component
    Register registers[REGISTER_COUNT];  // Registers
    int pc;  // Program counter
};

#endif // MACHINE_H
