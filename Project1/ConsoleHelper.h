#pragma once
#define NOMINMAX   // prevent windows.h from defining min/max macros
#include <windows.h>
#include <iostream>

constexpr const char* GREEN = "\033[32m";
constexpr const char* RESET = "\033[0m";

inline void initConsole() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    std::cout << GREEN;
}
