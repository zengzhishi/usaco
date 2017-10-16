/*
ID: zudaoju1
PROG: namenum
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream dict_fin ("dict.txt");
    
    map<int, string> keypad;
    keypad[2] = "ABC";
    keypad[3] = "DEF";
    keypad[4] = "GHI";
    keypad[5] = "JKL";
    keypad[6] = "MNO";
    keypad[7] = "PRS";
    keypad[8] = "TUV";
    keypad[9] = "WXY";

    string N;
    set<string> dict;
    while (dict_fin >> N) dict.insert(N);
    string a = "aadddd";
    for (int j = 0; j < a.size(); ++j)
        cout << a.substr(j, 1) << " " << j << endl;

    vector<int> candidates;
    candidates.push_back(1);
    candidates.push_back(2);
    candidates.push_back(3);
    candidates.push_back(4);
    candidates.push_back(5);
    candidates.push_back(6);
    candidates.push_back(7);
    vector<int>::iterator it, endit;
    int size_a = 0;

    it = candidates.begin();
    endit = candidates.end();
    size_a = candidates.size();
    candidates.push_back(8);
    candidates.erase(it, endit);
    for (it = candidates.begin(); it != candidates.end(); ++it) {
        cout << *it << endl;
    }

    
    return 0;
}

