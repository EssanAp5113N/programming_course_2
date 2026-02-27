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
    return 0;
}

int main() {
    int size;

    cin >> size;

    int* arr = new int[size];
    int* zarr = new int[18];

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (17 + 1);
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i] << "  ";
    }

    cout << endl;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = (size - 1); j > i; j--) 
        {
            if (arr[j - 1] > arr[j]) 
            {
                int temp = arr[j - 1]; 
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i] << "  ";
    }

    cout << endl;

    zip(arr, size, zarr);


    for (int i = 0; i < 18; i++) {
        cout << zarr[i] << "  ";
    }

    razarchzip(arr, size, zarr);

    cout << endl;

    delete[] arr;
    delete[] zarr;
    return 0;
}
