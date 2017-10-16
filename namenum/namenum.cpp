/*
ID: zudaoju1
PROG: namenum
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream dict_fin ("dict.txt");
    
    map<char, string> keypad;
    keypad['2'] = "ABC";
    keypad['3'] = "DEF";
    keypad['4'] = "GHI";
    keypad['5'] = "JKL";
    keypad['6'] = "MNO";
    keypad['7'] = "PRS";
    keypad['8'] = "TUV";
    keypad['9'] = "WXY";

    string N;
    unordered_set<string> dict, subset;
    unordered_set<string>::const_iterator got;
    while (dict_fin >> N) {
        dict.insert(N);
        if (N.size() > 6) {
            subset.insert(N.substr(0, 6));
        }
    }

    vector<string> candidates, backup;
    vector<string>::iterator it, startit, endit;
    string s, candidate;
    fin >> N;
    int len = N.size();
    for (size_t i = 0; i < N.size(); ++i) {
        s = keypad[N[i]];
        it = candidates.begin();
        endit = candidates.end();
        if (candidates.size() == 0) {
            for (size_t j = 0; j < 3; ++j) 
                candidates.push_back(s.substr(j, 1));
            continue;
        }
        backup.clear();
        for (; it != endit; ++it) {
            candidate = *it;
            for (size_t j = 0; j < 3; ++j) {
                if (len > 6 && (*it).size() == 6) {
                    got = subset.find(*it);
                    if (got == subset.end()) break;
                }
                backup.push_back(*it + s[j]);
            }
        }
        //vector 拷贝
        candidates.clear();
        candidates.assign(backup.begin(), backup.end());
        cout << candidates.size() << endl;
    }

    sort(candidates.begin(), candidates.end());
    N = "";
    for (it = candidates.begin(); it != candidates.end(); ++it) {
        got = dict.find(*it);
        if (got != dict.end()) {
            N += *it;
            N += "\n";
        }
    }
    if (N.size() == 0)
        fout << "NONE" << endl;
    else
        fout << N.substr(0, N.size() - 1) << endl;

    return 0;
}

