/*
ID: zudaoju1
PROG: combo
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void get_limits(int value, vector<int> &limits) {

    int a, b, c;

    for (size_t i = -2; i <= 2; ++i) {

        for (size_t j = -2; j <= 2; ++j) {
            
            for (size_t k = -2; k <= 2; ++k) {

                c = value % 10;
                a = value / 100;
                b = (value / 10) % 10;

            }
        }

    }
    
}

int main() {
    ofstream fout ("combo.out");
    ifstream fin ("combo.in");

    int n,
        a1, a2, a3,
        b1, b2, b3;

    fin >> n;
    fin >> a1 >> a2 >> a3;
    fin >> b1 >> b2 >> b3;

    return 0;
}

