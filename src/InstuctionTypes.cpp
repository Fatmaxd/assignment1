// InstructionTypes.cpp
#include "Instruction.h"
#include "Machine.h"

// Load Instruction: Loads value from memory to a register
class LoadInstruction : public Instruction {
private:
    int reg;     // Register number
    int address; // Memory address to load from

public:
    LoadInstruction(int instruction) {
        reg = (instruction >> 4) & 0x0F;
        address = instruction & 0xFF;
    }

    void execute(Machine& machine) override {
        // Load value from memory to register
        machine.getRegisters()[reg] = machine.getMemory()[address];
    }
};

// Store Instruction: Stores value from register to memory
class StoreInstruction : public Instruction {
private:
    int reg;     // Register number
    int address; // Memory address to store in

public:
    StoreInstruction(int instruction) {
        reg = (instruction >> 4) & 0x0F;
        address = instruction & 0xFF;
    }

    void execute(Machine& machine) override {
        // Store value from register to memory
        machine.getMemory()[address] = machine.getRegisters()[reg];
    }
};

// Add Instruction: Adds values from two registers and stores the result in a third register
class AddInstruction : public Instruction {
private:
    int reg1, reg2, resultReg;

public:
    AddInstruction(int instruction) {
        reg1 = (instruction >> 4) & 0x0F;
        reg2 = (instruction >> 0) & 0x0F;
        resultReg = (instruction >> 8) & 0x0F;
    }

    void execute(Machine& machine) override {
        // Add the values of two registers and store in the result register
        machine.getRegisters()[resultReg] = machine.getRegisters()[reg1] + machine.getRegisters()[reg2];
    }
};
