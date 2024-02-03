//Объявить и заполнить двумерный динамический массив случайными числами от 1 до 70. Показать его на экран. 
//Для заполнения и показа на экран написать отдельные функции.9 подсказака:функции должны принимать три параметра - 
//указатель на динамический массив, коллечество строк, коллечество столбцов. 
//Колличество строк и столбцов выбирает пользователь. 
//написать функцию, которая вычисляет сумму элементов, расположенных на побочной диагонали матрици. 
#include <iostream>
#include <cstdlib> // Для функций rand() и srand()
#include <ctime> // Для функции time()


using namespace std;

// Функция для создания двумерного динамического массива и его заполнения случайными числами
void fillArray(int**& array, int rows, int cols) {
    srand(time(0)); // Инициализация генератора случайных чисел
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = rand() % 70 + 1; // Заполнение элементов массива случайными числами от 1 до 70
        }
    }
}
// Функция для вывода двумерного динамического массива на экран
void printArray(int** array, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << array[i][j] << "\t"; // Вывод текущего элемента массива
        }
        cout << endl; // Переход на новую строку после вывода каждой строки массива
    }
}
// Функция для вычисления суммы элементов на побочной диагонали матрицы
int sumSecondaryDiagonal(int** array, int rows, int cols) {
    int sum = 0;
    if (rows != cols) {
        cout << "The matrix is not square, calculation is impossible." << endl;
        return -1; // Возврат ошибки, если матрица не квадратная
    }
    for (int i = 0; i < rows; i++) {
        sum += array[i][cols - 1 - i]; // Суммирование элементов побочной диагонали
    }
    return sum;
}
int main() {

    int rows, cols;
    
    cout << "Enter the number of lines: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    // Проверка на дурака
    if (rows <= 0 || cols <= 0) {
        cout << "The number of rows and columns must be greater than zero!" << endl;
        return 1; // Завершение программы с ошибкой
    }

    // Создание двумерного динамического массива
    int** array = new int*[rows];
    for (int i = 0; i < rows; i++) {
        array[i] = new int[cols];
    }
    fillArray(array, rows, cols); // Заполнение массива
    printArray(array, rows, cols); // Вывод массива на экран

    int sum = sumSecondaryDiagonal(array, rows, cols); // Вычисление суммы побочной диагонали
    if (sum != -1) { // Проверка на квадратную матрицу
        cout << "The sum of the elements on the side diagonal: " << sum << endl;
    }
    // Очистка памяти
    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}