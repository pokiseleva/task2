#include <bits/stdc++.h>
using namespace std;
void merge(char *filename);

void split(char* filename) {
    ifstream fin(filename);
    ofstream fout_0("task2_temp0.txt");
    ofstream fout_1("task2_temp1.txt");

    int file = 0;
    string s1, s2;
    getline(fin, s1);
    getline(fin, s2);
    fout_0 << s1 << endl;
    while (!fin.eof()) {
        if (s1 <= s2) {
            if (file) fout_1 << s2 << endl;
            else fout_0 << s2 << endl;
        } else {
            if (file) {
                fout_0 << s2 << endl;
            } else {
                fout_1 << s2 << endl;
            }
            file = (file + 1) % 2;
        }
        s1 = s2;
        getline(fin, s2);
    }
    fin.close();
    fout_0.close();
    fout_1.close();
    merge(filename);
}

void merge(char* filename) {
    ifstream fin_0("task2_temp0.txt");
    ifstream fin_1("task2_temp1.txt");
    ofstream fout(filename);

    string s2, s1, lastString = "";
    int file = 0;
    getline(fin_0, s1);
    getline(fin_1, s2);
    if (fin_1.eof()){
        while (!fin_0.eof()) {
            fout << s1 << endl;
            getline(fin_0, s1);
        }
    } else {
        while (!fin_0.eof() && !fin_1.eof()) {
            if (s1 <= s2) {
                if (lastString <= s1) {
                    fout << s1 << endl;
                    file = 0;
                    lastString = s1;
                    getline(fin_0, s1);
                } else {
                    while (lastString <= s2) {
                        fout << s2 << endl;
                        lastString = s2;
                        getline(fin_1, s2);
                    }
                    lastString = "";
                }
            } else {
                if (lastString <= s2) {
                    fout << s2 << endl;
                    file = 1;
                    lastString = s2;
                    getline(fin_1, s2);
                } else {
                    while (lastString <= s1) {
                        fout << s1 << endl;
                        lastString = s1;
                        getline(fin_0, s1);
                    }
                    lastString = "";
                }
            }
        }
        while (!fin_0.eof()) {
            fout << s1 << endl;
            getline(fin_0, s1);
        }

        while (!fin_1.eof()) {
            fout << s2 << endl;
            getline(fin_1, s2);
        }


        split(filename);
    }
}


int main() {
    char name[40];
    setlocale(0, "Russian");
    cout<<"Vvedite nazvanie faila(file.txt):";
    cin.getline(name,40);
    setlocale(0, "Russian");
    split(name);


    return 0;
}
