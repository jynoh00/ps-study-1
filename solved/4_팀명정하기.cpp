#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>

#define endl "\n"

using namespace std;

vector<int> years;
vector<pair<int, string>> students;

void input();
void solve();

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    ios_base::sync_with_stdio(false);

    input();
    solve();

    return 0;
}

void input() {
    for (int i = 0; i < 3; i++) {
        int tmp_solved, tmp_year;
        string tmp_name;

        cin >> tmp_solved >> tmp_year >> tmp_name;

        students.emplace_back(make_pair(tmp_solved, tmp_name));
        years.emplace_back(tmp_year);
    }
}

void solve() {
    string outputByYear = "", outputBySolved = "";
    sort(years.begin(), years.end());
    sort(students.rbegin(), students.rend());

    for (int i = 0; i < 3; i++) {
        outputByYear += to_string(years[i]%100);
        outputBySolved += students[i].second[0];
    }

    cout << outputByYear << endl;
    cout << outputBySolved << endl;
}

/*

1. 세 참가자의 입학연도를 100으로 나눈 나머지를 오름차순으로 정렬해서 이어 붙인 문자열
2. 세 참가자의 성씨를 영문으로 표기했을 때 첫 글자를 백준 문제를 많이 푼 사람부터 내림차순 붙인 문자열

600 2018 AHN
2000 2019 LEE
6000 2020 OH

A
L
O

OLA
181920


*/