/*
 * ID: zudaoju1
 * PROG: ride
 * LANG: C++
 *
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#define START_INDEX 65

using namespace std;

int getIndex(char ch) {
    return (int)ch - START_INDEX + 1;
} 

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");

    int firstValue;
    int output;
    string str;
    char ch;
    int ch_index;

    for (size_t j = 0; j < 2; ++j) {
        getline(fin, str);
        output = 1;
        for (size_t i = 0; i < str.size(); ++i) {
            ch = str[i];
            ch_index = getIndex(ch);
            output *= ch_index;
        }
        output %= 47;
        if (j == 0) firstValue = output;
        else fout << ((output == firstValue) ? "GO" : "STAY") << endl;
    }

    fin.close();
    fout.close();

    return 0;
}


