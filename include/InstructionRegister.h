#ifndef INSTRUCTIONREGISTER_H
#define INSTRUCTIONREGISTER_H

class InstructionRegister {
private:
    int instruction;  // Current instruction to execute

public:
    InstructionRegister();
    int getInstruction() const;
    void setInstruction(int newInstruction);
};

#endif
