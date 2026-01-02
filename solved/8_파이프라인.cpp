#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

#define endl "\n"

using namespace std;

int N;
vector<int> s;
int work_time = 0;

void input();
void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();

    return 0;
}

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int si;
        cin >> si;
        s.emplace_back(si);
    }
}

void solve() {
    sort(s.rbegin(), s.rend());

    work_time += N-1 + s[0];
    
    cout << work_time << endl;
}

/*
작업 슬롯 1개

N개의 자동차 생산 공정 계획
i번째 자동차는 생산을 위해 si 단계의 프로세스 필요

작업 슬롯 수직선상 [0,1)
i번째 자동차 생산 중이면 1/si 크기의 반열린 구간

0초부터 1초마다 다음 순서대로 반복
 할당된 생산 프로세스부터, 모든 생산 프로세스가 크기만큼 뒤로 움직임

할당 x 생산 프로세스 중 하나 골라 할당 or 할당x 선택 가능

i번째 생산 프로세스를 할당할 경우 슬롯의 [0, 1/si) 부분에 할당 (앞에 할당)
단 겹치는 경우 할당 불가

모든 자동차가 작업 슬롯을 거쳐, 생산될 때까지 걸리느 최소 시간 몇 초

자동차 개수 N

4
5 7 8 11

1/5, 1/7, 1/8, 1/11

0이상 1/5미만

0~1초) 1/5 넣고
1~2초) 1/5 움직임 (2/5 ~ 3/5) -> 1/7 넣고
2~3초) 움직임(두개) 1/8 넣고
3~4초) 움직임(세개) 1/11 넣고
4~5초) 움직임(네개)

하나를 고를 수 있음 즉 순서 x

생산 프로세스가 가장 작은 수 부터 (s가)
-> 1/s가 가장 큼 -> 이후 움직인 후에 생산 슬롯에 매 턴 삽입 가능

차피 매초마다 전부 넣음
-> 전부 넣는데 걸리는 시간 N초

가장 마지막 프로세스 크기보고 [0,1) 벗어나는 순간까지 걸리는 시간 계산

=> 
ans += N-1 // 전부 프로세스에 넣기까지 시간
sort() // 내림차순
ans += s[0] // 마지막 자동차 생산까지 걸리는 시간
*/

