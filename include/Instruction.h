// Instruction.h
#ifndef INSTRUCTION_H
#define INSTRUCTION_H

class Machine; // Forward declaration

class Instruction {
public:
    virtual void execute(Machine& machine) = 0; // Pure virtual function to execute the instruction
    virtual ~Instruction() {}
};

#endif
