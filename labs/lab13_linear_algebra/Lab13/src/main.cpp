#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

// Проверка создания ветки Повторная проверка

float eps = 1e-9;
int systema(int m, int n, float** A, float* X) {
    int i, j, k, v;
    float c;

    for (i = 0; i < m && i < n; i++) {
        v = i;
        for (j = i + 1; j < m; j++) {
            if (abs(A[j][i]) > abs(A[v][i])) {
                v = j;
            }
        }

        if (fabs(A[v][i]) < eps)
            continue;

        if (v != i) {
            for (j = i; j <= n; j++) {
                c = A[i][j];
                A[i][j] = A[v][j];
                A[v][j] = c;
            }
        }

        for (k = i + 1; k < m; k++) {
            if (fabs(A[i][i]) < eps) continue;
            c = A[k][i] / A[i][i];
            if (fabs(c) > eps) {
                for (j = i; j <= n; j++) {
                    A[k][j] -= c * A[i][j];
                }
            }
        }
    }

    for (i = 0; i < m; i++) {
        bool all_zero = true;
        for (j = 0; j < n; j++) {
            if (fabs(A[i][j]) > eps) {
                all_zero = false;
                break;
            }
        }
        if (all_zero && fabs(A[i][n]) > eps) {
            return -1;
        }
    }

    int rank = 0;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (fabs(A[i][j]) > eps) {
                rank++;
                break;
            }
        }
    }
    if (rank < n) {
        return 0;  
    }

    for (i = n - 1; i >= 0; i--) {
        for (k = 0; k < i; k++) {
            c = A[k][i] / A[i][i];
            A[k][n] -= c * A[i][n];
            A[k][i] = 0;
        }
    }

    for (i = 0; i < n; i++) {
        X[i] = A[i][n] / A[i][i];
    }
    return 1;
}

int main() {
    int i, j, g, n, m;
    float **A, *X;
    ifstream fin("Test.txt");
    ofstream fout("output.txt");

    fin >> m >> n;

    X = new float[n];
    A = new float* [m];

    for (i = 0; i < m; i++) {
        A[i] = new float[n + 1];
        for (j = 0; j <= n; j++) {
            fin >> A[i][j];
        }
    }
    fin.close();

    g = systema(m, n, A, X);

    if (g == 1) {
            for (i = 0; i < n; i++)
            {
                fout << X[i] << "\t";
            }
            fout << endl;
    }
    else if (g == -1) {
        fout << "Система НЕСОВМЕСТНА" << endl;
    }
    else if (g == 0) {
        fout << "Система имеет бесконечное число решений" << endl;
    }

    fout.close();

    for (i = 0; i < m; i++) {
        delete[] A[i];
    }
    delete[] A;
    delete[] X;
   
}
