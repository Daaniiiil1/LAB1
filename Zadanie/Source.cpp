#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    int ROWS, COLS;
    double probability;

    // Ввод размерности массива
    cout << "Введите количество строк: ";
    cin >> ROWS;
    cout << "Введите количество столбцов: ";
    cin >> COLS;

    // Ввод вероятности выпадения 1 (от 0 до 1)
    cout << "Введите вероятность выпадения 1 (0.0 - 1.0): ";
    cin >> probability;

    // Проверка корректности ввода
    if (ROWS <= 0 || COLS <= 0) {
        cout << "Ошибка: размерность должна быть положительной!" << endl;
        return 1;
    }

    if (probability < 0 || probability > 1) {
        cout << "Ошибка: вероятность должна быть в диапазоне 0.0 - 1.0!" << endl;
        return 1;
    }

    // Инициализация генератора случайных чисел
    srand(time(0));

    // Создание динамического двумерного массива
    int** mass = new int* [ROWS];
    for (int i = 0; i < ROWS; i++) {
        mass[i] = new int[COLS];
    }

    // Заполнение массива 0 и 1 с заданной вероятностью
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            double randomValue = static_cast<double>(rand()) / RAND_MAX;
            if (randomValue < probability) {
                mass[i][j] = 1;
            }
            else {
                mass[i][j] = 0;
            }
        }
    }

    // Вычисление суммы по столбцам
    int* columnSums = new int[COLS]();

    for (int j = 0; j < COLS; j++) {
        for (int i = 0; i < ROWS; i++) {
            columnSums[j] += mass[i][j];
        }
    }

    // Вывод массива
    cout << "\nМассив:" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << mass[i][j] << " ";
        }
        cout << endl;
    }

    // Вывод сумм по столбцам
    cout << "\nСуммы по столбцам:" << endl;
    for (int j = 0; j < COLS; j++) {
        cout << "Столбец " << j + 1 << ": " << columnSums[j] << endl;
    }

    // Вычисление и вывод статистики
    int totalOnes = 0;
    for (int j = 0; j < COLS; j++) {
        totalOnes += columnSums[j];
    }

    cout << "\nСтатистика:" << endl;
    cout << "Всего элементов: " << ROWS * COLS << endl;
    cout << "Количество единиц: " << totalOnes << endl;
    cout << "Заданная вероятность: " << probability << endl;

    // Освобождение памяти
    for (int i = 0; i < ROWS; i++) {
        delete[] mass[i];
    }
    delete[] mass;
    delete[] columnSums;

    return 0;
}