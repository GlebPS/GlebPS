#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    if (num <= 3) {
        return true;
    }
    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

bool isPowerOf22(int N) {
    if (N <= 0 || N == 1) {
        return false;
    }
    while (N % 22 == 0) {
        N /= 22;
    }
    return N == 1;
}

void printDigitsInReverse(int N) {
    if (N == 0) {
        return;
    }
    cout << N % 10;
    printDigitsInReverse(N / 10);
}

int greatestCommonDivisor(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int x1, x2, y1, y2;

    cout << "Введите (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Введите (x2 y2): ";
    cin >> x2 >> y2;

    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    cout << "Расстояние между точками: " << distance << endl;

    int num1, num2;

    cout << "Введите первое целое число: ";
    cin >> num1;
    cout << "Введите второе целое число: ";
    cin >> num2;

    cout << "Среднее арифметическое: " << (num1 + num2) / 2 << endl;

    int num3, num4;

    cout << "Введите первое целое число: ";
    cin >> num3;
    cout << "Введите второе целое число: ";
    cin >> num4;

    cout << "Среднее геометрическое: " << sqrt(num3 * num4) << endl;

    int side1, side2, side3;

    cout << "Введите длины трех отрезков: ";
    cin >> side1 >> side2 >> side3;

    if (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1) {
        if (side1 == side2 && side2 == side3) {
            cout << "Треугольник равносторонний." << endl;
        } else if (side1 == side2 || side2 == side3 || side1 == side3) {
            cout << "Треугольник равнобедренный." << endl;
        } else {
            cout << "Треугольник разносторонний." << endl;
        }
    } else {
        cout << "Треугольник не существует." << endl;
    }

    double t1, t2, t3;

    cout << "Введите t1, t2 и t3: ";
    cin >> t1 >> t2 >> t3;

    double maxTime = max(max(t1, t2), t3);
    cout << "Максимальное время: " << maxTime << endl;

    int n;
    cout << "Введите n: ";
    cin >> n;

    int doubleFactorial = 1;
    while (n > 0) {
        doubleFactorial *= n;
        n -= 2;
    }
    cout << "Двойной факториал: " << doubleFactorial << endl;

    int n2;
    cout << "Введите n: ";
    cin >> n2;

    int doubleFactorial2 = 1;
    for (int i = n2; i > 0; i -= 2) {
        doubleFactorial2 *= i;
    }
    cout << "Двойной факториал: " << doubleFactorial2 << endl;

    int a, b;

    cout << "Введите интервал [a, b]: ";
    cin >> a >> b;

    if (a <= 2) {
        cout << "Простые числа в интервале [" << 2 << ", " << b << "]: 2 ";
    }
    for (int i = (a % 2 == 0 ? a + 1 : a); i <= b; i += 2) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;

    int number;
    int sequenceSum = 0;

    cout << "Введите последовательность чисел, завершите ввод числом -9999:" << endl;
    while (true) {
        cin >> number;
        if (number == -9999) {
            break;
        }
        sequenceSum += number;
    }
    cout << "Сумма всех элементов последовательности (исключая -9999): " << sequenceSum << endl;

    int number18;
    int min18 = INT_MAX;
    int max18 = INT_MIN;

    cout << "Введите последовательность чисел, завершите ввод числом 0:" << endl;
    while (true) {
        cin >> number18;
        if (number18 == 0) {
            break;
        }
        if (number18 > max18) {
            max18 = number18;
        }
        if (number18 < min18) {
            min18 = number18;
        }
    }
    if (min18 == INT_MAX || max18 == INT_MIN) {
        cout << "В последовательности только нули." << endl;
    } else {
        cout << "Минимальное значение: " << min18 << endl;
        cout << "Максимальное значение: " << max18 << endl;
    }

    int N;
    cout << "Введите N: ";
    cin >> N;
    int item = 1;
    int squareItem = item * item;
    cout << "Точные квадраты натуральных чисел, не превосходящие " << N << ":" << endl;
    while (squareItem <= N) {
        cout << squareItem << " ";
        item++;
        squareItem = item * item;
    }
    cout << endl;

    if (isPowerOf22(N)) {
        cout << N << " является степенью числа 22" << endl;
    } else {
        cout << N << " не является степенью числа 22" << endl;
    }

    int number1, number2;
    cout << "Введите два положительных целых числа: ";
    cin >> number1 >> number2;

    if (number1 <= 0 || number2 <= 0) {
        cout << "Числа должны быть положительными." << endl;
        return 1;
    }

    int gcdResult = greatestCommonDivisor(number1, number2);
    cout << "Наибольший общий делитель (НОД) чисел " << number1 << " и " << number2 << " = " << gcdResult << endl;

    int mark;
    cout << "Введите оценку в школе (1-5): ";
    cin >> mark;
    string description;
    switch (mark) {
        case 1:
            description = "неудовлетворительно";
            break;
        case 2:
            description = "неудовлетворительно";
            break;
        case 3:
            description = "удовлетворительно";
            break;
        case 4:
            description = "хорошо";
            break;
        case 5:
            description = "отлично";
            break;
        default:
            description = "оценка не является допустимой";
            break;
    }
    cout << "Словесное описание оценки: " << description << endl;
}
