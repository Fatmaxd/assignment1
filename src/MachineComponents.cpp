#include "MachineComponents.h"
#include <iostream>

Register R0; // Define R0 globally
Register R1; // Define R1 globally
Register R2; // Define R2 globally
Register R3;
Register R4;
Register R5;
Register R6;
int memory[256];
ProgramCounter::ProgramCounter() : value(0) {}

// Method to increment the Program Counter
void ProgramCounter::increment() {
    // Increment if the value is within the number of instructions
    value++;
}

void ProgramCounter::reset() {
    value = 0;
}

int ProgramCounter::getCurrentValue() const {
    return value;
}

// Method to check if there are more instructions in memory
bool ProgramCounter::hasNextInstruction(int maxInstructions) const {
    return value < maxInstructions;  // Check if PC is less than the total number of instructions
}


InstructionRegister::InstructionRegister() : instruction("") {}

void InstructionRegister::setInstruction(const std::string& instruction) {
    this->instruction = instruction;
}

std::string InstructionRegister::getInstruction() const {
    return instruction;
}

void InstructionRegister::clear() {
    instruction.clear();
}

Memory::Memory() {}

void Memory::loadInstructions(const std::vector<std::string>& instructions) {
    this->instructions = instructions;
    std::cout << "Memory loaded with instructions:\n";
    for (size_t i = 0; i < this->instructions.size(); ++i) {
        std::cout << "Address " << i << ": " << this->instructions[i] << std::endl;
    }
}



void Memory::addInstruction(const std::string& instruction) {
    instructions.push_back(instruction);  // Add the instruction to memory
}

std::string Memory::getInstruction(int address) const {
    if (address >= 0 && address < static_cast<int>(instructions.size())) {
        return instructions[address];
    }
    std::cerr << "Error: Attempted to access invalid memory address: " << address << std::endl;
    return "";  // Returning empty string for invalid access
}


void Memory::displayMemory() const {
    for (const auto& instruction : instructions) {
        std::cout << instruction << " ";
    }
    std::cout << std::endl;
}

void Screen::writeLine(const std::string& line) {
    content.push_back(line);
}

void Screen::clear() {
    content.clear();
}

void Screen::displayContent() const {
    for (const auto& line : content) {
        std::cout << line << std::endl;
    }
} 