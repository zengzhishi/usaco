/*
ID: zudaoju1
PROG: palsquare
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

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

bool isPalindromes(int i, int b) {
    int r;
    int i2base10 = i * i;
    string s = tobaseB(i2base10, b, false);
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
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");

    int n;
    fin >> n;
    for (size_t i = 1; i < 300; ++i) {
        if (isPalindromes(i, n)) {
            fout << tobaseB(i, n, true) << " " 
                 << tobaseB(i * i, n, true) << endl;
        }
    }

    return 0;
}
