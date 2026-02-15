#include <iostream>
using namespace std;

int main() {
    // Статический массив

    //int arrS1[10];

    //for (int i = 0; i < 10; i++) {
    //    arrS1[i] = i * i;
    //}

    //for (int i = 0; i < 10; i++) {
    //    cout << arrS1[i] << endl;
    //}

    // -----------------------------

    //int arrS2[10];

    //int *pArr = arrS2;

    //for (int i = 0; i < 10; i++) {
    //    *(pArr + i) = i * i;
    //}

    //for (int i = 0; i < 10; i++) {
    //    cout << *(pArr + i) << endl;
    //}

    // Динамический массив

    int size = 10;
    //int *arrD1 = new int[size];

    //for (int i = 0; i < size; i++) {
    //    arrD1[i] = i * i;
    //}

    //for (int i = 0; i < size; i++) {
    //    cout << arrD1[i] << endl;
    //}

    //delete[] arrD1;

    // -----------------------------

    int *arrD2 = new int[size];
    int *p;
    p = arrD2;

    for (int i = 0; i < size; i++) {
        *(p + i) = i * i;
    }

    for (int i = 0; i < size; i++) {
        cout << *(p + i) << endl;
    }

    delete[] arrD2;

    // Упражнение 4: линейный самоадресуемый список из 10 элементов.
    // TODO: сформируйте список и выведите элементы по порядку.
    return 0;
}
