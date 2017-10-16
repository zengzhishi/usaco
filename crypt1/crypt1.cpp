/*
ID: zudaoju1
PROG: crypt1
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int a = 0, b = 0, c = -1;

bool check_bit(int value, vector<int> &digits) {
    vector<int>::iterator it;
    while (value) {
        it = find(digits.begin(), digits.end(), value % 10);
        if (it == digits.end()) return false;
        value /= 10;
    }
    return true;
}

bool check(int first, int second, vector<int> &digits) {
    int value1 = first * (second % 10),
        value2 = first * (second / 10),
        value3 = first * second;
    if ((check_bit(value1, digits) && 
                check_bit(value2, digits) && 
                check_bit(value3, digits)) &&
                value1 < 1000 && value2 < 1000 && 
                value3 < 10000 && value3 >= 1000)
            return true;
    return false;
}

int get_first(vector<int> &digits, int n) {
    c++;
    if (c == n) {
        b++;
        c = 0;
    }
    if (b == n) {
        a++;
        b = 0;
    }
    if (a == n) return -1;
    return digits[a] * 100 + digits[b] * 10 + digits[c];
}

int main() {
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");

    int n, tmp, first, second, available = 0;
    vector<int> digits;

    fin >> n;
    for (size_t i = 0; i < n; ++i) {
        fin >> tmp;
        digits.push_back(tmp);
    }
    sort(digits.begin(), digits.end());

    first = get_first(digits, n);
    while (first > 0) {
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                second = digits[i] * 10 + digits[j];
                if (check(first, second, digits)) available += 1;
            }
        }
        first = get_first(digits, n);
    }
    fout << available << endl;

    return 0;
}

