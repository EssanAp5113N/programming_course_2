#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int** M, i, j, n, m, k;
    ifstream fin("Test.txt");
    ofstream fout("Rez1.txt");

    fin >> n;
    M = new int* [n];
    for (i = 0; i < n; i++)
    {
        M[i] = new int[n];
        for (j = 0; j < n; j++) M[i][j] = 0;
    }
    fin >> m;
    for (k = 0; k < m; k++)
    {
        fin >> i >> j;
        M[i - 1][j - 1] = 1; M[j - 1][i - 1] = 1;
    }

    fin.close();
    fout << "   ";

    for (i = 0; i < n; i++) {
        fout << i + 1;
        fout << "  ";
    }
    fout << "\n";

    for (i = 0; i < n; i++) {
        fout << i + 1;
        fout << "  ";
        for (j = 0; j < n; j++) {
            fout << M[i][j];
            fout << "  ";
        }
        fout << "\n";
    }
    fout.close();
    return 0;
}
