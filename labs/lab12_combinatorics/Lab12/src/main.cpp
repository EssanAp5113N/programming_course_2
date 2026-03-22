#include <iostream>
using namespace std;

int* Q;
int* S;
int* L;
int* R;

int n, ch;


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

	cout << "Всего решений: " << ch << endl;

	delete[] S;
	delete[] Q;
	delete[] R;
	delete[] L;
}
