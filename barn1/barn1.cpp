/*
ID: zudaoju1
PROG: barn1
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int> &starts, vector<int> &ends, int start, int end) {
    int R = starts[start],
        EndR = ends[start];
    while (start < end) {
        while (start < end && starts[end] >= R) end--;
        if (start < end) {
            starts[start] = starts[end];
            ends[start] = ends[end];
            start++;
        }
        while (start < end && starts[start] <= R) start++;
        if (start < end) {
            starts[end] = starts[start];
            ends[end] = ends[start];
            end--;
        }
    }
    starts[start] = R;
    ends[start] = EndR;
    return start;
}

void pair_quick_sort(vector<int> &starts, 
        vector<int> &ends, 
        int start, int end) {
    if (start < end) {
        int i = partition(starts, ends, start, end);
        pair_quick_sort(starts, ends, start, i - 1);
        pair_quick_sort(starts, ends, i + 1, end);
    }
    
}

void get_interval(vector<int> &cow_stalls, vector<int> &intervals){
    int pre = cow_stalls[0];
    for (vector<int>::iterator it = cow_stalls.begin() + 1;
            it != cow_stalls.end(); ++it) {
        intervals.push_back(*it - pre);
        cout << *it - pre << endl;
        pre = *it;
    }
}

void get_top_n(vector<int> &list, int n, vector<int> &indexs) {
    if (list.size() <= n) return;
    vector<int> tmp_list, tmp_indexs;
    tmp_list.assign(list.begin(), list.end());
    for (size_t i = 0; i < list.size(); ++i) tmp_indexs.push_back(i);
    pair_quick_sort(tmp_list, tmp_indexs, 0, tmp_list.size() - 1);
    indexs.assign(tmp_indexs.end() - n, tmp_indexs.end());
}

int main() {
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");

    int m, s, c, stall_num, course = 0;
    bool is_ordered = true;
    vector<int> cow_stalls, intervals, topn;

    fin >> m >> s >> c;
    fin >> stall_num;
    cow_stalls.push_back(stall_num);
    for (size_t i = 1; i < c; ++i) {
        fin >> stall_num;
        if (stall_num < cow_stalls[i - 1]) is_ordered = false;
        cow_stalls.push_back(stall_num);
    }

    if (!is_ordered) sort(cow_stalls.begin(), cow_stalls.end());
    get_interval(cow_stalls, intervals);
    get_top_n(intervals, m - 1, topn);
    cout << topn.size() << endl;
    if (topn.size() != 0 || m - 1 == 0) {
        for (size_t i = 0; i < topn.size(); ++i) course += intervals[topn[i]];
        course += cow_stalls[0] + (s - cow_stalls[cow_stalls.size() - 1]) - m;
        fout << s - course << endl;
    } else {
        fout << c << endl;
    }

    return 0;
}

