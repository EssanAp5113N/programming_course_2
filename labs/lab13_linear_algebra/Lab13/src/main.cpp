#include <iostream>
using namespace std;

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

        c = A[i][i];
        for (j = i; j <= n; j++)
        {
            A[i][j] = A[i][j] / c;
        }

        for (k = i + 1; k < m; k++)
        {
            c = A[k][i];
            if (abs(c) > eps)
            {
                for (j = i; j <= n; j++)
                {
                    A[k][j] = A[k][j] - c * A[i][j];
                }
            }
        }
    }

    if (fabs(A[m - 1][n - 1]) > eps)
    {
        c = A[m - 1][n - 1];
        for (j = n - 1; j <= n; j++)
        {
            A[m - 1][j] = A[m - 1][j] / c;
        }
    }

    return 1;
}

int main() {
    int i, j, g, n, m;
    float **A;
    scanf_s("%d", &m);
    scanf_s("%d", &n);
    A = new float*[m];
    for (i = 0; i < m; i++) {
        A[i] = new float[n + 1];
        for (j = 0; j <= n; j++) {
            scanf_s("%f", &A[i][j]);
        }
    }
    g = systema(m, n, A);
    if (g) {
            for (i = 0; i < m; i++)
            {
                for (j = 0; j <= n; j++)
                {
                    cout << A[i][j] << "\t";
                }
                cout << endl;
            }
    }
    else {
        printf("ERROR\n");
    }

    for (i = 0; i < m; i++) {
        delete[] A[i];
    }
    delete[] A;
   
}
