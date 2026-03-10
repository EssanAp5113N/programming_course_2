#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <string.h>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Упражнение 1
    //int x;
    //char str[80];
    //cin >> x;
    //cout << x << endl;

    //scanf_s("%d", &x);
    //printf("%d", x);

    //cout << endl;

    //FILE* f = fopen("t.txt", "w");
    //fprintf(f, "%s", "test text");
    //fclose(f);

    // gets puts - усторевшее не безопастное (построчное чтение из файла)
    // EOF - обозначает конец файла

    // Упражнение 2

    int word_count = 0;
    FILE* file1 = fopen("File1.txt", "w");
    FILE* file2 = fopen("File2.txt", "w");
    ifstream test("test1.txt");

    vector<string> line;

    if (test.is_open()) {
        string word;
        while (getline(test, word)) {
            line.push_back(word);
        }
        test.close();
    }


    word_count = line.size();
    vector<vector<string>> list(line.size());
    

    for (int i = 0; i < word_count; i++) {
        list[i].push_back(line[i]);
        for (int j = 0; j < word_count; j++) {
            string sub = line[j].substr(0, line[i].length());
            if (line[i] == sub && i != j) {
                list[i].push_back(line[j]);
            }
        }
    }

    int id_maxcnt = 0;
    int max_cnt = 0;

    for (int i = 0; i < word_count; i++) {
        if (max_cnt < list[i].size()) {
            max_cnt = list[i].size();
            id_maxcnt = i;
        }
    }

    int id_maxlen = 0;
    int maxlen = 0;
    
    for (int i = 0; i < word_count; i++) {
        if (list[i].size() > 1 && list[i][0].length() > maxlen) {
            id_maxlen = i;
            maxlen = list[i][0].length();
        }
    }

    if (max_cnt - 1 == 0) {
        cout << "NO" << endl;
        fprintf(file1, "%s", "NO");
        fprintf(file2, "%s", "NO");
        return 0; 
    };

    cout << endl;
    for (int i = 0; i < list[id_maxlen].size(); i++) {
        cout << list[id_maxlen][i] << " ";
    }

    cout << endl;
    cout << line[id_maxcnt] << " ";
    cout << max_cnt - 1;

   

    

    for (int i = 0; i < list[id_maxlen].size(); i++) {
        fprintf(file1, "%s", list[id_maxlen][i].c_str());
        fprintf(file1, "%s", " ");
    }

    fclose(file1);


    fprintf(file2, "%s", line[id_maxcnt].c_str());
    fprintf(file2, "%s", " ");
    fprintf(file2, "%d", max_cnt - 1);

    fclose(file2);

    return 0;
}
