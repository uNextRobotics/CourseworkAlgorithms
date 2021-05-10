#include <iostream>
using namespace std;

const double goldenRatio = (1 + sqrt(5)) / 2; // "Золотое" число

// Рассматриваемая нами функция
double func(double x) {
    return log(1 + x * x - cos(x)) - pow(M_E, sin(M_PI * x));
}

int main() {
    double a, b; // Концы отрезка

    double accuracy; // Точность, с которой мы находим локальный максимум
    double x1, x2; // Точки, делящие текущий отрезок в отношении золотого сечения
    cout << "Введите концы отрезка (числа a и b):" << endl;
    cin >> a >> b;
    cout << "Введите точность эпсилон: " << endl;
    cin >> accuracy;
    while (fabs(b - a) > accuracy) {
        x1 = b - (b - a) / goldenRatio;
        x2 = a + (b - a) / goldenRatio;
        if (func(x1) <= func(x2)) // Условие для поиска максимума
            a = x1;
        else
            b = x2;
    } // Выполняем, пока не достигнем заданной точности
    cout << "Минимум функции:" << endl;
    cout << "x: " << (a + b) / 2 << endl;
    cout << "y: " << func((a + b) / 2) << endl;
    return 0;
}