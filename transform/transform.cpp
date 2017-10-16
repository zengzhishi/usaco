/*
ID: zudaoju1
PROG: transform
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int **rotation(int **input, int n, int action) {
    int **new_map = new int *[n];
    for (size_t i = 0; i < n; ++i) {
        new_map[i] = new int[n];
        for (size_t j = 0; j < n; ++j) {
            if (action == 1)
                new_map[i][j] = input[n - 1 - j][i];
            else if (action == 2)
                new_map[i][j] = input[n - 1 - i][n - 1 - j];
            else if (action == 3)
                new_map[i][j] = input[j][n - 1 - i];
            else
                new_map[i][j] = input[i][j];
        }
    }
    return new_map;
}

int **reflection(int **input, int n) {
    int **new_map = new int *[n];
    for (size_t i = 0; i < n; ++i) {
        new_map[i] = new int[n];
        for (size_t j = 0; j < n; ++j) {
            new_map[i][j] = input[i][n - 1 - j];
        }
    }
    return new_map;
}

int **transfer(int **input, int n, int action) {
    int **new_map;
    switch (action) {
        case 1: //90 Degree Rotation
            new_map = rotation(input, n, 1);
            break;
        case 2: //180 Degree Rotation
            new_map = rotation(input, n, 2);
            break;
        case 3: //270 Degree Rotation
            new_map = rotation(input, n, 3);
            break;
        case 4: //Reflection
            new_map = reflection(input, n);
            break;
        case 51: //Combination #1
            new_map = reflection(input, n);
            new_map = rotation(new_map, n, 1);
            break;
        case 52: //Combination #2
            new_map = reflection(input, n);
            new_map = rotation(new_map, n, 2);
            break;
        case 53: //Combination #3
            new_map = reflection(input, n);
            new_map = rotation(new_map, n, 3);
            break;
        default: //No change
            new_map = rotation(new_map, n, 0);
            break;
    }
    return new_map;
}

int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");

    int N;
    string line;

    fin >> N;

    int **input = new int *[N],
        **output = new int *[N];

    for (size_t i = 0; i < N; ++i) {
        fin >> line;
        input[i] = new int[N];
        for (size_t j = 0; j < N; ++j) {
            if (line[j] == '@') input[i][j] = 1;
            else input[i][j] = 0;
        }
    }

    for (size_t i = 0; i < N; ++i) {
        fin >> line;
        output[i] = new int[N];
        for (size_t j = 0; j < N; ++j) {
            if (line[j] == '@') output[i][j] = 1;
            else output[i][j] = 0;
        }
    }

    int list[4] = {1, 2, 3, 4},
        list5[3] = {51, 52, 53},
        list6 = 6;

    int action = 0;
    bool status = true;
    //检查前四种
    size_t x;

    for (x = 0; x < 4; ++x) {
        action = list[x];
        int **trans_map = transfer(input, N, action); 
        status = true;
        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < N; ++j) {
                if (output[i][j] != trans_map[i][j]) {
                    status = false;
                    break;
                }
            }
        }
        if (status) break;
    }
    if (status) {
        fout << list[x] << endl;
        return 0;
    }

    status = true;
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < N; ++j) {
            if (output[i][j] != input[i][j]) {
                status = false;
                break;
            }
        }
    }
    if (status) {
        fout << "7" << endl;
        return 0;
    }

    for (x = 0; x < 3; ++x) {
        action = list5[x];
        int **trans_map = transfer(input, N, action); 
        status = true;
        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < N; ++j) {
                if (output[i][j] != trans_map[i][j]) {
                    status = false;
                    break;
                }
            }
        }
        if (status) break;
    }

    if (status) fout << "5" << endl;
    else fout << "7" << endl;

    return 0;
}

