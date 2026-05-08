#include <iostream>
#define NOMINMAX
#include <windows.h>
#include "InputHelper.h"
#include "MonitoringMenu.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    while (true) {
        std::cout << "\n=== 반도체 시료 생산 관리 시스템 ===\n"
                  << "1. 시료 관리\n"
                  << "2. 생산 관리\n"
                  << "3. 모니터링\n"
                  << "0. 종료\n"
                  << "메뉴 선택: ";

        switch (readMenuInput()) {
        case 1:
        case 2:
            std::cout << "[준비 중]\n";
            break;
        case 3:
            runMonitoringMenu();
            break;
        case 0:
            std::cout << "종료합니다.\n";
            return 0;
        case -1:
            std::cout << "잘못된 입력입니다.\n";
            break;
        default:
            std::cout << "없는 메뉴입니다.\n";
            break;
        }
    }
}
