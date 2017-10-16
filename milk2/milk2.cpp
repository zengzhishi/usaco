/*
ID: zudaoju1
PROG: milk2
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

int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");

    int N;
    int start, end;
    vector<int> starts;
    vector<int> ends;

    fin >> N;
    for (int i = 0; i < N; ++i) {
        fin >> start >> end;
        starts.push_back(start);
        ends.push_back(end);
    }
    pair_quick_sort(starts, ends, 0, N - 1);

    vector<int> work_times;
    vector<int> wait_times;
    start = starts[0];
    end = ends[0];
    int index = 1;
    if (N == 1) work_times.push_back(end - start);
    while (index < N) {
        if (starts[index] > end) {
            work_times.push_back(end - start);
            wait_times.push_back(starts[index] - end);
            start = starts[index];
            end = ends[index];
        } else {
            if (ends[index] > end) end = ends[index];
            if (starts[index] < start) start = starts[index];
        }
        work_times.push_back(ends[index] - starts[index]);
        ++index;
    }
    work_times.push_back(end - start);

    int maxWork = 0,
        maxWait = 0;
    if (work_times.size() != 0) {
        vector<int>::iterator maxWorkPosition = max_element(work_times.begin(), 
                work_times.end());
        maxWork = *maxWorkPosition;
    }
    if (wait_times.size() != 0) {
        vector<int>::iterator maxWaitPosition = max_element(wait_times.begin(), 
                wait_times.end());
        maxWait = *maxWaitPosition;
    }
    fout << maxWork << " " << maxWait << endl;
    return 0;
}

