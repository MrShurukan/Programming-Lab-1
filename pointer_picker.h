#include "include_all.h"

void deft() {
    std::cout << "Этот таск ещё не определён.\n";
}

typedef void (*voidptr)();
voidptr pickTask(int number) {
    switch (number) {
        case 1: return task1;
        case 2: return task2;
        case 3: return task3;
        case 4: return task4;
        case 5: return task5;
        case 6: return task6;
        case 7: return task7;
        case 8: return task8;
        case 9: return task9;
        case 10: return task10;
        case 11: return task11;
        case 12: return task12;
        case 13: return task13;
        case 14: return task14;
        case 15: return task15;
        case 16: return task16;
        case 17: return task17;
        case 18: return task18;
        case 19: return task19;
        case 20: return task20;
        case 21: return task21;

        default:
            return deft;
    }
}