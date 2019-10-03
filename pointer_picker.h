#include "include_all.h"

void deft() {
    std::cout << "Этот таск ещё не определён.\n";
}

#define caseTask(n) case n: return task##n

typedef void (*voidptr)();
voidptr pickTask(int number) {
    switch (number) {
        caseTask(1);
        caseTask(2);
        caseTask(3);
        caseTask(4);
        caseTask(5);
        caseTask(6);
        caseTask(7);
        caseTask(8);
        caseTask(9);
        caseTask(10);
        caseTask(11);
        caseTask(12);
        caseTask(13);
        caseTask(14);
        caseTask(15);

        default:
            return deft;
    }
}