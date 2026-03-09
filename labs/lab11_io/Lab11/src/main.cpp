#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
    // Упражнение 1
    int x;
    char str[80];
    cin >> x;
    cout << x << endl;

    scanf_s("%d", &x);
    printf("%d", x);

    // gets puts - усторевшее не безопастное
    // fopen fclose - для работы с файлами
    // fscanf fprintf - для работы с файлами
    // EOF - обозначает конец файла

    // Упражнение 2

    return 0;
}
