#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void zip(int* arr, int size, int* zarr) {
    int s[18] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17 };
    for (int i = 0; i < 18; i++) {
        int cnt = 0;
        for (int j = 0; j < size; j++) {
            if (s[i] == arr[j]) {
                cnt += 1;
            }
        }
        zarr[i] = cnt;
    }
    
}

void razarchzip(int* arr, int size, int* zarr) {
    int s[18] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17 };
    int index = 0;
    for (int i = 0; i < 18; i++) {
        int cnt=0;
        while (cnt < zarr[i]) {
            arr[index] = s[i];
            index++;
            cnt++;
        }
    }
}

int main() {
    int size;

    cin >> size;

    int* arrstart = new int[size];
    int* arrend = new int[size];
    int* zarr = new int[18];

    for (int i = 0; i < size; i++) {
        arrstart[i] = rand() % (17 + 1);
    }

    cout << endl;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = (size - 1); j > i; j--) 
        {
            if (arrstart[j - 1] > arrstart[j]) 
            {
                int temp = arrstart[j - 1];
                arrstart[j - 1] = arrstart[j];
                arrstart[j] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        cout << arrstart[i] << "  ";
    }

    cout << endl;

    zip(arrstart, size, zarr);


    for (int i = 0; i < 18; i++) {
        cout << zarr[i] << "  ";
    }
    cout << endl;


    razarchzip(arrend, size, zarr);

    cout << endl;

    for (int i = 0; i < size; i++) {
        cout << arrend[i] << "  ";
    }

    cout << endl;

    delete[] arrstart;
    delete[] arrend;
    delete[] zarr;
    return 0;
}
