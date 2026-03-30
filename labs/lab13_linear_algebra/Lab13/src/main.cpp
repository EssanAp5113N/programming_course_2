#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

// Проверка создания ветки

float eps = 0.000001;
int systema(int m, int n, float** A) {
    int i, j, k, v;
    float c;

    for (i = 0; i < m; i++) {
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
            c = A[k][i] / A[i][i];
            if (fabs(c) > eps) {
                for (j = i; j <= n; j++) {
                    A[k][j] -= c * A[i][j];
                }
            }
        }
    }
    return 1;
}

int main() {
    int i, j, g, n, m;
    float **A;
    ifstream fin("Test.txt");
    ofstream fout("output.txt");

    fin >> m >> n;
    A = new float* [m];

    for (i = 0; i < m; i++) {
        A[i] = new float[n + 1];
        for (j = 0; j <= n; j++) {
            fin >> A[i][j];
        }
    }
    fin.close();

    g = systema(m, n, A);
    if (g) {
            for (i = 0; i < m; i++)
            {
                for (j = 0; j <= n; j++)
                {
                    fout << A[i][j] << "\t";
                }
                fout << endl;
            }
    }
    else {
        printf("ERROR\n");
    }

    fout.close();

    for (i = 0; i < m; i++) {
        delete[] A[i];
    }
    delete[] A;
   
}
