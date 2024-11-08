#ifndef INSTRUCTIONTYPES_H
#define INSTRUCTIONTYPES_H

#include "Instruction.h"
#include "Machine.h"

// Base instruction classes for specific instructions
class LoadInstruction : public Instruction {
private:
    int reg;
    int address;

public:
    LoadInstruction(int instruction);
    void execute(Machine& machine) override;
};

class StoreInstruction : public Instruction {
private:
    int reg;
    int address;

public:
    StoreInstruction(int instruction);
    void execute(Machine& machine) override;
};

class AddInstruction : public Instruction {
private:
    int reg1, reg2, resultReg;

public:
    AddInstruction(int instruction);
    void execute(Machine& machine) override;
};

class JumpInstruction : public Instruction {
private:
    int reg;
    int address;

public:
    JumpInstruction(int instruction);
    void execute(Machine& machine) override;
};

class HaltInstruction : public Instruction {
public:
    HaltInstruction(int instruction);
    void execute(Machine& machine) override;
};

#endif
