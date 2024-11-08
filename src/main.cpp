#include "../include/Machine.h"  // Correct path from src to include
#include <iostream>
#include <vector>

int main() {
    Machine machine;

    // Sample program (LOAD to register 0, STORE to memory 0)
    std::vector<int> program = {0x10A3, 0x30A3};  // Example instructions (LOAD, STORE)

    // Load program into the machine
    machine.loadProgram(program);

    // Fetch and execute instructions
    for (int i = 0; i < 2; i++) {
        machine.fetchAndExecute();
        machine.display();
    }

    return 0;
}
