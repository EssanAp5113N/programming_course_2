Here i try to do prezentaions

---

```cpp
#include <iostream>                         |Столбец 1|Столбец 2|Столбец 3|
                                            |-|--------|---|
                                            |Длинная запись в первом столбце|Запись в столбце 2|Запись в столбце 3|
                                            |Кртк зпс| |Слева нет записи|
using namespace std;

const int n = 3;
int P[n]; 
int R[n];

void per(int k) {
    for (int i = 0; i < n; i++) {
        if (R[i] == 0) {
            P[k] = i + 1;
            R[i] = 1;
            if (k == n - 1) {
                for (int j = 0; j < n; j++) {
                    cout << P[j] << " ";
                }
                cout << endl;
            }
            else {
                per(k + 1);
            }
            R[i] = 0;
        }
    }
}

int main() {
    for (int i = 0; i < n; i++) {
        R[i] = 0;
    }
    
    per(0);

    return 0;
}
```
