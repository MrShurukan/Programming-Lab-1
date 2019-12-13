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

void printSet(const std::multiset<int>& s) {
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

std::map<int, int> factAmount;
void factorization(int n) {
    if (n == 1) {
        std::cout << "-\n";
        return;
    }

    for (int i = 2; i*i <= n; i++) {    // Возможные делители находятся в диапазоне от [2, sqrt(n)]
        if (n % i == 0) {
            factAmount[i]++;
            factorization(n / i);   // Число i - одно из делителей. Оставшееся число n / i требуется проверить этим же способом
            return;
        }
    }

    // Цикл завершился без нахождения ни одного делителя => число простое и его нужно добавить как делитель
    factAmount[n]++;

    // Финальная точка программы, вывод ответа:
    for (auto i = factAmount.begin(); i != factAmount.end(); i++) {
        int fact = i->first, amount = i->second;

        // Выводим звездочку перед каждым, кроме первого
        if (i != factAmount.begin()) std::cout << '*';

        std::cout << fact;
        if (amount > 1) std::cout << "^" << amount;
    }
    std::cout << '\n';
}

void task16() {
    int n;
    std::cout << "Введите n: ";
    std::cin >> n;

    factAmount.clear();    // Очищаем map от возможных прошлых вычислений
    factorization(n);
}

// Возвращает индекс массы тела.
double BMI(double weight, double height) {
    return weight / (height * height);
}

// Принимает численное значение ИМТ и печатает на экран соответствующую категорию
void printBMI(double BMI) {
    if (BMI < 18.5)         std::cout << "Underweight\n";
    else if (BMI < 25.0)    std::cout << "Normal\n";
    else if (BMI < 30.0)    std::cout << "Overweight\n";
    else                    std::cout << "Obesity\n";
}

void task17() {
    double weight, height;
    std::cout << "Введите вес и рост: ";
    std::cin >> weight >> height;

    printBMI( BMI(weight, height / 100) );
}

void task18() {
    srand( time(nullptr) );

    const int size = 20;
    int arr[size];

    int min = 101, max = -101;
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 201 - 100;

        std::cout << arr[i] << ' ';

        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
    std::cout << '\n' << min << '\n' << max << '\n';
}

void task19() {
    int count[10] = {0, };

    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int entry;
        std::cin >> entry;

        count[entry]++;
    }

    for (int i = 0; i < 10; i++) {
        if (count[i] != 0)
            std::cout << i << ": " << count[i] << std::endl;
    }
}

void sort(long long arr[], int n) {
    for (int j = 0; j < n; j++) {

        bool isUnsorted = false;
        for (int i = 0; i < n - j - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                isUnsorted = true;
            }
        }

        if (!isUnsorted) return;
    }
}

void printArray(long long arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << ' ';
    }
}

void task20() {
    int n;
    std::cin >> n;

    long long arr[100000];

    for (int i = 0; i < n; i++) std::cin >> arr[i];
    sort(arr, n);
    printArray(arr, n);
}

void task21() {
    srand( time(nullptr) );

    const int rows = 10, columns = 8;
    int arr[columns][rows] = {{0,}, };

    int rndCol = rand() % columns,
        rndRow = rand() % rows;

    arr[rndCol][rndRow] = -1;

    int attempts = 5;
    while (attempts) {
        int row, col;
        std::cin >> row >> col;

        if (row >= rows || col >= columns) {
            std::cout << "Выход за границу массива\n";
            continue;
        }

        if (arr[col][row] == -1) {
            std::cout << "Вы угадали\n";
            return;
        }
        else {
            if (arr[col][row] == 0) {
                std::cout << "Нет\n";
                attempts--;
            }
            else {
                std::cout << "Эту уже проверяли\n";
            }
            arr[col][row]++;
        }
    }

    std::cout << "GAME OVER\n";
}

void swap(int* a, int* b) {
    *a += *b;

    *b = *a - *b;
    *a = *a - *b;
}

int msort(int* a, int* b, int* c) {
    // Сортируем первые два элемента между собой
    if (*a > *b) swap(a, b);
    // Убеждаемся, что справа стоит максимальный элемент
    if (*b > *c) {
        swap(b, c);

        if (*a > *b) swap(a, b);    // Бывший правый элемент мог быть меньше, чем левый, ставим в нужную позицию
    }

    return *c;
}

void info(const int* var) {
    std::cout << "Адрес: " << var << "; Значение: " << *var << '\n';
}

int* add(int* a, const int* b) {
    *a = *a + *b;
    return a;
}

void task22() {
    int a = 2, b = 3, c = 1;
    info(&a);
    info(&b);
    info(&c);

    std::cout << "Максимум: " << msort(&a, &b, &c) << '\n';
    info( add(&a, add(&b, &c)) );
}

char rusA  = static_cast<char>(192),
     rusYa = static_cast<char>(223);

char toLowerCase(char c) {
    // Введена заглавная английская буква
    if (c >= 'A' && c <= 'Z') {
        return c + 32;      // Сдвиг до маленьких букв в таблице
    }

    // Остальное уже нам подходит
    return c;
}

bool isValid(char c) {
    // Все цифры и английские буквы
    return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'z');
}

size_t strlen(const char* string);

bool isPalindrome(char str[]) {
    int len = strlen(str);

    // Для хранения "очищенной" строки
    char* copy = new char[len + 1];

    // Очистка строки от нежелаемых символов и перевод верхнего регистра в нижний
    int copyI = 0;
    for (int originI = 0; originI < len; originI++) {
        char c = str[originI];

        if (isValid(c)) {
            copy[copyI++] = toLowerCase(c);
        }
    }

    copy[copyI] = '\0';
    len = copyI;    // copyI после цикла теперь можно рассматривать как длину строки copy

    if (len == 0) return false;

    for (int i = 0; i < len / 2; i++) {
        if (copy[i] != copy[len-i-1]) return false;
    }

    return true;
}

void task23() {
    char* str = new char[21];
    std::cout << "Введите строку: ";
    std::cin.ignore();
    std::cin.getline(str, 21);

    std::cout << (isPalindrome(str) ? "Палиндром\n" : "Не палиндром\n");
}

size_t strlen(const char* string) {
    size_t i = 0;
    while (string[i++] != '\0');

    return i - 1;
}

int strcmp(const char* string1, const char* string2) {
    size_t i = 0;
    while (string1[i] != '\0' && string2[i] != '\0') {
        if (string1[i] != string2[i])
            return string1[i] - string2[i];
        i++;
    }

    return 0;
}

char* strstr(char* string1, const char* string2) {
    size_t len1 = strlen(string1),
           len2 = strlen(string2);

    if (len2 > len1) return nullptr;

    for (size_t i = 0; i <= len1 - len2; i++) {
        bool stringsMatch = true;
        size_t ind1 = i, ind2 = 0;

        while (ind2 < len2) {
            if (string1[ind1++] != string2[ind2++]) {
                stringsMatch = false;
                break;
            }
        }

        if (stringsMatch) return string1 + i;
    }

    return nullptr;
}

char* strcat(char* destptr, const char* srcptr) {
    size_t len1 = strlen(destptr),
           len2 = strlen(srcptr);

    for (size_t i = 0; i < len2; i++) {
        destptr[len1 + i] = srcptr[i];
    }
    destptr[len1 + len2] = '\0';

    return destptr;
}

void task24() {
    char str1[101], str2[51];
    std::cout << "Введите первую строку: ";
    std::cin.ignore();
    std::cin.getline(str1, 50);

    std::cout << "Введите вторую строку: ";
    std::cin.getline(str2, 50);

    std::cout << strlen(str1) << ' ' << strlen(str2) << '\n';

    int cmpresult = strcmp(str1, str2);
    if (cmpresult == 0) {
        std::cout << "Строки равны\n";
    }
    else if (cmpresult < 0) {
        std::cout << "Строка 2 больше строки 1\n";
    }
    else {
        std::cout << "Строка 1 больше строки 2\n";
    }

    char* substr = strstr(str1, str2);
    if (substr == nullptr) {
        std::cout << "-1\n";
    }
    else {
        std::cout << static_cast<int>(substr - str1) << '\n';
    }

    std::cout << strcat(str1, str2) << '\n';
}

void task25() {

}

void task26() {

}

void task27() {

}

void task28() {

}

void task29() {

}

void task30() {

}