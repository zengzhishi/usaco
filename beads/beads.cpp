/*
ID: zudaoju1
PROG: beads
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> get_diff_str(string input) {
    vector<string> slices;
    vector<int> sumups;
    if (input.size() == 0) return sumups;
    int index = 0;
    string slice;
    slice = input[index];
    char mark = input[index];
    int reverse = 0, tmp, first_out_reverse;
    bool issecond_reverse = false;
    while (index < input.size() - 1 &&
            !issecond_reverse &&
            slice.size() < input.size() / 2) {
        ++index;
        if (mark == 'w') {
            slice += input[index];
            mark = input[index];
            continue;
        } else if (input[index] == mark || input[index] == 'w') {
            slice += input[index];
            continue;
        } else {
            if (reverse != 0) {
                slices.push_back(slice);

                int tmp_reverse = reverse;
                while (input[tmp_reverse - 1] == 'w') --tmp_reverse;
                slice = input.substr(tmp_reverse, index - tmp_reverse);
                if (reverse > input.size() / 2) {
                    if (first_out_reverse == 0) 
                        first_out_reverse = reverse;
                    if (reverse != first_out_reverse)
                        issecond_reverse = true;
                }
            }
            slice += input[index];
            reverse = index;
            mark = input[index];
        }
        /* 
        cout << slice << endl;
        cout << input[index] << "\t" << index 
            << "\t" << reverse << "\t" << mark << endl;
        */
    }
    if (slices.size() == 0) slices.push_back(slice);
    for (vector<string>::iterator it = slices.begin(); it != slices.end(); ++it) {
        cout << *it << endl;
        sumups.push_back((*it).size());
    }
    return sumups;
}

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");

    int N;
    string beads_string;

    fin >> N;
    if (N < 3 || N > 350) return -1;

    fin >> beads_string;
    int len = beads_string.size();

    char *beads_chars = new char [beads_string.length() * 2 + 1];
    string double_beads_string = beads_string + beads_string;

    vector<int> sumups = get_diff_str(double_beads_string);
    if (sumups.size() == 1) {
        fout << beads_string.size() << endl;
        return 0;
    }

    vector<int>::iterator maxPosition = max_element(sumups.begin(), sumups.end());
    fout << *maxPosition << endl;

    return 0;
}

