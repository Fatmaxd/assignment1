#ifndef VOLEMACHINESIMULATOR_H
#define VOLEMACHINESIMULATOR_H
 
#include "MachineComponents.h"
#include "FileManager.h"

class VoleMachineSimulator {
private:
    ProgramCounter pc;
    InstructionRegister ir;
    Memory memory;
public:
    VoleMachineSimulator();
    void menu();
    void loadProgram(const std::string& filename);
    void runStepByStep();
    void fetchInstruction();
    void executeInstruction();
    void displayStatus();
};

#endif
