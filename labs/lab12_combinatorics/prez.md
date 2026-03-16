Here i try to do prezentaions

---
```cpp
#include <iostream>
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

|    Статическая память    |    Диномическая память    |
|    ------------------    |    -------------------    |
|                          |                           |

