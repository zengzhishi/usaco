/*
ID: zudaoju1
PROG: milk
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int NEED = 100,
    MAX = 1001;

int find_max_unit(vector<int> &list1, vector<int> &list2) {

    int min_cent_index = -1,
        min_cent = MAX,
        value;
    for (size_t i = 0; i < list1.size(); ++i) {
        value = list1[i];
        if (min_cent > value) {
            min_cent = value;
            min_cent_index = i;
        }
    }

    return min_cent_index;
}

int main() {
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");

    int n,
        farmer_num,
        cent,
        avaliable;
    vector<int> cents,
                avaliables;

    fin >> n;
    fin >> farmer_num;
    for (size_t i = 0; i < farmer_num; ++i) {
        fin >> cent >> avaliable;
        cents.push_back(cent);
        avaliables.push_back(avaliable);
    }

    int course = 0,
        min_index;
    for (size_t i = 0; i < farmer_num; ++i) {
        min_index = find_max_unit(cents, avaliables);
        cent = cents[min_index];
        avaliable = avaliables[min_index];
        if (n > avaliable) {
            course += avaliable * cent;
        } else {
            course += n * cent;
            break;
        }
        n -= avaliable;
        cents.erase(cents.begin() + min_index);
        avaliables.erase(avaliables.begin() + min_index);
    }
    fout << course << endl;
    
    return 0;
}

