/*
ID: zudaoju1
PROG: friday
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

bool isleapYear(int years) {
    if (years % 100 != 0) {
        return not (years % 4);
    } else {
        return not (years % 400);
    }
}

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int N, year, monthdays;
    const int start_year = 1900;

    map<int, int> month2Days;
    month2Days[1] = 31;
    month2Days[2] = 28;
    month2Days[3] = 31;
    month2Days[4] = 30;
    month2Days[5] = 31;
    month2Days[6] = 30;
    month2Days[7] = 31;
    month2Days[8] = 31;
    month2Days[9] = 30;
    month2Days[10] = 31;
    month2Days[11] = 30;
    month2Days[12] = 31;

    map<int, int> weektimes;
    for (size_t i = 0; i < 7; ++i) {
        weektimes[i] = 0;
    }

    int start_day_for_week = 0;
    int index13th;
    fin >> N;
    for (size_t i = 0; i < N; ++i) {
        year = start_year + i;
        for (size_t j = 1; j <= 12; ++j) {
            start_day_for_week++;
            start_day_for_week %= 7;
            monthdays = month2Days[j];
            if (j == 2 && isleapYear(year)) {
                monthdays += 1;
            }
            index13th = (start_day_for_week + 13 - 1) % 7;
            weektimes[index13th] += 1;
            start_day_for_week = (monthdays + start_day_for_week - 1) % 7;
        }
    }

    fout << weektimes[6];
    for (size_t i = 0; i < 6; ++i) {
        fout <<  " " << weektimes[i];
    }
    fout << endl;
    return 0;
}

