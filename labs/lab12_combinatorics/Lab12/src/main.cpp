#include <iostream>
#include <vector>
using namespace std;

int* Q;
int* S;
int* L;
int* R;


int n, ch;

int solutionsCount = 0;

void placeQueens(vector<vector<int>>& board, int row, int K) {
    if (row == K) {
        solutionsCount++;
        cout << "Var " << solutionsCount << ":\n";
        for (int i = 0; i < K; ++i) {
            for (int j = 0; j < K; ++j) {
                if (board[i][j] == -1)
                    cout << "Q ";
                else
                    cout << ". ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int col = 0; col < K; ++col) {
        if (board[row][col] == 0) {
            board[row][col] = -1;

            for (int j = 0; j < K; ++j) {
                if (j != col)
                    board[row][j] += 1;
            }

            for (int i = 0; i < K; ++i) {
                if (i != row)
                    board[i][col] += 1;
            }

            for (int i = 1; i < K; ++i) {
                if (row + i < K && col + i < K)
                    board[row + i][col + i] += 1;
                if (row - i >= 0 && col - i >= 0)
                    board[row - i][col - i] += 1;
            }

            for (int i = 1; i < K; ++i) {
                if (row + i < K && col - i >= 0)
                    board[row + i][col - i] += 1;
                if (row - i >= 0 && col + i < K)
                    board[row - i][col + i] += 1;
            }

            placeQueens(board, row + 1, K);

            board[row][col] = 0;

            for (int j = 0; j < K; ++j) {
                if (j != col)
                    board[row][j] -= 1;
            }

            for (int i = 0; i < K; ++i) {
                if (i != row)
                    board[i][col] -= 1;
            }

            for (int i = 1; i < K; ++i) {
                if (row + i < K && col + i < K)
                    board[row + i][col + i] -= 1;
                if (row - i >= 0 && col - i >= 0)
                    board[row - i][col - i] -= 1;
            }

            for (int i = 1; i < K; ++i) {
                if (row + i < K && col - i >= 0)
                    board[row + i][col - i] -= 1;
                if (row - i >= 0 && col + i < K)
                    board[row - i][col + i] -= 1;
            }
        }
    }
}

void Queen(int j) {
	for (int i = 0; i < n; i++) {
		if (S[i] == 0 && R[j - i + n - 1] == 0 && L[j + i] == 0) {
			S[i] = 1;
			R[j - i + n - 1] = 1;
			L[j + i] = 1;
			Q[j] = i;
			if (j == n - 1) {
				ch++;
				for (int k = 0; k < n; k++) {
					cout << Q[k] + 1 << " ";
				}
				cout << endl;
			}
			else {
				Queen(j + 1);
			}
			S[i] = 0;
			R[j - i + n - 1] = 0;
			L[j + i] = 0;
		}
	}
}


void main() {
	cin >> n;


	S = new int[n];
	Q = new int[n];
	R = new int[2 * n - 1];
	L = new int[2 * n - 1];

    vector<vector<int>> board(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		S[i] = 0;
	}

	for (int i = 0; i < 2 * n - 1; i++) {
		R[i] = 0;
	}

	for (int i = 0; i < 2 * n - 1; i++) {
		L[i] = 0;
	}


	ch = 0;
	Queen(0);
    placeQueens(board, 0, n);

	cout << "Colich: " << ch << endl;


	delete[] S;
	delete[] Q;
	delete[] R;
	delete[] L;
}
