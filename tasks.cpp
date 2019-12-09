#include <iostream>


void task1() {
    std::cout << "��������� ���������� ��������� 2+2*2 = " << 2 + 2 * 2;
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

    std::cout << "��: " << a << b << '\n';

    std::swap(a, b);

    std::cout << "�����: " << a << b << '\n';
    std::cout << "��: " << a << b << '\n';

    a = a + b;
    b = a - b;
    a = a - b;

    std::cout << "�����: " << a << b << '\n';
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
            std::cout << "����� ���������: (-Inf, Inf)\n";
        else
            std::cout << "����� ��������� ����������\n";

        return;
    }

    if (a == 0) {
        // ��� �� ���������� ���������, ������ ��� �������
        // � ���� ����� ��������� b �������������� �� ����� ����
        std::cout << "������ ���������: " << -(c / b) << '\n';

        return;
    }

    double D = b*b - 4*a*c;
    if (D < 0) {
        std::cout << "�������������� ������ ���.";
        return;
    }
    else if (D == 0) {
        // � ���� ����� ��������� a �������������� �� ����� ����
        std::cout << "������ ���������: " << -b / 2*a << '\n';
        return;
    }

    double sqrtD = std::sqrt(D);
    double x1 = (-b + sqrtD) / 2*a;
    double x2 = (-b - sqrtD) / 2*a;

    std::cout << "����� ���������: x1:" << x1 << ", x2: " << x2 << '\n';
}

#define sqr(x) (x) * (x)
#define getLength(xa, ya, xb, yb) std::sqrt(sqr(xb - xa) + sqr(yb - ya))
void task7() {
    std::cout << "1 - ����� ������, 2 - ���������� ������\n";
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
            std::cout << "������������ �����\n";
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
                std::cout << "������, ������� �� ����!";
                return;
            }
            std::cout << a / b;
            break;

        default:
            std::cout << "����������� ��������";
    }
    std::cout << '\n';
}

void task9() {
    std::random_device rd;
    std::mt19937 mersenne(rd()); // �������������� ����� �������� ��������� ��������� ������

    bool userWantsToExit = false;
    while (!userWantsToExit) {
        int n = static_cast<int>(mersenne() % 101);

        bool isGuessed = false;
        int attempts = 5;

        int guess;
        std::cout << "�������� ����� �� 1 �� 100: (� ��� ���� �������)\n";
        while (!isGuessed && attempts > 0) {
            std::cin >> guess;
            attempts--;

            if (n < guess) {
                std::cout << "�������� ����� ������";
            }
            else if (n > guess) {
                std::cout << "�������� ����� ������";
            }
            else {
                std::cout << "����������! �� �������";
                isGuessed = true;
            }
            std::cout << '\n';
        }

        if (attempts == 0 && !isGuessed) {
            std::cout << "�� ���������. ���� ��������: " << n << '\n';
        }

        int answ;
        std::cout << "������ ������ �������? (1 - ��): ";
        std::cin >> answ;
        if (answ != 1) userWantsToExit = true;
    }
    std::cout << "�� ����� ������!\n";
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
            std::cout << "���������\n";
            return;
        }

    std::cout << "�������\n";
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

    for (int i = 2; i*i <= n; i++) {    // ��������� �������� ��������� � ��������� �� [2, sqrt(n)]
        if (n % i == 0) {
            factAmount[i]++;
            factorization(n / i);   // ����� i - ���� �� ���������. ���������� ����� n / i ��������� ��������� ���� �� ��������
            return;
        }
    }

    // ���� ���������� ��� ���������� �� ������ �������� => ����� ������� � ��� ����� �������� ��� ��������
    factAmount[n]++;

    // ��������� ����� ���������, ����� ������:
    for (auto i = factAmount.begin(); i != factAmount.end(); i++) {
        int fact = i->first, amount = i->second;

        // ������� ��������� ����� ������, ����� �������
        if (i != factAmount.begin()) std::cout << '*';

        std::cout << fact;
        if (amount > 1) std::cout << "^" << amount;
    }
    std::cout << '\n';
}

void task16() {
    int n;
    std::cout << "������� n: ";
    std::cin >> n;

    factAmount.clear();    // ������� map �� ��������� ������� ����������
    factorization(n);
}

// ���������� ������ ����� ����.
double BMI(double weight, double height) {
    return weight / (height * height);
}

// ��������� ��������� �������� ��� � �������� �� ����� ��������������� ���������
void printBMI(double BMI) {
    if (BMI < 18.5)         std::cout << "Underweight\n";
    else if (BMI < 25.0)    std::cout << "Normal\n";
    else if (BMI < 30.0)    std::cout << "Overweight\n";
    else                    std::cout << "Obesity\n";
}

void task17() {
    double weight, height;
    std::cout << "������� ��� � ����: ";
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
            std::cout << "����� �� ������� �������\n";
            continue;
        }

        if (arr[col][row] == -1) {
            std::cout << "�� �������\n";
            return;
        }
        else {
            if (arr[col][row] == 0) {
                std::cout << "���\n";
                attempts--;
            }
            else {
                std::cout << "��� ��� ���������\n";
            }
            arr[col][row]++;
        }
    }

    std::cout << "GAME OVER\n";
}