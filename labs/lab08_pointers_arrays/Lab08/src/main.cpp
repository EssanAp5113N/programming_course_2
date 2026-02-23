#include <iostream>
#include <cstdlib> 

using namespace std;

struct List {
    int data;     
    List *prev;   
    List *next;   
};

void merge(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            result[k] = arr1[i];
            i++;
        }
        else {
            result[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < size1) {
        result[k] = arr1[i];
        i++;
        k++;
    }

    while (j < size2) {
        result[k] = arr2[j];
        j++;
        k++;
    }
}


int main() {
    setlocale(LC_ALL, "Russian");
    // Задание 3
    // 1)
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

    //int size = 10;
    //int *arrD1 = new int[size];

    //for (int i = 0; i < size; i++) {
    //    arrD1[i] = i * i;
    //}

    //for (int i = 0; i < size; i++) {
    //    cout << arrD1[i] << endl;
    //}

    //delete[] arrD1;

    // -----------------------------

    //int *arrD2 = new int[size];
    //int *p;
    //p = arrD2;

    //for (int i = 0; i < size; i++) {
    //    *(p + i) = i * i;
    //}

    //for (int i = 0; i < size; i++) {
    //    cout << *(p + i) << endl;
    //}

    //delete[] arrD2;

    // 2)

    //int arrX[] = { 1, 3, 5, 7, 9 };
    //int sizeX = 5;

    //int arrY[] = { 2, 4, 6, 8, 10 };
    //int sizeY = 5;

    //int* result = new int[sizeX + sizeY];

    //merge(arrX, sizeX, arrY, sizeY, result);

    //for (int i = 0; i < sizeX + sizeY; i++) {
    //    cout << result[i] << " ";
    //}

    //delete[] result;


    // Упражнение 4
    
    List *head = new List;
    head->data = 1;
    head->prev = nullptr;
    head->next = nullptr;

    List *current = head;

    for (int i = 2; i <= 10; i++) {
        List *newList = new List;
        newList->data = i;
        newList->prev = current;
        newList->next = nullptr;

        current->next = newList;
        current = newList;
    }

    current = head;
    while (current != nullptr) {
        cout << "Item " << current->data << endl;
        cout << "  Ip: " << current << endl;
        cout << "  prev: " << current->prev << endl;
        cout << "  next: " << current->next << endl << endl;
        current = current->next;
    }

    current = head;
    List *next;
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
}
