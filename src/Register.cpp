#include "../include/Register.h"  // Correct path from src to include


Register::Register() : value(0) {}  // Initialize register with value 0

int Register::getValue() const {
    return value;
}

void Register::setValue(int value) {
    this->value = value;
}
