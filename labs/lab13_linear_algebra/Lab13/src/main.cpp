#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <sstream>
using namespace std;

float eps = 1e-9;

bool parseEquation(const string& eq, float& a, float& b, float& c, float& d) {
    string clean = "";
    for (char ch : eq) {
        if (!isspace(ch)) clean += ch;
    }

    size_t eqPos = clean.find('=');
    string left = clean.substr(0, eqPos);
    string right = clean.substr(eqPos + 1);

    d = stof(right);
    a = b = c = 0;
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
        else if (i < left.length() && left[i] == 'z') {
            c += sign * coeff;
            i++;
        }
    }
    return true;
}

int systema(int m, int n, float** A, float* X, int* free_vars, int& free_count) {
    int i, j, k, v;
    float c;

    for (i = 0; i < m && i < n; i++) {
        v = i;
        for (j = i + 1; j < m; j++) {
            if (fabs(A[j][i]) > fabs(A[v][i])) {
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
        if (all_zero && fabs(A[i][n]) > eps) {
            return -1;
        }
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
        free_count = 0;
        for (j = 0; j < n; j++) {
            if (!is_basis[j]) {
                free_vars[free_count++] = j;
            }
        }

        for (i = rank - 1; i >= 0; i--) {
            int col = basis_col[i];
            if (fabs(A[i][col]) < eps) continue;

            for (k = 0; k < i; k++) {
                if (fabs(A[k][col]) < eps) continue;
                c = A[k][col] / A[i][col];
                A[k][n] -= c * A[i][n];
                A[k][col] = 0;
            }
        }

        for (i = 0; i < n; i++) {
            X[i] = 0;
        }

        for (i = 0; i < rank; i++) {
            int col = basis_col[i];
            if (fabs(A[i][col]) > eps) {
                X[col] = A[i][n] / A[i][col];
            }
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

    for (i = 0; i < n; i++) {
        X[i] = A[i][n] / A[i][i];
    }

    delete[] basis_col;
    delete[] is_basis;
    return 1;
}

int main() {
    int i, j, m = 3, n = 3;
    float** A, * X;
    string inputLine;

    ifstream fin("Test.txt");
    ofstream fout("output.txt");

    getline(fin, inputLine);
    fin.close();

    stringstream ss(inputLine);
    string equations[3];

    for (i = 0; i < 3; i++) {
        getline(ss, equations[i], ',');
    }

    float a[3], b[3], c[3], d[3];

    for (i = 0; i < 3; i++) {
        parseEquation(equations[i], a[i], b[i], c[i], d[i]);
    }

    A = new float* [m];
    for (i = 0; i < m; i++) {
        A[i] = new float[n + 1];
        A[i][0] = a[i];
        A[i][1] = b[i];
        A[i][2] = c[i];
        A[i][3] = d[i];
    }

    X = new float[n];
    int* free_vars = new int[n];
    int free_count = 0;

    int g = systema(m, n, A, X, free_vars, free_count);

    if (g == 1) {
        fout << X[0] << " " << X[1] << " " << X[2] << endl;
    }
    else if (g == -1) {
        fout << "Система НЕСОВМЕСТИМА" << endl;
    }
    else if (g == 0) {
        fout << X[0] << " " << X[1] << " " << X[2] << endl;
        if (free_count > 0) {
            fout << "Свободные переменные: ";
            for (i = 0; i < free_count; i++) {
                if (free_vars[i] == 0) fout << "x";
                else if (free_vars[i] == 1) fout << "y";
                else fout << "z";
                if (i < free_count - 1) fout << " ";
            }
            fout << endl;
        }
    }

    fout.close();

    for (i = 0; i < m; i++) {
        delete[] A[i];
    }
    delete[] A;
    delete[] X;
    delete[] free_vars;

    return 0;
}