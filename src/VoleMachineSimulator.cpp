#include "VoleMachineSimulator.h"
#include <iostream>
#include "MachineComponents.h"
#include "Instructions.h"  // Include the header where LoadR0 is defined


VoleMachineSimulator::VoleMachineSimulator() {}

void VoleMachineSimulator::menu() {
    int choice;
    do {
        std::cout << "Vole Machine Simulator Menu:\n";
        std::cout << "1. Load Program\n";
        std::cout << "2. Run Step by Step\n";
        std::cout << "3. Display Status\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                loadProgram("program.txt");  // Load program from the file
                break;
            case 2:
                runStepByStep();  // Execute instructions one by one
                break;
            case 3:
                displayStatus();  // Display the machine's status (PC, IR, etc.)
                break;
            case 4:
                std::cout << "           ____" << std::endl;
                std::cout << "        .-'    `-." << std::endl;
                std::cout << "       /    O   O  \\     BOOM!" << std::endl;
                std::cout << "      |    (__)    |   The Vole Machine!" << std::endl;
                std::cout << "      \\     -      /" << std::endl;
                std::cout << "       `-.___.-' " << std::endl;

                std::cout << "Exiting simulator.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}

void VoleMachineSimulator::loadProgram(const std::string& filename) {
    FileManager fileManager;
    fileManager.loadProgram(filename, memory);
    std::cout << "Program loaded.\n";
}



void VoleMachineSimulator::runStepByStep() {
    int totalInstructions = memory.getInstructions().size(); // Get the total number of instructions loaded in memory

    while (pc.hasNextInstruction(totalInstructions)) {
        fetchInstruction(); // Fetch the instruction
        
        // Check if the fetched instruction is the termination instruction
        if (ir.getInstruction() == "C000") {            std::cout << "Program terminated by instruction C000." << std::endl;
            pc.increment();

            break; // Exit the loop immediately
        }

        executeInstruction(); // Execute the fetched instruction

        // After executing the instruction, check if there are more instructions to execute
        if (!pc.hasNextInstruction(totalInstructions)) {
            std::cout << "No more instructions to fetch. Program terminated." << std::endl;
            break; // Stop the loop if the PC exceeds the number of instructions
        }
    }

    std::cout << "Program execution completed." << std::endl;
}






void VoleMachineSimulator::fetchInstruction() {
    int currentPC = pc.getCurrentValue();
    int totalInstructions = memory.getInstructions().size();

    // Handle case where no instructions have been loaded
    if (totalInstructions == 0) {
        std::cout << "No instructions loaded. Program cannot run." << std::endl;
        return; // Exit if no instructions are loaded
    }

    if (currentPC < totalInstructions) {
        std::string instruction = memory.getInstruction(currentPC);

        // Check if instruction is valid
        if (instruction == "10FF" || instruction == "11E1" || instruction == "12FF" ||
            instruction == "10E0" || instruction == "11F1" || instruction == "12E2" ||
            instruction == "2000" || instruction == "2130" || instruction == "2201" ||
            instruction == "23C6" || instruction == "2420" || instruction == "3100" ||
            instruction == "3400" || instruction == "5112" || instruction == "3101" ||
            instruction == "5113" || instruction == "B124" || instruction == "1101" ||
            instruction == "B014" || instruction == "C000") {
            ir.setInstruction(instruction);
            std::cout << "Fetched Instruction: " << instruction << std::endl;
        } else {
            // Invalid instruction, handle error
            std::cerr << "Error: Invalid instruction " << instruction << " at address " << currentPC << std::endl;
            ir.setInstruction("");  // Clear the IR for invalid instruction
            std::cout << "Program terminated due to invalid instruction." << std::endl;
            return;  // Exit fetching on invalid instruction
        }
    } else {
        std::cout << "No more instructions to fetch. Program terminated." << std::endl;
        std::cout << "Good job! Now, take a moment to relax." << std::endl;
        ir.setInstruction("");  // Clear the IR when no more instructions
    }
}





void VoleMachineSimulator::executeInstruction() {
    std::string currentInstruction = ir.getInstruction();
    std::cout << "Executing instruction: " << currentInstruction << std::endl;

    // Handle known instructions
    bool instructionExecuted = false; // Flag to check if the instruction was executed successfully

    if (currentInstruction == "10FF") {
        std::cout << "Executing LoadR0 instruction" << std::endl;
        LoadR0 loadR0(0x00); // Load R0 with value 00
        loadR0.execute();
        instructionExecuted = true;
    } else if (currentInstruction == "11E1") {
        std::cout << "Executing LoadR1 instruction" << std::endl;
        LoadR1 loadR1(30); // Load R1 with value 30
        loadR1.execute();
        instructionExecuted = true;
    } else if (currentInstruction == "12FF") {
        std::cout << "Executing LoadR2 instruction" << std::endl;
        LoadR2 loadR2(1);  // Load R2 with value 01 (decimal)
        loadR2.execute();
        instructionExecuted = true;
    } 
    // Handle new instructions
    else if (currentInstruction == "10E0") {
        std::cout << "Executing LoadR0E0 instruction" << std::endl;
        LoadR0E0 loadR0E0(0xE0); // Load R0 with value E0
        loadR0E0.execute();
        instructionExecuted = true;
    } else if (currentInstruction == "11F1") {
        std::cout << "Executing LoadR1F1 instruction" << std::endl;
        LoadR1F1 loadR1F1(0xF1); // Load R1 with value F1
        loadR1F1.execute();
        instructionExecuted = true;
    } else if (currentInstruction == "12E2") {
        std::cout << "Executing LoadR2E2 instruction" << std::endl;
        LoadR2E2 loadR2E2(0xE2); // Load R2 with value E2
        loadR2E2.execute();
        instructionExecuted = true;
    }
    // Handle additional instructions
    else if (currentInstruction == "2000") {  // Load R0 with 00
        std::cout << "Executing LoadR0 instruction" << std::endl;
        LoadR0 loadR0(0x00);
        loadR0.execute();
        instructionExecuted = true;
    } else if (currentInstruction == "2130") {  // Load R1 with 30
        std::cout << "Executing LoadR1 instruction" << std::endl;
        LoadR1 loadR1(30);
        loadR1.execute();
        instructionExecuted = true;
    } else if (currentInstruction == "2201") {  // Load R2 with 01
        std::cout << "Executing LoadR2 instruction" << std::endl;
        LoadR2 loadR2(1);
        loadR2.execute();
        instructionExecuted = true;
    } else if (currentInstruction == "23C6") {  // Load R3 with C6
        std::cout << "Executing LoadR3 instruction" << std::endl;
        LoadR3 loadR3(0xC6);
        loadR3.execute();
        instructionExecuted = true;
    } else if (currentInstruction == "2420") {  // Load R4 with 20
        std::cout << "Executing LoadR4 instruction" << std::endl;
        LoadR4 loadR4(0x20);
        loadR4.execute();
        instructionExecuted = true;
    } else if (currentInstruction == "3100") {  // Load R1 to M0
        std::cout << "Executing LoadR1toM0 instruction" << std::endl;
        LoadR1toM0 loadR1toM0;
        loadR1toM0.execute();
        instructionExecuted = true;
    } else if (currentInstruction == "3400") {  // Load R4 to M0
        std::cout << "Executing LoadR4toM0 instruction" << std::endl;
        LoadR4toM0 loadR4toM0;
        loadR4toM0.execute();
        instructionExecuted = true;
    } else if (currentInstruction == "5112") {  // Add R1 + R2 to R1
        std::cout << "Executing AddR1R2toR1 instruction" << std::endl;
        AddR1R2toR1 addR1R2toR1;
        addR1R2toR1.execute();
        instructionExecuted = true;
    } else if (currentInstruction == "3101") {  // Store R1 to M1
        std::cout << "Executing StoreR1toM1 instruction" << std::endl;
        StoreR1toM1 storeR1toM1;
        storeR1toM1.execute();
        instructionExecuted = true;
    } else if (currentInstruction == "5113") {  // Comp R1 with R0
        std::cout << "Executing CompR1withR0 instruction" << std::endl;
        CompR1withR0 compR1withR0;
        compR1withR0.execute();
        instructionExecuted = true;
    } else if (currentInstruction == "B124") {  // Load M1 to R1
        std::cout << "Executing LoadM1toR1 instruction" << std::endl;
        LoadM1toR1 loadM1toR1;
        loadM1toR1.execute();
        instructionExecuted = true;
    } else if (currentInstruction == "1101") {  // Load R1 with 01
        std::cout << "Executing LoadR1 instruction" << std::endl;
        LoadR1 loadR1(1);
        loadR1.execute();
        instructionExecuted = true;
    } else if (currentInstruction == "B014") {  // Comp R0 with R0
        std::cout << "Executing CompR0withR0 instruction" << std::endl;
        CompR0withR0 compR0withR0;
        compR0withR0.execute();
        instructionExecuted = true;
    }  

    // Error handling for unknown instructions
    if (!instructionExecuted) {
        std::cout << "Error: Unknown instruction encountered - " << currentInstruction << std::endl;
        // Optionally: Stop execution or skip to next instruction based on user preference
        // For now, let's skip to the next instruction without halting the program
        std::cout << "Skipping to the next instruction." << std::endl;
        return; // Skip the current invalid instruction
    }

    // Increment PC only for valid instructions
    if (currentInstruction != "C000") {
        pc.increment();
    }
}



void VoleMachineSimulator::displayStatus() {
    Screen screen; // Declare screen as a member variable

    // Display Program Counter and Instruction Register
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Program Counter: 0x" << std::hex << pc.getCurrentValue() << std::dec << std::endl;  // Hex format for PC
    std::cout << "Instruction Register: " << ir.getInstruction() << std::endl;
    std::cout << "---------------------------------" << std::endl;

    // Display Registers Status
    std::cout << "Registers Status:" << std::endl;
    std::cout << "R0 Value: " << R0.getValue() << "  |  ";
    std::cout << "R1 Value: " << R1.getValue() << "  |  ";
    std::cout << "R2 Value: " << R2.getValue() << "  |  ";
    std::cout << "R3 Value: " << R3.getValue() << "  |  ";
    std::cout << "R4 Value: " << R4.getValue() << std::endl;

    std::cout << "---------------------------------" << std::endl;

    // Display Memory Content in Hexadecimal
    std::cout << "Memory Content:" << std::endl;
    const auto& instructions = memory.getInstructions(); // Assuming memory has a `getInstructions()` method
    for (size_t i = 0; i < instructions.size(); ++i) {
        std::cout << "Address 0x" << std::hex << i << ": " << instructions[i] << std::endl;
    }

    std::cout << "---------------------------------" << std::endl;

    // Display Instructions Executed
    std::cout << "Instructions Executed: " 
              << std::dec << pc.getCurrentValue() << " / " << instructions.size() << std::endl;
    std::cout << "---------------------------------" << std::endl;
}
 