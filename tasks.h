#include <iostream>


void task1() {
    std::cout << "Результат вычисления выражения 2+2*2 = " << 2 + 2 * 2;
}

void task2() {
    int a = 3, b = 3.14;
    double c = 3, d = 3.14;
    
    std::cout << a << '\n'
        << b << '\n'
        << c << '\n'
        << d << '\n';
}

#define printMath(a, b) std::cout << a + b << ' ' << a - b << ' ' << a * b << ' ' << a / b << '\n'
void task3() {
    int int1, int2;
    std::cin >> int1 >> int2;
    printMath(int1, int2);

    double double1, double2;
    std::cin >> double1 >> double2;
    printMath(double1, double2);

    int int21;
    double double21;
    std::cin >> int21 >> double21;
    printMath(int21, double21);

    double double31;
    int int31;
    std::cin >> double31 >> int31;
    printMath(double31, int31);
}

void task4() {
    int a, b;
    std::cin >> a >> b;

    std::cout << "До: " << a << b << '\n';

    std::swap(a, b);

    std::cout << "После: " << a << b << '\n';
    std::cout << "До: " << a << b << '\n';

    a = a + b;
    b = a - b;
    a = a - b;

    std::cout << "После: " << a << b << '\n';
}

void task5() {
    const double g = -9.8;
    double x0, v0, t;
    std::cin >> x0 >> v0 >> t;

    std::cout << x0 + v0*t + (g*t*t) / 2 << '\n';
}

void task6() {
    double a, b, c;
    std::cin >> a >> b >> c;

    if (a == 0 && b == 0) {
        if (c == 0)
            std::cout << "Корни уравнения: (-Inf, Inf)\n";
        else
            std::cout << "Корни уравнения отсутсвуют\n";

        return;
    }

    if (a == 0) {
        // Это не квадратное уравнение, решаем как обычное
        // В этой точке программы b гарантированно не равен нулю
        std::cout << "Корень уравнения: " << -(c / b) << '\n';

        return;
    }

    double D = b*b - 4*a*c;
    if (D < 0) {
        std::cout << "Действительных корней нет.";
        return;
    }
    else if (D == 0) {
        // В этой точке программы a гарантированно не равно нулю
        std::cout << "Корень уравнения: " << -b / 2*a << '\n';
        return;
    }

    double sqrtD = std::sqrt(D);
    double x1 = (-b + sqrtD) / 2*a;
    double x2 = (-b - sqrtD) / 2*a;

    std::cout << "Корни уравнения: x1:" << x1 << ", x2: " << x2 << '\n';
}

#define sqr(x) (x) * (x)
#define getLength(xa, ya, xb, yb) std::sqrt(sqr(xb - xa) + sqr(yb - ya)) 
void task7() {
    std::cout << "1 - длины сторон, 2 - координаты вершин\n";
    int method;
    std::cin >> method;
    
    double square;
    double a, b, c;
    switch (method) {
        case 1:
            std::cout << "a, b, c: ";
            std::cin >> a >> b >> c;
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
            std::cout << "Некорректный метод\n";
            return;
    }
    double p = (a + b + c) / 2;
    square = std::sqrt(p * (p - a) * (p - b) * (p - c));
    std::cout << square << '\n';
}

void task8() {
    double a, b;
    char op;

    std::cin >> a >> op >> b;
    switch(op) {
        case '+':
            std::cout << a + b;
            break;
        case '-':
            std::cout << a - b;
            break;
        case '*':
            std::cout << a * b;
            break;
        case '/':
            if (b == 0) { 
                std::cout << "Ошибка, деление на ноль!";
                return;
            }
            std::cout << a / b;
            break;

        default:
            std::cout << "Неизвестный оператор";
    }
    std::cout << '\n';
}

void task9() {
    std::random_device rd;
    std::mt19937 mersenne(rd()); // инициализируем Вихрь Мерсенна случайным стартовым числом

    bool userWantsToExit = false;
    while (!userWantsToExit) {
        int n = static_cast<int>(mersenne() % 101);

        bool isGuessed = false;
        int attempts = 5;

        int guess;
        std::cout << "Угадайте число от 1 до 100: (У вас пять попыток)\n";
        while (!isGuessed && attempts > 0) {
            std::cin >> guess;
            attempts--;

            if (n < guess) {
                std::cout << "Заданное число меньше";
            }
            else if (n > guess) {
                std::cout << "Заданное число больше";
            }
            else {
                std::cout << "Поздравляю! Вы угадали";
                isGuessed = true;
            }
            std::cout << '\n';
        }

        if (attempts == 0 && !isGuessed) {
            std::cout << "Вы проиграли. Было загадано: " << n << '\n';
        }

        int answ;
        std::cout << "Хотите начать сначала? (1 - ДА): ";
        std::cin >> answ;
        if (answ != 1) userWantsToExit = true;
    }
    std::cout << "До новых встрех!\n";
}

void task10() {
    double base;
    int power;
    std::cin >> base >> power;

    double result = base;
    for (int i = 1; i < power; i++)
        result *= base;
    
    std::cout << result;
}

void task11() {
    int n;
    std::cin >> n;

    long long result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;

    std::cout << result;
}

void task12() {
    int n;
    std::cin >> n;

    int root = std::sqrt(n);
    for (int i = 2; i <= root; i++)
        if (n % i == 0) {
            std::cout << "Составное\n";
            return;
        }

    std::cout << "Простое\n";
}

void task13() {
    long long n;
    std::cin >> n;
    int amount = 0;
    for (long long x = 1; x <= n; x *= 2)
        amount++;
    
    std::cout << amount << '\n';
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
    int n;
    std::cin >> n;

    std::multiset<int> s;

    int a;
    for (int i = 0; i < n; i++) {
        std::cin >> a;
        s.insert(a);

        printSet(s);
    }
}