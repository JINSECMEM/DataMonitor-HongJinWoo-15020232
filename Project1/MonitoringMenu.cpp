#include "MonitoringMenu.h"
#include "SampleStore.h"
#include "InputHelper.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

// ---------------------------------------------------------------
// Table helpers
// ---------------------------------------------------------------

static void sep() {
    std::cout << std::string(52, '-') << '\n';
}

static void printSampleRow(const Sample& s) {
    std::cout << std::fixed << std::setprecision(2)
              << std::right << std::setw(4)  << s.id            << " | "
              << std::left  << std::setw(9)  << s.name          << " | "
              << std::right << std::setw(12) << s.avg_production_time << " | "
              << std::right << std::setw(7)  << s.yield_rate    << '\n';
}

// ---------------------------------------------------------------
// Menu actions
// ---------------------------------------------------------------

static void listAll() {
    const auto& samples = SampleStore::instance().all();
    std::cout << "\n[전체 시료 목록]\n";
    sep();
    std::cout << "  ID | 이름      | 생산시간(min) | 수율(%)\n";
    sep();
    for (const auto& s : samples)
        printSampleRow(s);
    sep();
    std::cout << "총 " << samples.size() << "개 시료\n";
}

static void findById() {
    std::cout << "조회할 시료 ID 입력: ";
    int id = readMenuInput();
    if (id < 0) {
        std::cout << "잘못된 입력입니다.\n";
        return;
    }
    auto result = SampleStore::instance().find(id);
    if (!result) {
        std::cout << "오류: ID " << id << "에 해당하는 시료가 없습니다.\n";
        return;
    }
    const auto& s = *result;
    std::cout << std::fixed << std::setprecision(2)
              << "\n[시료 상세 정보]\n"
              << "  ID            : " << s.id << '\n'
              << "  이름          : " << s.name << '\n'
              << "  평균 생산시간 : " << s.avg_production_time << " min\n"
              << "  수율          : " << s.yield_rate << " %\n";
}

static void sortByYield() {
    std::vector<Sample> sorted = SampleStore::instance().all();
    std::ranges::sort(sorted, std::greater<>{}, &Sample::yield_rate);

    std::cout << "\n[수율 높은 순]\n";
    sep();
    std::cout << "순위 | ID  | 이름      | 수율(%)\n";
    sep();
    int rank = 1;
    for (const auto& s : sorted) {
        std::cout << std::right << std::setw(4) << rank++ << " | "
                  << std::right << std::setw(3) << s.id   << " | "
                  << std::left  << std::setw(9) << s.name << " | "
                  << std::fixed << std::setprecision(2)
                  << std::right << std::setw(7) << s.yield_rate << '\n';
    }
    sep();
}

static void sortByProductionTime() {
    std::vector<Sample> sorted = SampleStore::instance().all();
    std::ranges::sort(sorted, std::less<>{}, &Sample::avg_production_time);

    std::cout << "\n[생산시간 짧은 순]\n";
    sep();
    std::cout << "순위 | ID  | 이름      | 생산시간(min)\n";
    sep();
    int rank = 1;
    for (const auto& s : sorted) {
        std::cout << std::right << std::setw(4) << rank++ << " | "
                  << std::right << std::setw(3) << s.id   << " | "
                  << std::left  << std::setw(9) << s.name << " | "
                  << std::fixed << std::setprecision(2)
                  << std::right << std::setw(12) << s.avg_production_time << '\n';
    }
    sep();
}

// ---------------------------------------------------------------
// Entry point
// ---------------------------------------------------------------

void runMonitoringMenu() {
    while (true) {
        std::cout << "\n=== 모니터링 ===\n"
                  << "1. 전체 시료 목록 조회\n"
                  << "2. 시료 상세 조회\n"
                  << "3. 수율 기준 정렬 조회\n"
                  << "4. 평균 생산시간 기준 정렬 조회\n"
                  << "0. 뒤로 가기\n"
                  << "메뉴 선택: ";

        switch (readMenuInput()) {
        case 1: listAll();              break;
        case 2: findById();             break;
        case 3: sortByYield();          break;
        case 4: sortByProductionTime(); break;
        case 0: return;
        case -1: std::cout << "잘못된 입력입니다.\n"; break;
        default: std::cout << "없는 메뉴입니다.\n";   break;
        }
    }
}
