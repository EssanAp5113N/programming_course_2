#include <iostream>
using namespace std;

int main() {
    // Статический массив

    int arrS1[10];

    for (int i = 0; i < 10; i++) {
        arrS1[i] = i * i;
    }

    for (int i = 0; i < 10; i++) {
        cout << arrS1[i] << endl;
    }

    // -----------------------------

    // Упражнение 4: линейный самоадресуемый список из 10 элементов.
    // TODO: сформируйте список и выведите элементы по порядку.
    return 0;
}
