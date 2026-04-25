#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int** M, i, j, n, k, * C1, q1, *C2, q2;


struct el {
    int s;
    struct el* p;
};

el** S;

void cdeep_m(int k) {
    for (int i = 0; i < n; i++) {
        if (M[k][i] == 1 && C1[i] == 0) {
            C1[i] = q1;
            cdeep_m(i);
        }
    }
}

void cdeep_list(int k) {
    for (el* p1 = S[k]; p1 != NULL; p1 = p1->p) {
        if (C2[p1->s] == 0) {
            C2[p1->s] = q2;
            cdeep_list(p1->s);
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

    C1 = new int[n];
    for (int i = 0; i < n; i++) C1[i] = 0;

    q1 = 0;
    for (int i = 0; i < n; i++) {
        if (C1[i] == 0) {
            q1++;
            C1[i] = q1;
            cdeep_m(i);  
        }
    }

    fout << q1 << endl;

    for (int t = 1; t <= q1; t++) {
        for (int i = 0; i < n; i++) {
            if (C1[i] == t) {
                fout << i << " ";
            }
        }
        fout << endl;
    }

    for (int i = 0; i < n; i++) delete[] M[i];
    delete[] M;
    delete[] C1;

    fout.close();
}

void Spisok() {
    ifstream fin("Test.txt");
    ofstream fout("GenSpisok.txt");

    int n, a, b;
    fin >> n;

    el **S = new el * [n];
    for (int i = 0; i < n; i++) S[i] = NULL;

    while (fin >> a >> b) {
        if (a == -1 && b == -1) break;

        el* ps = new el;
        ps->s = b;
        ps->p = S[a];
        S[a] = ps;

        ps = new el;
        ps->s = a;
        ps->p = S[b];
        S[b] = ps;
    }
    fin.close();

    C2 = new int[n];
    for (int i = 0; i < n; i++) C2[i] = 0;

    q2 = 0;
    for (int i = 0; i < n; i++) {
        if (C2[i] == 0) {
            q2++;
            C2[i] = q2;
            cdeep_list(i);
        }
    }

    fout << "Деревьев: " << q2 << endl << endl;

    for (int t = 1; t <= q2; t++) {
        for (int i = 0; i < n; i++) {
            if (C2[i] == t) fout << i << " ";
        }
        fout << endl;
    }

    fout.close();

    for (int i = 0; i < n; i++) {
        el* current = S[i];
        while (current != NULL) {
            el* temp = current;
            current = current->p;
            delete temp;
        }
    }
    delete[] S;
    delete[] C2;

}

int main() {
    MatSmech();
    Spisok();
}
