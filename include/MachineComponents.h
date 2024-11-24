#ifndef MACHINECOMPONENTS_H
#define MACHINECOMPONENTS_H

#include <vector>
#include <string>
#include <iostream> // Needed for std::cout in displayContent


class ProgramCounter {
private:
    int value;
public:
    ProgramCounter();
    void increment();
    void reset();
    int getCurrentValue() const;
    bool hasNextInstruction(int maxInstructions) const; // Updated method
    

};

class InstructionRegister {
private:
    std::string instruction;
public:
    InstructionRegister();
    void setInstruction(const std::string& instruction);
    std::string getInstruction() const;
    void clear();
};

class Memory {
private:
    std::vector<std::string> instructions;  // Vector to hold instructions
public:
    Memory();
    void loadInstructions(const std::vector<std::string>& instructions);
    void addInstruction(const std::string& instruction);  // Method to add single instruction
    std::string getInstruction(int address) const;
    void displayMemory() const;
    std::vector<std::string> getInstructions() const {
       return instructions;  // Return the full list of instructions in memory
    }
};

class Register {
private:
    unsigned int value;
public:
    Register() : value(0) {}
    void setValue(unsigned int newValue) {
        value = newValue;  // Set the new value
    }
    unsigned int getValue() const {
        return value;  // Return the current value
    }
};

class Screen {
private:
    std::vector<std::string> content; // Stores the output
public:
    void writeLine(const std::string& line); // Add a line to the screen
    void clear(); // Clear the screen content
    void displayContent() const; // Display all content
};


extern Register R0; // Declare R0 globally
extern Register R1; // Declare R1 globally
extern Register R2; // Declare R2 globally
extern Register R3;
extern Register R4;
extern Register R5;
extern Register R6;
extern int memory[256];

#endif
