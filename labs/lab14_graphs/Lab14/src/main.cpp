#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void MatSmech() {
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

    fout << n << endl;
    fout << m;
    fout << "\n";




    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            fout << M[i][j];
            fout << "  ";
        }
        fout << "\n";
    }
    fout.close();
}

void Spicok() {
    ifstream input("Rez1.txt");
    ofstream output("Rez2.txt");
 
    int* v1, * v2, * D, * S, * L, * U;
    int i, n, m, k, j;
    input >> n;
    input >> m;
    v1 = new int[m]; 
    v2 = new int[m];
    m = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            input >> val;
            if (val == 1 && i < j) {
                v1[m] = i;
                v2[m] = j;
                m++;
            }
        }
    }
    input.close();
    D = new int[m + m]; 
    S = new int[n];
    L = new int[n]; 
    U = new int[n];

    input.close();

    for (j = 0; j < n; j++) L[j] = 0;
    for (i = 0; i < m; i++) 
    {
        L[v1[i]]++; 
        L[v2[i]]++;
    }
    S[0] = 0; 
    for (j = 1; j < n; j++) S[j] = S[j - 1] + L[j - 1];
    for (j = 0; j < n; j++) U[j] = S[j];
    
    for (i = 0; i < m; i++) 
    {
        k = v1[i]; D[U[k]] = v2[i]; U[k]++;
        k = v2[i]; D[U[k]] = v1[i]; U[k]++;
    }

    output << n << "\n";
    for (j = 0; j < n; j++) {
        output << L[j] << " ";
    }
    output << "\n";

    for (j = 0; j < n; j++) {
        output << S[j] << " ";
    }
    output << "\n";

    for (i = 0; i < m + m; i++) {
        output << D[i] + 1 << " ";
    }

    delete[] v1;
    delete[] v2;
    delete[] D;
    delete[] S;
    delete[] L;
    delete[] U;

    output.close();

}

void Rebra() {
    ifstream input("Rez2.txt");
    ofstream output("Rez3.txt");

    int n;
    int *L, *S, *D;

    input >> n;
    
    L = new int[n];
    S = new int[n];

    for (int j = 0; j < n; j++) {
        input >> L[j];
    }

    for (int j = 0; j < n; j++) {
        input >> S[j];
    }

    int sumL = 0;
    for (int j = 0; j < n; j++) {
        sumL += L[j];
    }
    int m = sumL / 2;

    D = new int[2 * m];
    for (int i = 0; i < 2 * m; i++) {
        input >> D[i];
    }
    input.close();

    output << n << "\n";
    output << m << "\n";

    for (int i = 0; i < n; i++) {
        for (int j = S[i]; j < S[i] + L[i]; j++) {
            int neighbor = D[j];
            if (i < neighbor) {
                output << i + 1<< " " << neighbor << "\n";
            }
        }
    }

    delete[] L;
    delete[] S;
    delete[] D;

    output.close();
}

int main() {
    MatSmech();
    Spicok();
    Rebra();
}
