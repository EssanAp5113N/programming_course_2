#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream input("Test.txt");
    ofstream output("result.txt");

    int L[22][22], i, j, n, i0, j0, ik, jk;
    char S[21];

    input >> n;
    input.ignore();

    for (i = 1; i <= n; i++) {
        input.getline(S, 21);
        for (j = 1; j <= n; j++) {
            if (S[j - 1] == '-')
                L[i][j] = 0;
            else
                L[i][j] = 1000;
        }
    }

    for (j = 0; j <= n + 1; j++) {
        L[0][j] = 1000;
        L[n + 1][j] = 1000;
    }

    for (i = 1; i <= n; i++) {
        L[i][0] = 1000;
        L[i][n + 1] = 1000;
    }

    input >> i0 >> j0;
    input >> ik >> jk;

    input.close();


    int Pi[401], Pj[401], r, t;

    Pi[1] = i0;
    Pj[1] = j0;
    r = 1;
    t = 1;
    L[i0][j0] = 1;

    while (t <= r) {
        i = Pi[t];
        j = Pj[t];
        int q = L[i][j] + 1;

        if (L[i - 1][j] == 0) {
            L[i - 1][j] = q;
            r++;
            Pi[r] = i - 1;
            Pj[r] = j;
        }
        if (L[i][j - 1] == 0) {
            L[i][j - 1] = q;
            r++;
            Pi[r] = i;
            Pj[r] = j - 1;
        }
        if (L[i + 1][j] == 0) {
            L[i + 1][j] = q;
            r++;
            Pi[r] = i + 1;
            Pj[r] = j;
        }
        if (L[i][j + 1] == 0) {
            L[i][j + 1] = q;
            r++;
            Pi[r] = i;
            Pj[r] = j + 1;
        }
        if (L[i - 1][j - 1] == 0) {
            L[i - 1][j - 1] = q;
            r++;
            Pi[r] = i - 1;
            Pj[r] = j - 1;
        }
        if (L[i - 1][j + 1] == 0) {
            L[i - 1][j + 1] = q;
            r++;
            Pi[r] = i - 1;
            Pj[r] = j + 1;
        }
        if (L[i + 1][j - 1] == 0) {
            L[i + 1][j - 1] = q;
            r++;
            Pi[r] = i + 1;
            Pj[r] = j - 1;
        }
        if (L[i + 1][j + 1] == 0) {
            L[i + 1][j + 1] = q;
            r++;
            Pi[r] = i + 1;
            Pj[r] = j + 1;
        }

        t++;
    }

    int Mi[401], Mj[401], k;

    char labyrinth[22][22];
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (L[i][j] == 1000)
                labyrinth[i][j] = '#';
            else
                labyrinth[i][j] = '-';
        }
    }

    if (L[ik][jk] >= 1000) {
        output << "Пути не существует!" << endl;
    }
    else {
        k = L[ik][jk];
        i = ik;
        j = jk;

        while (!(i == i0 && j == j0)) {
            labyrinth[i][j] = '*';

            if (L[i - 1][j] == k - 1) {
                i--;
                k--;
            }
            else if (L[i][j - 1] == k - 1) {
                j--;
                k--;
            }
            else if (L[i + 1][j] == k - 1) {
                i++;
                k--;
            }
            else if (L[i][j + 1] == k - 1) {
                j++;
                k--;
            }
            else if (L[i - 1][j - 1] == k - 1) {
                i--;
                j--;
                k--;
            }
            else if (L[i - 1][j + 1] == k - 1) {
                i--;
                j++;
                k--;
            }
            else if (L[i + 1][j - 1] == k - 1) {
                i++;
                j--;
                k--;
            }
            else if (L[i + 1][j + 1] == k - 1) {
                i++;
                j++;
                k--;
            }
        }

        labyrinth[i0][j0] = 's';
        labyrinth[ik][jk] = 'f';

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                output << labyrinth[i][j];
            }
            output << endl;
        }

        output << "\nДлина пути: " << L[ik][jk] - 1 << " шагов" << endl;
    }

    output.close();

    return 0;
}