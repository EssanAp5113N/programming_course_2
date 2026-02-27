#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    // Упражнения 1: Три функции

    string str = "Hello world!";

    cout << str.length() << endl;

    cout << str.find("!") << endl;

    cout << str.empty() << endl;

    cout << "---------" << endl;

    // Упражнение 4: ввод количества слов и самих слов.

    int word_count = 0;

    cin >> word_count;

    if (word_count > 20 || word_count < 0) {
        return 0;
    }

    // С помощью vector

    vector<string> line(word_count);

    for (int i = 0; i < word_count; i++) {
        string l;
        cin >> l;
        line[i] = l;
    }

    cout << "---------" << endl;

    for (int i = 1; i < word_count;) {
        cout << line[i] << endl;
        i += 2;
    }

    return 0;
}
