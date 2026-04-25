#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void MatSmech() {
    int** M, i, j, n, k;
    ifstream fin("Test.txt");
    ofstream fout("GenMat.txt");

    fin >> n;
    M = new int* [n];
    for (i = 0; i < n; i++)
    {
        M[i] = new int[n];
        for (j = 0; j < n; j++) M[i][j] = 0;
    }
    
    while (fin >> i >> j)
    {
        if (i == -1 && j == -1) break;
        M[i][j] = 1; M[j][i] = 1;
    }

    fin.close();


    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            fout << M[i][j];
            fout << "  ";
        }
        fout << "\n";
    }
    fout.close();
}


int main() {
    MatSmech();
}
