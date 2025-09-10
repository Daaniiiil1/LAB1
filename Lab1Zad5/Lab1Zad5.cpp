#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string surname;
    string name;
    int age;
    string group;
};

// Функция для ввода данных студента
Student inputStudent() {
    Student s;
    cout << "Фамилия: ";
    cin >> s.surname;
    cout << "Имя: ";
    cin >> s.name;
    cout << "Возраст: ";
    cin >> s.age;
    cout << "Группа: ";
    cin >> s.group;
    return s;
}

// Функция для вывода данных студента
void printStudent(const Student& s) {
    cout << "Фамилия: " << s.surname << endl;
    cout << "Имя: " << s.name << endl;
    cout << "Возраст: " << s.age << endl;
    cout << "Группа: " << s.group << endl;
    cout << "------------------------" << endl;
}

// Функции поиска
vector<Student> findBySurname(const vector<Student>& students, const string& surname) {
    vector<Student> result;
    for (const auto& s : students) {
        if (s.surname == surname) {
            result.push_back(s);
        }
    }
    return result;
}

vector<Student> findByName(const vector<Student>& students, const string& name) {
    vector<Student> result;
    for (const auto& s : students) {
        if (s.name == name) {
            result.push_back(s);
        }
    }
    return result;
}

vector<Student> findByAge(const vector<Student>& students, int age) {
    vector<Student> result;
    for (const auto& s : students) {
        if (s.age == age) {
            result.push_back(s);
        }
    }
    return result;
}

vector<Student> findByGroup(const vector<Student>& students, const string& group) {
    vector<Student> result;
    for (const auto& s : students) {
        if (s.group == group) {
            result.push_back(s);
        }
    }
    return result;
}



int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    vector<Student> students = {
        {"Иванов", "Иван", 20, "ИТ-101"},
        {"Петров", "Петр", 21, "ИТ-101"},
        {"Сидорова", "Мария", 19, "ИТ-102"},
        {"Иванов", "Алексей", 20, "ИТ-102"},
        {"Кузнецова", "Елена", 22, "ИТ-101"}
    };

    int choice;
    do {
        cout << "\n=== ПОИСК СТУДЕНТОВ ===" << endl;
        cout << "1. По фамилии" << endl;
        cout << "2. По имени" << endl;
        cout << "3. По возрасту" << endl;
        cout << "4. По группе" << endl;
        cout << "5. Показать всех студентов" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите вариант: ";
        cin >> choice;


        switch (choice) {
        case 1: {
            string surname;
            cout << "Введите фамилию: ";
            cin >> surname;
            auto result = findBySurname(students, surname);
            if (result.empty()) {
                cout << "Студенты с фамилией '" << surname << "' не найдены." << endl;
            }
            else {
                cout << "Найдено " << result.size() << " студентов:" << endl;
                for (const auto& s : result) {
                    printStudent(s);
                }
            }
            break;
        }
        case 2: {
            string name;
            cout << "Введите имя: ";
            cin >> name;
            auto result = findByName(students, name);
            if (result.empty()) {
                cout << "Студенты с именем '" << name << "' не найдены." << endl;
            }
            else {
                cout << "Найдено " << result.size() << " студентов:" << endl;
                for (const auto& s : result) {
                    printStudent(s);
                }
            }
            break;
        }
        case 3: {
            int age;
            cout << "Введите возраст: ";
            cin >> age;
            auto result = findByAge(students, age);
            if (result.empty()) {
                cout << "Студенты возраста " << age << " не найдены." << endl;
            }
            else {
                cout << "Найдено " << result.size() << " студентов:" << endl;
                for (const auto& s : result) {
                    printStudent(s);
                }
            }
            break;
        }
        case 4: {
            string group;
            cout << "Введите группу: ";
            cin >> group;
            auto result = findByGroup(students, group);
            if (result.empty()) {
                cout << "Студенты группы '" << group << "' не найдены." << endl;
            }
            else {
                cout << "Найдено " << result.size() << " студентов:" << endl;
                for (const auto& s : result) {
                    printStudent(s);
                }
            }
            break;
        }
        case 5: {
            cout << "Все студенты (" << students.size() << "):" << endl;
            for (const auto& s : students) {
                printStudent(s);
            }
            break;
        }
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Неверный выбор!" << endl;
        }
    } while (choice != 0);

    return 0;
}
