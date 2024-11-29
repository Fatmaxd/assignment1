#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
 
#include <string>

// Base Instruction class
class Instruction {
public:
    virtual void execute() = 0; // Abstract execute method
    virtual ~Instruction() = default;
};

// Specific instruction classes
class LoadR0 : public Instruction {
private:
    unsigned int value;
public:
    LoadR0(unsigned int val);
    void execute() override;
};

class LoadR1 : public Instruction {
private:
    unsigned int value;
public:
    LoadR1(unsigned int val);
    void execute() override;
};

class LoadR2 : public Instruction {
private:
    int value_;
public:
    LoadR2(int value);
    void execute() override;
};

// New Instruction classes
class LoadR0E0 : public Instruction {
private:
    unsigned int value;
public:
    LoadR0E0(unsigned int val);
    void execute() override;
};

class LoadR1F1 : public Instruction {
private:
    unsigned int value;
public:
    LoadR1F1(unsigned int val);
    void execute() override;
};

class LoadR2E2 : public Instruction {
private:
    int value_;
public:
    LoadR2E2(int value);
    void execute() override;
};

class LoadR3 : public Instruction {
private:
    int value;
public:
    LoadR3(int value);
    void execute() override;
};

class LoadR4 : public Instruction {
private:
    int value;
public:
    LoadR4(int value);
    void execute() override;
};

class LoadR1toM0 : public Instruction {
public:
    void execute() override;
};

class LoadR4toM0 : public Instruction {
public:
    void execute() override;
};

class AddR1R2toR1 : public Instruction {
public:
    void execute() override;
};

class AddR1R3toR1 : public Instruction {
public:
    void execute() override;
};

class StoreR1toM1 : public Instruction {
public:
    void execute() override;
};

class CompR1withR0 : public Instruction {
public:
    void execute() override;
};

class LoadM1toR1 : public Instruction {
public:
    void execute() override;
};

class CompR0withR0 : public Instruction {
public:
    void execute() override;
};

// New Jump and Halt Instructions
class Jump : public Instruction {
private:
    unsigned int conditionRegisterId;
    unsigned int address;
public:
    Jump(unsigned int regId, unsigned int addr);
    void execute() override;
};

class Halt : public Instruction {
public:
    void execute() override;
};

#endif // INSTRUCTIONS_H
