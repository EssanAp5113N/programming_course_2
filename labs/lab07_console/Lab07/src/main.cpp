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

    double S;
    double T;
    double Proc_god;
    double Proc_mes;
    double Proc_mes_tec;
    double Sum_Proc;
    double Plat;
    double S_tec;
    double Dolg_tec;
    double Sum_Pid;
    double XX;

    cin >> S;
    cin >> T;
    cin >> Proc_god;

    Proc_mes = Proc_god / 12 / 100;

    Plat = S * (Proc_mes * pow(1 + Proc_mes, T)) / (pow((1 + Proc_mes), T) - 1);
    S_tec = S;

    for (int i = 1; i <= T; i++) {
        Proc_mes_tec = S_tec * Proc_mes;

        Dolg_tec = Plat - Proc_mes_tec;

        if (i == T) {
            Dolg_tec = S_tec;
            Plat = Dolg_tec + Proc_mes_tec;
        }

        XX = S_tec;

        S_tec -= Dolg_tec;

        Sum_Proc += Proc_mes_tec;


        cout << i << '\t' << XX << "\t" << Proc_mes_tec << '\t' << Dolg_tec << endl;
    }

    cout << Sum_Proc << endl;
}
