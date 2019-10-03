#include <iostream>
#include "include_all.h"

#define FUNCTIONS
#define print(x) std::cout << x << '\n'
#define printVar(x) std::cout << "Значение " #x ": " << x << '\n'

#define getDef(type, name) type name; std::cout << "Введите " #name ": "; std::cin >> name
#define get(name) std::cout << "Введите " #name ": "; std::cin >> name

int main() {
    setlocale(LC_ALL, "Russian");

    int task_number = 0;
    while (true) {
        get(task_number);

        if (task_number == 0) break;
        // else if (task_number > 15) continue;

        pickTask(task_number)();
        print("\n");
    }

    print("Прервано.");
    return 0;
}