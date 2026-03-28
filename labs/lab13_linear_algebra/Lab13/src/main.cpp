#include <iostream>
using namespace std;

float eps = 0.000001;
int systema(int n, float** A, float* X) {
    return 0;
}

int main() {
    int i, j, g, n, m;
    float **A, *X;
    scanf_s("%d", &m);
    scanf_s("%d", &n);
    X = new float[n];
    A = new float*[m];
    for (i = 0; i < m; i++) {
        A[i] = new float[n + 1];
        for (j = 0; j <= n; j++) {
            scanf_s("%f", &A[i][j]);
        }
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j <= n; j++) {
            printf("%f", A[i][j]);
        }
    }
    g = systema(n, A, X);
    if (g) {
        for (i = 0; i < n; i++) {
            printf("%8.3f", X[i]);
        }
    }
    else {
        printf("ERROR\n");
    }
}
