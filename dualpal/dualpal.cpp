/*
ID: zudaoju1
PROG: dualpal
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string tobaseB(int i, int b, bool isreverse) {
    int r;
    string s = "";
    while (i) {
        r = i % b;
        i /= b;
        if (r < 10 && r >= 0) {
            s += (r + '0');
        } else {
            s += (r - 10 + 'A'); 
        }
    }
    if (isreverse) reverse(s.begin(), s.end());
    return s;
}

string strictly_to_baseB(int i, int b, bool isreverse) {
    string s = tobaseB(i, b, isreverse);
    int j = 0;
    while (s[j] == '0') ++j;
    return s.substr(j, s.size() - j);
}

bool isPalindromes(int i, int b) {
    int r;
    string s = strictly_to_baseB(i, b, true);
    r = s.size();
    bool value = true;
    for (size_t j = 0; j < r; ++j) {
        if (j >= r - j - 1)
            break;
        else if (s[j] != s[r - j - 1]) {
            value = false;
            break;
        }
    }
    return value;
}

int main() {
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");

    int n, s;
    fin >> n >> s;
    int i = s + 1,
        out_times = 0,
        palindromic_times;
    while (out_times < n) {
        palindromic_times = 0;
        for (size_t j = 2; j < 11; ++j) {
            if (isPalindromes(i, j)) {
                cout << i << " " << j << " " << tobaseB(i, j, true) << endl;
                ++palindromic_times;
                if (palindromic_times == 2) {
                    fout << i << endl;
                    ++out_times;
                    break;
                }
            }
        }
        ++i;
    }

    return 0;
}
