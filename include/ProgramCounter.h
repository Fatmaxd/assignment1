#ifndef PROGRAMCOUNTER_H
#define PROGRAMCOUNTER_H

class ProgramCounter {
private:
    int address;  // Current address in the program

public:
    ProgramCounter();
    int getAddress() const;
    void setAddress(int newAddress);
    void increment();
};

#endif
