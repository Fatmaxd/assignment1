# Vole Machine Simulator
 
## Overview
The Vole Machine Simulator is a C++ project developed as part of the CS213 - **Object Oriented Programming** course. The simulator mimics the operations of a fictional Vole machine, allowing users to load and execute machine programs, step by step, while tracking the status of the program counter, registers, and memory. It’s an educational tool designed to help understand how low-level machine operations work.

While this simulator isn't fully completed yet (because who doesn’t love adding a few finishing touches?), it already serves as a working model of a simple machine simulator and might get some updates in the future to add more features or polish its current functionality. 

## Features
- Load machine programs from a file (so you don’t have to type every instruction manually — you're welcome).
- Execute instructions **step by step** (because who doesn’t love suspense in their coding?).
- Display the current status of:
  - **Program Counter (PC)**
  - **Instruction Register (IR)**
  - **Registers** (including R0, R1, etc. — they’re all doing their jobs!).
  - **Memory** (it’s not much, but it’s home).
- Handles basic machine instructions like loading values into registers, storing in memory, and more.
- **Error handling**: If something goes wrong, the simulator will let you know (no more guessing what’s broken!).

## What I Learned 
This project taught me a lot about:
- **C++ programming**: Especially working with objects, classes, and simulating machine-level operations.
- **Object-Oriented Design**: I applied OOP principles to model different components of the machine (Registers, Memory, Program Counter, etc.) and how they interact.
- **Debugging skills**: And boy, did I debug a lot. If I learned one thing, it’s that machines don’t always like to do what you tell them.
- **How to handle simulation states**: Managing and tracking the status of each machine component was trickier than I thought!
- **Error Handling**: Ensuring the program could gracefully handle invalid instructions was a fun challenge.
- **The importance of comments**: Because without them, even I wouldn’t know what I was doing after a week. 

## Disclaimer
This project isn’t 100% completed yet (and it probably won’t be for a while — unless I wake up in the middle of the night with a burst of inspiration). But I do plan on adding some more features and tweaks soon.

## Menu Options
Here’s what you can do once the simulator is running:

1. **Load Program**: Load a program from a file (space-separated instructions).
2. **Run Step by Step**: Execute one instruction at a time (for those who like to take it slow and savor the moment).
3. **Display Status**: See what's going on with your machine — registers, memory, and more.
4. **Exit**: Because sometimes, you just need to exit gracefully.

## Course Information
- **Course**: CS213 - Object-Oriented Programming
- **Instructor**:  Dr. Mohammad El-Ramly
- **Semester**: Fall 2024

## Future Plans 
- More instructions for the simulator to make it even more like a real machine (maybe even add an AI to run the programs for you? Just kidding... or am I?).
- More advanced error handling (because we all know machines like to throw tantrums).
- Adding documentation for all the instruction types (because everyone loves reading documentation, right?).
