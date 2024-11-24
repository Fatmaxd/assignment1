#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "MachineComponents.h"
#include <string>

class FileManager {
public:
    void loadProgram(const std::string& filename, Memory& memory);
};

#endif
