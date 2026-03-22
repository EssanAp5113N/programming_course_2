#include <iostream>
#include <vector>
using namespace std;

int* Q;
int* S;
int* L;
int* R;


int n, ch;

bool isSafeFullCheck(vector<vector<int>>& board, int K) {
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            if (board[i][j] == 1) {
                for (int c = 0; c < K; c++) {
                    if (c != j && board[i][c] == 1) return false;
                }
                for (int r = 0; r < K; r++) {
                    if (r != i && board[r][j] == 1) return false;
                }
                for (int d = 1; d < K; d++) {
                    if (i + d < K && j + d < K && board[i + d][j + d] == 1) return false;
                    if (i + d < K && j - d >= 0 && board[i + d][j - d] == 1) return false;
                    if (i - d >= 0 && j + d < K && board[i - d][j + d] == 1) return false;
                    if (i - d >= 0 && j - d >= 0 && board[i - d][j - d] == 1) return false;
                }
            }
        }
    }
    return true;
}

void generateAllConfigurations(vector<vector<int>>& board, int row, int K, int& count) {
    if (row == K) {
        if (isSafeFullCheck(board, K)) {
            count++;
            cout << "Var " << count << ":\n";
            for (int i = 0; i < K; i++) {
                for (int j = 0; j < K; j++) {
                    if (board[i][j] == 1)
                        cout << "Q ";
                    else
                        cout << ". ";
                }
                cout << endl;
            }
            cout << endl;
        }
        return;
    }

    for (int col = 0; col < K; col++) {
        board[row][col] = 1;
        generateAllConfigurations(board, row + 1, K, count);
        board[row][col] = 0;
    }
}

void Met(int K) {
    vector<vector<int>> board(K, vector<int>(K, 0));
    int count = 0;
    generateAllConfigurations(board, 0, K, count);
    cout << count << "\n";
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
	Met(n);

	cout << "Всего решений: " << ch << endl;


	delete[] S;
	delete[] Q;
	delete[] R;
	delete[] L;
}
