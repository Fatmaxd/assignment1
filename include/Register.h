#ifndef REGISTER_H
#define REGISTER_H

class Register {
public:
    Register();  // Constructor to initialize the register with zero value

    int getValue() const;  // Get the current value stored in the register
    void setValue(int value);  // Set a value to the register

private:
    int value;  // Register value
};

#endif // REGISTER_H
