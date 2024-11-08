#include "Machine.h"
#include <iostream>

Machine::Machine() : pc(0) {
    // Initialize registers (no need for zero initialization since it's done in Register class)
    for (int i = 0; i < REGISTER_COUNT; i++) {
        registers[i] = Register();
    }
}

void Machine::loadProgram(const std::vector<int>& program) {
    // Load the program into memory
    for (size_t i = 0; i < program.size(); i++) {
        memory.store(i, program[i]);
    }
}

void Machine::fetchAndExecute() {
    // Fetch instruction from memory using program counter
    int instruction = memory.load(pc);
    pc++;

    // For simplicity, assume instruction is in the form: opcode (4 bits) | operand (12 bits)
    int opCode = (instruction >> 12) & 0xF;  // Extract the opcode (first 4 bits)
    int operand = instruction & 0xFFF;  // Extract the operand (last 12 bits)

    // Decode and execute the instruction based on opCode
    switch (opCode) {
        case 1:  // LOAD operation
            {
                int reg = (operand >> 8) & 0xF;  // Extract register index from operand
                int addr = operand & 0xFF;  // Extract memory address from operand
                registers[reg].setValue(memory.load(addr));
                break;
            }
        case 3:  // STORE operation
            {
                int reg = (operand >> 8) & 0xF;
                int addr = operand & 0xFF;
                memory.store(addr, registers[reg].getValue());
                break;
            }
        default:
            std::cout << "Unknown opcode " << opCode << std::endl;
            break;
    }
}

void Machine::display() {
    std::cout << "PC: " << pc << std::endl;

    std::cout << "Memory: ";
    for (int i = 0; i < MEMORY_SIZE; i++) {
        std::cout << memory.load(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "Registers: ";
    for (int i = 0; i < REGISTER_COUNT; i++) {
        std::cout << registers[i].getValue() << " ";
    }
    std::cout << std::endl;
}

