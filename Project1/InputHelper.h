#pragma once
#include <iostream>
#include <limits>

// Reads one integer from stdin. Returns -1 on non-numeric input.
inline int readMenuInput() {
    int ch;
    std::cin >> ch;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return -1;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return ch;
}
