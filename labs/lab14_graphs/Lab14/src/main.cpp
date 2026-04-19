#include <iostream>

int main() {
    int** M, i, j, n, m, k;
    scanf_s("%d", &n);
    M = new int* [n];
    for (i = 0; i < n; i++)
    {
        M[i] = new int[n];
        for (j = 0; j < n; j++) M[i][j] = 0;
    }
    scanf_s("%d", &m);
    for (k = 0; k < m; k++)
    {
        scanf_s("%d%d", &i, &j);
        M[i - 1][j - 1] = 1; M[j - 1][i - 1] = 1;
    }

    printf("  ");

    for (i = 0; i < n; i++) {
        printf("%d", i + 1);
        printf("  ");
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        printf("%d", i + 1);
        printf(" ");
        for (j = 0; j < n; j++) {
            printf("%d", M[i][j]);
            printf("  ");
        }
        printf("\n");
    }
    return 0;
}
