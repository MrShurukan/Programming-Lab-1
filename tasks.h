#ifndef FUNCTIONS
#define print(x) std::cout << x << '\n'
#define printVar(x) std::cout << "Значение " #x ": " << x << '\n'

#define getDef(type, name) type name; std::cout << "Введите " #name ": "; std::cin >> name
#define get(name) std::cout << "Введите " #name ": "; std::cin >> name

#include <iostream>
#endif


void task1() {
    std::cout << "Результат вычисления выражения 2+2*2 = " << 2 + 2 * 2;
}

void task2() {
    int a = 3, b = 3.14;
    double c = 3, d = 3.14;
    
    print(a);
    print(b);
    print(c);
    print(d);
}

#define printMath(a, b) std::cout << a + b << ' ' << a - b << ' ' << a * b << ' ' << a / b << '\n'
void task3() {
    getDef(int, int1);
    getDef(int, int2);
    printMath(int1, int2);

    getDef(double, double1);
    getDef(double, double2);
    printMath(double1, double2);

    getDef(double, int21);
    getDef(double, double21);
    printMath(int21, double21);

    getDef(double, double31);
    getDef(int, int31);
    printMath(double31, int31);
}

void task4() {
    getDef(int, a);
    getDef(int, b);

    printVar(a);
    printVar(b);

    std::swap(a, b);

    printVar(a);
    printVar(b);

    a = a + b;
    b = a - b;
    a = a - b;

    printVar(a);
    printVar(b);
}

void task5() {
    const double g = -9.8;
    getDef(double, x0);
    getDef(double, v0);
    getDef(double, t);

    print(x0 + v0*t + (g*t*t) / 2);
}

void task6() {
    getDef(double, a);
    getDef(double, b);
    getDef(double, c);

    if (a == 0 && b == 0) {
        std::cout << "Корни уравнения: (-Inf, Inf)" << std::endl;
        return;
    }

    if (a == 0) {
        // Это не квадратное уравнение, решаем как обычное
        if (b == 0) {
            print("Корень уравнения: 0");
        }
        else {
            std::cout << "Корень уравнения: " << -(c / b) << std::endl;
        }

        return;
    }

    double D = b*b - 4*a*c;
    if (D < 0) {
        print("Действительных корней нет.");
        return;
    }
    else if (D == 0) {
        std::cout << "Корень уравнения: " << -b / 2*a << std::endl;
        return;
    }

    double sqrtD = std::sqrt(D);
    double x1 = (-b + sqrtD) / 2*a;
    double x2 = (-b - sqrtD) / 2*a;

    printVar(x1);
    printVar(x2);
}

#define sqr(x) (x) * (x)
#define getLength(xa, ya, xb, yb) std::sqrt(sqr(xb - xa) + sqr(yb - ya)) 
void task7() {
    std::cout << "1 - длины сторон, 2 - координаты вершин" << std::endl;
    getDef(int, method);
    
    double square;
    double a, b, c;
    switch (method) {
        case 1:
            get(a);
            get(b);
            get(c);
            break;
        case 2:
            double Xa, Ya;
            std::cout << "Xa Ya: ";
            std::cin >> Xa >> Ya;

            double Xb, Yb;
            std::cout << "Xb Yb: ";
            std::cin >> Xb >> Yb;

            double Xc, Yc;
            std::cout << "Xc Yc: ";
            std::cin >> Xc >> Yc;

            a = getLength(Xa, Ya, Xb, Yb);
            b = getLength(Xb, Yb, Xc, Yc);
            c = getLength(Xa, Ya, Xc, Yc);
            break;

        default:
            print("Некорректный метод");
            return;
    }
    double p = (a + b + c) / 2;
    square = std::sqrt(p * (p - a) * (p - b) * (p - c));
    printVar(square);
}

void task8() {
    double a, b;
    char op;

    std::cin >> a >> op >> b;
    switch(op) {
        case '+':
            print(a + b);
            break;
        case '-':
            print(a - b);
            break;
        case '*':
            print(a * b);
            break;
        case '/':
            if (b == 0) { 
                print("Ошибка, деление на ноль!");
                return;
            }
            print(a / b);
            break;

        default:
            print("Неизвестный оператор");
    }
}

void task9() {
    bool userWantsToExit = false;
    while (!userWantsToExit) {
        srand(time(0));
        int n = rand() % 101;

        bool isGuessed = false;
        int attemps = 5;

        int guess;
        print("Угадайте число от 1 до 100: (У вас пять попыток)");
        while (!isGuessed && attemps > 0) {
            std::cin >> guess;
            attemps--;

            if (n < guess) {
                print("Заданное число меньше");
            }
            else if (n > guess) {
                print("Заданное число больше");
            }
            else {
                print("Поздравляю! Вы угадали");
                isGuessed = true;
            }
        }

        if (attemps == 0 && !isGuessed) {
            std::cout << "Вы проиграли. Было загадано: " << n << std::endl;
        }

        int answ;
        std::cout << "Хотите начать сначала? (1 - ДА): ";
        std::cin >> answ;
        if (answ != 1) userWantsToExit = true;
    }
    print("До новых встрех!");
}

void task10() {
    double base;
    int power;
    std::cin >> base >> power;

    double result = base;
    for (int i = 1; i < power; i++)
        result *= base;
    
    print(result);
}

void task11() {
    getDef(int, n);

    long long result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;

    print(result);
}

void task12() {
    getDef(int, n);

    int root = std::sqrt(n);
    for (int i = 2; i <= root; i++)
        if (n % i == 0) {
            print("Составное");
            return;
        }

    print("Простое");
}

void task13() {
    getDef(long long, n);
    int amount = 0;
    for (long long x = 1; x <= n; x *= 2)
        amount++;
    
    print(amount);
}

#define ll long long
void checkSum(ll s, ll l1, ll r1, ll l2, ll r2) {
    for (ll i = l1; i <= r1; i++) {
        ll desired = s - i;

        if (l2 >= desired && desired <= r2) {
            std::cout << i << " " << desired << std::endl;
            return;
        }
    }

    std::cout << -1 << std::endl;
}

void task14() {
    ll s, l1, r1, l2, r2;
    std::cin >> s >> l1 >> r1 >> l2 >> r2;

    bool isFirstShorter = (r1 - l1 < r2 - l2);
    if (isFirstShorter) {
        checkSum(s, l1, r1, l2, r2);
    }
    else {
        checkSum(s, l2, r2, l1, r1);
    }
}

void printSet(std::multiset<int> s) {
    int size = s.size();
    int maxLength = (size < 5 ? size : 5);

    for (auto i = std::next(s.rbegin(), size - maxLength); 
            i != s.rend(); 
            i++)
    {
        std::cout << *i << " ";
    }
    std::cout << '\n';
}

void task15() {
    getDef(int, n);
    std::multiset<int> s;

    int a;
    for (int i = 0; i < n; i++) {
        std::cin >> a;
        s.insert(a);

        printSet(s);
    }
}