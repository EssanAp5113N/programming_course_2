Призентация
---
До начала работы

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

---
Вход в main(), инициализация,  per(0) - начало цикла

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
    
    per(0);                  <-----

    return 0;
}
```

|    Статическая память    |    Диномическая память    |
|    ------------------    |    -------------------    |
|   P: [?, ?, ?]        |                           |
|   R: [0, 0, 0]          |                           |

---

per(0) - проверка R[0] == 0

```cpp
#include <iostream>
using namespace std;

const int n = 3;
int P[n]; 
int R[n];

void per(int k) {
    for (int i = 0; i < n; i++) {
        if (R[i] == 0) {         
            P[k] = i + 1;        |     <-----
            R[i] = 1;            |     <-----
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
|   P: [1, ?, ?]        |           i: 0  ( per(0) )          |
|   R: [1, 0, 0]          |           k: 0  ( per(0) )             |

---
 per(0) - вызов per(1)

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
                per(k + 1);    <-----
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
|   P: [1, ?, ?]        |           i: 0  ( per(0) )            |
|   R: [1, 0, 0]          |           k: 0  ( per(0) )             |

---
per(1) - проверка R[0] == 0, проверка R[1] == 0

```cpp
#include <iostream>
using namespace std;

const int n = 3;
int P[n]; 
int R[n];

void per(int k) {
    for (int i = 0; i < n; i++) {
        if (R[i] == 0) {         
            P[k] = i + 1;            |     <-----        
            R[i] = 1;                |     <-----            
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
|   P: [1, 2, ?]        |           i: 0  -> i: 1 [R[0] != 0] ( per(1) )     |
|   R: [1, 1, 0]          |           k: 1  ( per(1) )             |
|                       |           i: 0  ( per(0) )            |
|                        |           k: 0  ( per(0) )             |

---
per(1) - вызов per(2)

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
                per(k + 1);    <------
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
|   P: [1, 2, ?]        |            i: 1  ( per(1) )     |
|   R: [1, 1, 0]          |           k: 1  ( per(1) )             |
|                       |           i: 0  ( per(0) )            |
|                        |           k: 0  ( per(0) )             |

---
 per(2) - проверка R[0] == 0, проверка R[1] == 0,  проверка R[2] == 0

```cpp
#include <iostream>
using namespace std;

const int n = 3;
int P[n]; 
int R[n];

void per(int k) {
    for (int i = 0; i < n; i++) {
        if (R[i] == 0) {         
            P[k] = i + 1;           |     <-----                 
            R[i] = 1;               |     <-----                
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
|   P: [1, 2, 3]           |           i: 0 ->  [R[0] != 0] [R[1] != 0] -> i: 2   ( per(2) )            |
|   R: [1, 1, 1]           |           k: 2  ( per(2) )             |
|                          |            i: 1  ( per(1) )     |
|                         |           k: 1  ( per(1) )             |
|                           |           i: 0  ( per(0) )            |
|                        |           k: 0  ( per(0) )             |

---
 per(2) - проверка k == n-1, ВЫВОД перестановки "1 2 3"

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
                for (int j = 0; j < n; j++) {       |     <-----      
                    cout << P[j] << " ";            |     <-----      
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
|   P: [1, 2, 3]           |            i: 2   ( per(2) )            |
|   R: [1, 1, 1]           |           k: 2  ( per(2) )             |
|                          |            i: 1  ( per(1) )     |
|                         |           k: 1  ( per(1) )             |
|                           |           i: 0  ( per(0) )            |
|                        |           k: 0  ( per(0) )             |
