#include <iostream>
#include <locale>
#include "include_all.h"

int main() {
    std::setlocale(LC_ALL, "Russian");

    int taskNumber = 0;
    while (true) {
        std::cout << "������� ����� �������: ";
        std::cin >> taskNumber;

        if (taskNumber == 0) break;

        pickTask(taskNumber)();
        std::cout << '\n';
    }

    std::cout << "��������.\n";
    return 0;
}