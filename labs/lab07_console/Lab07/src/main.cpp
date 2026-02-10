#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Задание 1: вычисление значений функции.

    double x0 = 0.0;
    double otst;
    cin >> x0;

    otst = (4 - x0) / 9;

    for (int i = 0; i < 10; i++) {
        double xi = x0 + i * otst;
        cout << sin(xi) / xi << endl;
    }
}
