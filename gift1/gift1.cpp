/*
ID: zudaoju1
PROG: gift1
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");

    int NP,
        value,
        left;
    string name, giver;
    vector<string> names;
    map<std::string,int> groups;

    fin >> NP;
    for (size_t i = 0; i < NP; ++i) {
        fin >> name;
        groups[name] = 0;
        names.push_back(name);
    }

    while (!fin.eof()) {
        fin >> giver;
        if (fin.eof()) break;
        fin >> value >> NP;
        if (NP == 0) continue;
        groups[giver] += (value % NP - value);
        value = value / NP;
        for (size_t i = 0; i < NP; ++i) {
            fin >> name;
            groups[name] += value;
        }
    }

    for (vector<string>::iterator it = names.begin(); it != names.end(); ++it) {
        fout << *it << " " << groups[*it] << endl;
    }

    return 0;
}

