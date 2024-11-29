#include "Instructions.h"
#include <iostream>
#include "MachineComponents.h" // For access to registers and memory
 
// LoadR0
LoadR0::LoadR0(unsigned int val) : value(val) {}
void LoadR0::execute() {
    R0.setValue(value);
    std::cout << "Loaded R0 with value: " << value << std::endl;
}

// LoadR1
LoadR1::LoadR1(unsigned int val) : value(val) {}
void LoadR1::execute() {
    R1.setValue(value);
    std::cout << "Loaded R1 with value: " << value << std::endl;
}

// LoadR2
LoadR2::LoadR2(int value) : value_(value) {}
void LoadR2::execute() {
    R2.setValue(value_);
    std::cout << "Loaded R2 with value: " << value_ << std::endl;
}

// LoadR0E0
LoadR0E0::LoadR0E0(unsigned int val) : value(val) {}
void LoadR0E0::execute() {
    R0.setValue(value);
    std::cout << "Loaded R0E0 with value: " << value << std::endl;
}

// LoadR1F1
LoadR1F1::LoadR1F1(unsigned int val) : value(val) {}
void LoadR1F1::execute() {
    R1.setValue(value);
    std::cout << "Loaded R1F1 with value: " << value << std::endl;
}

// LoadR2E2
LoadR2E2::LoadR2E2(int value) : value_(value) {}
void LoadR2E2::execute() {
    R2.setValue(value_);
    std::cout << "Loaded R2E2 with value: " << value_ << std::endl;
}

// LoadR3
LoadR3::LoadR3(int value) : value(value) {}
void LoadR3::execute() {
    R3.setValue(value);
    std::cout << "Loaded R3 with value: " << value << std::endl;
}

// LoadR4
LoadR4::LoadR4(int value) : value(value) {}
void LoadR4::execute() {
    R4.setValue(value);
    std::cout << "Loaded R4 with value: " << value << std::endl;
}

// LoadR1toM0
void LoadR1toM0::execute() {
    memory[0] = R1.getValue();
    std::cout << "Stored R1 to memory M0: " << memory[0] << std::endl;
}

// LoadR4toM0
void LoadR4toM0::execute() {
    memory[0] = R4.getValue();
    std::cout << "Stored R4 to memory M0: " << memory[0] << std::endl;
}

// AddR1R2toR1
void AddR1R2toR1::execute() {
    R1.setValue(R1.getValue() + R2.getValue());
    std::cout << "Added R1 and R2. New R1: " << R1.getValue() << std::endl;
}

// AddR1R3toR1
void AddR1R3toR1::execute() {
    R1.setValue(R1.getValue() + R3.getValue());
    std::cout << "Added R1 and R3. New R1: " << R1.getValue() << std::endl;
}

// StoreR1toM1
void StoreR1toM1::execute() {
    memory[1] = R1.getValue();
    std::cout << "Stored R1 to memory M1: " << memory[1] << std::endl;
}

// CompR1withR0
void CompR1withR0::execute() {
    if (R1.getValue() == R0.getValue()) {
        std::cout << "R1 equals R0" << std::endl;
    } else if (R1.getValue() > R0.getValue()) {
        std::cout << "R1 greater than R0" << std::endl;
    } else {
        std::cout << "R1 less than R0" << std::endl;
    }
}

// LoadM1toR1
void LoadM1toR1::execute() {
    R1.setValue(memory[1]);
    std::cout << "Loaded M1 into R1: " << R1.getValue() << std::endl;
}

// CompR0withR0
void CompR0withR0::execute() {
    std::cout << "R0 equals itself" << std::endl;
}
