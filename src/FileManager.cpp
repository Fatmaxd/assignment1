#include "FileManager.h"
#include <fstream>
#include <iostream>

void FileManager::loadProgram(const std::string& filename, Memory& memory) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    std::vector<std::string> instructions;
    std::vector<std::string> invalidInstructions; // Store invalid instructions
    std::string instruction;
    while (file >> instruction) {
        // Expanded list of valid instructions
        if (instruction == "10FF" || instruction == "11E1" || instruction == "12FF" ||
            instruction == "10E0" || instruction == "11F1" || instruction == "12E2" ||
            instruction == "2000" || instruction == "2130" || instruction == "2201" ||
            instruction == "23C6" || instruction == "2420" || instruction == "3100" ||
            instruction == "3400" || instruction == "5112" || instruction == "3101" ||
            instruction == "5113" || instruction == "B124" || instruction == "1101" ||
            instruction == "B014" || instruction == "C000") {
            instructions.push_back(instruction);
            std::cout << "Loaded instruction: " << instruction << std::endl;
        } else {
            // Store invalid instructions
            invalidInstructions.push_back(instruction);
            std::cerr << "Invalid instruction: " << instruction << std::endl;
        }
    }

    // Check if there are no valid instructions
    if (instructions.empty()) {
        std::cout << "No valid instructions loaded. Program cannot run." << std::endl;
        return; // Terminate loading process if no valid instructions are present
    }

    // Load valid instructions into memory
    memory.loadInstructions(instructions);

    // After loading, print summary of invalid instructions (if any)
    if (!invalidInstructions.empty()) {
        std::cout << "\nInvalid instructions summary:\n";
        for (const std::string& invalid : invalidInstructions) {
            std::cout << invalid << std::endl;
        }
    }

    std::cout << "\nProgram loaded with " << instructions.size() << " valid instructions and "
              << invalidInstructions.size() << " invalid instructions.\n";
}
 