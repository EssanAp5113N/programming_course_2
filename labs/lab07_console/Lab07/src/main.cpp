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

    // Задание 2: Число.

    int a = 0;
    int b = 1;
    int MAX;
    int t;
    int R;
    int S = 1;
    int n = 2;


    cin >> MAX;

    while (S <= MAX) {
        R = a + b;
        a = b;
        b = R;
        S += R;
        n += 1;
    }

    cout << n << ' ' << S << endl;

    // Задание 3: Долг.

    double S;
    double T;
    double Proc_god;
    double Proc_mes;
    double Proc_mes_tec;
    double Sum_Proc;
    double Plat;
    double S_tec;
    double Dolg_tec;
    double A;

    cin >> S;
    cin >> T;
    cin >> Proc_god;

    Proc_mes = Proc_god / 12 / 100;

    S_tec = S;

    A = S / T;

    S_tec = S;

    for (int i = 1; i <= 12; i++) {
        Proc_mes_tec = S_tec * Proc_mes;
        Sum_Proc += Proc_mes_tec;
        Dolg_tec = S_tec + Proc_mes_tec;

        Plat = Dolg_tec - (S - i * A);

        cout << i << '\t' << S_tec << '\t' << Proc_mes_tec << '\t' << Plat << endl;

        S_tec = Dolg_tec - Plat;

    }

    cout << Sum_Proc;

}
