#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int** M, i, j, n, k, * C, q;

void cdeep(int k) {
    for (int i = 0; i < n; i++) {
        if (M[k][i] == 1 && C[i] == 0) {
            C[i] = q;
            cdeep(i);
        }
    }
}

void MatSmech() {
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

    C = new int[n];
    for (int i = 0; i < n; i++) C[i] = 0;

    q = 0;
    for (int i = 0; i < n; i++) {
        if (C[i] == 0) {
            q++;
            C[i] = q;
            cdeep(i);  
        }
    }

    fout << q << endl;

    for (int t = 1; t <= q; t++) {
        for (int i = 0; i < n; i++) {
            if (C[i] == t) {
                fout << i << " ";
            }
        }
        fout << endl;
    }

    for (int i = 0; i < n; i++) delete[] M[i];
    delete[] M;
    delete[] C;

    fout.close();
}


int main() {
    MatSmech();
}
