#include <iostream>
using namespace std;
int main() {
    int x[] = { 2, 3, -1, 4, 5}; // Пример массива x
    int m = -1; // Инициализируем m значением -1 (если в массиве нет отрицательных элементов, то будет использоваться последний элемент)
    for (int i = 0; i < sizeof(x) / sizeof(x[0]); i++) {
        if (x[i] < 0) {
            m = i-1; // Найден отрицательный элемент
            break; // Прерываем цикл
        }
    }
    int y = 0;
    int product = 1;
    for (int i = 0; i <= m; i++) {
        product *= x[i]; // Вычисляем  x1 * x2 * ... * xm
        y += product; // Добавляем произведение к y
    }
    cout << "Значение у: " << y << endl;
    return 0;
}