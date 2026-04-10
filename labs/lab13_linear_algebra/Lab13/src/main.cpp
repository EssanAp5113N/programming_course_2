#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

// Проверка создания ветки Повторная проверка

float eps = 1e-9;
int systema(int m, int n, float** A, float* X, int* free_vars, int& free_count) {
    int i, j, k, v;
    float c;

    for (i = 0; i < m && i < n; i++) {
        v = i;
        for (j = i + 1; j < m; j++) {
            if (fabs(A[j][i]) > fabs(A[v][i])) {
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
    int* basis_col = new int[n];
    bool* is_basis = new bool[n]();

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (fabs(A[i][j]) > eps) {
                rank++;
                basis_col[rank - 1] = j;
                is_basis[j] = true;
                break;
            }
        }
    }
    if (rank < n) {
        free_count = 0;
        for (j = 0; j < n; j++) {
            if (!is_basis[j]) {
                free_vars[free_count++] = j;
            }
        }

        for (i = rank - 1; i >= 0; i--) {
            int col = basis_col[i];
            if (fabs(A[i][col]) < eps) continue;

            for (k = 0; k < i; k++) {
                if (fabs(A[k][col]) < eps) continue;
                c = A[k][col] / A[i][col];
                A[k][n] -= c * A[i][n];
                A[k][col] = 0;
            }
        }

        for (i = 0; i < n; i++) {
            X[i] = 0;
        }

        for (i = 0; i < rank; i++) {
            int col = basis_col[i];
            if (fabs(A[i][col]) > eps) {
                X[col] = A[i][n] / A[i][col];
            }
        }

        delete[] basis_col;
        delete[] is_basis;
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
    delete[] basis_col;
    delete[] is_basis;
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
    int* free_vars = new int[n];
    int free_count = 0;

    for (i = 0; i < m; i++) {
        A[i] = new float[n + 1];
        for (j = 0; j <= n; j++) {
            fin >> A[i][j];
        }
    }
    fin.close();

    g = systema(m, n, A, X, free_vars, free_count);

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
        for (i = 0; i < n; i++) {
            fout << X[i] << "  ";
        }
        fout << endl;
        if (free_count > 0) {
            fout << "Свободные переменные: ";
            for (i = 0; i < free_count; i++) {
                fout << "x" << free_vars[i] + 1;
                if (i < free_count - 1) fout << ", ";
            }
            fout << endl;
        }
    }

    fout.close();

    for (i = 0; i < m; i++) {
        delete[] A[i];
    }
    delete[] A;
    delete[] X;
    delete[] free_vars;
}
