#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

float eps = 1e-9;

bool parseEquation(const string& eq, float& a, float& b, float& c) {
    string s = eq;
    string clean = "";
    for (char ch : s) {
        if (!isspace(ch)) clean += ch;
    }

    size_t eqPos = clean.find('=');
    string left = clean.substr(0, eqPos);
    string right = clean.substr(eqPos + 1);

    c = stof(right);

    a = b = 0;
    size_t i = 0;
    float sign = 1.0;
    float coeff = 1.0;

    while (i < left.length()) {
        if (left[i] == '+') {
            sign = 1.0;
            i++;
        }
        else if (left[i] == '-') {
            sign = -1.0;
            i++;
        }
        else if (i == 0) {
            sign = 1.0;
        }

        coeff = 1.0;
        if (i < left.length() && (isdigit(left[i]) || left[i] == '.')) {
            size_t start = i;
            while (i < left.length() && (isdigit(left[i]) || left[i] == '.')) i++;
            coeff = stof(left.substr(start, i - start));
        }

        if (i < left.length() && left[i] == 'x') {
            a += sign * coeff;
            i++;
        }
        else if (i < left.length() && left[i] == 'y') {
            b += sign * coeff;
            i++;
        }
    }
    return true;
}

int systema(int m, int n, float** A, float* X) {
    int i, j, k, v;
    float c;

    for (i = 0; i < m && i < n; i++) {
        v = i;
        for (j = i + 1; j < m; j++) {
            if (fabs(A[j][i]) > fabs(A[v][i])) v = j;
        }

        if (fabs(A[v][i]) < eps) continue;

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
        if (all_zero && fabs(A[i][n]) > eps) return -1;
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
        for (i = 0; i < n; i++) X[i] = 0;
        for (i = 0; i < rank; i++) {
            int col = basis_col[i];
            if (fabs(A[i][col]) > eps) X[col] = A[i][n] / A[i][col];
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

    for (i = 0; i < n; i++) X[i] = A[i][n] / A[i][i];

    delete[] basis_col;
    delete[] is_basis;
    return 1;
}

int main() {
    ifstream fin("Test.txt");
    ofstream fout("output.txt");

    string line;
    getline(fin, line);
    fin.close();

    float a1, b1, c1, a2, b2, c2;
    size_t commaPos = line.find(',');
    string eq1 = line.substr(0, commaPos);
    string eq2 = line.substr(commaPos + 1);

    parseEquation(eq1, a1, b1, c1);
    parseEquation(eq2, a2, b2, c2);

    float** A = new float* [2];
    float* X = new float[2];

    for (int i = 0; i < 2; i++) A[i] = new float[3];

    A[0][0] = a1; A[0][1] = b1; A[0][2] = c1;
    A[1][0] = a2; A[1][1] = b2; A[1][2] = c2;

    int g = systema(2, 2, A, X);

    if (g == 1) {
        fout << X[0] << " " << X[1] << endl;
    } 
    else if (g == -1) fout << "Inconsistent system" << endl;
    else if (g == 0) fout << "Set of decisions" << endl;

    for (int i = 0; i < 2; i++) delete[] A[i];
    delete[] A;
    delete[] X;

    fout.close();
    return 0;
}