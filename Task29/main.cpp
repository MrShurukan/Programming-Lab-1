#include <iostream>
#include <cstring>
#include <sstream> // для std::stringstream
#include <cstdlib> // для exit()

int main(int argc, char** argv) {
    setlocale(LC_ALL, "Russian");

    std::cout << argv[0] << std::endl;

    // Поиск -help
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-help") == 0) {
            std::cout << "'-help' Отображает информацию о поддерживаемых аргументах\n\n"

            "'-n <имя>' Выводит на экран сообщение: 'Привет, <имя>'. Если задан ключ -n, то слежующий за ним агрумент "
            "КС воспринимается как <имя>. Если <имя> не задано, выводится сообщение об ошибке\n\n"

            "'-b' Если задан данный ключ, то в предыдущем сообщении вместо 'Привет', будет 'Пока'\n\n"

            "'-w' Если задан данный ключ, то программа спросит у пользователя как его зовут "
            "и если задан '-n', то в сообщении 'Привет, <имя>' вместо <имя> будет выведено то имя которое введено "
            "пользователем, при этом параметр <имя> после ключа '-n' вводить не обязательно\n";

            exit(0);
        }
    }

    // Обработка остальных параметров
    bool isNPresent = false;
    std::string name = "";
    bool isBPresent = false;
    bool isWPresent = false;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0) {
            if (i + 1 >= argc && !isWPresent) {
                std::cout << "Ошибка: имя не задано!";
                exit(0);
            }

            if (strcmp(argv[i + 1], "-w") != 0)
                name = argv[i + 1];
            else
                isWPresent = true;

            isNPresent = true;
            i++;
        }
        else if (strcmp(argv[i], "-b") == 0) isBPresent = true;
        else if (strcmp(argv[i], "-w") == 0) isWPresent = true;
        else {
            std::cout << '"' << argv[i] << "\" - недопустимый параметр\n";
            exit(0);
        }
    }

    if (isWPresent) {
        std::cout << "Как вас зовут? ";
        std::cin >> name;
    }
    if (isNPresent) {
        if (isBPresent)
            std::cout << "Пока, " << name << std::endl;
        else
            std::cout << "Привет, " << name << std::endl;
    }

    return 0;
}