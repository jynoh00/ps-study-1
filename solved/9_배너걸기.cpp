#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <string>
#include <map>

#define endl "\n"
#define CAN "YES"
#define CANT "NO"

using namespace std;

int N, M;
vector<int> A;
int needSameNumberCnt;

void input();
string solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    cout << solve() << endl;

    return 0;
}

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int Ai; cin >> Ai;
        A.emplace_back(Ai);
    }
}

string solve() {
    needSameNumberCnt = ceil(9.0 * M / 10);

    int casesNumber = (N - M) + 1;
    map<int, int> m;

    int left = 0, right = M - 1;
    for (int i = left; i <= right; i++) { // O(M) => O(N)
        m[A[i]]++;
        if (m[A[i]] >= needSameNumberCnt) return CAN;
    }

    for (int i = 1; i < casesNumber; i++) { // O(N-M) => O(N)
        m[A[left]]--;
        m[A[right+i]]++;
        if (m[A[right+i]] >= needSameNumberCnt) return CAN;
        left++;
    }

    return CANT;
}

/*
MMS <- 센서 활용, 도로 및 주변 지형 정보

지도 보유 => 한 도로에서 찍은 물체 정보들이 담겨 있음

- N개의 구간으로 나뉨, 각 구간마다 물체가 1개씩 존재
- Ai는 i번째 구간에 있는 물체가 지면으로부터 떨어져있는 거리

아래 조건에 맞게 배너를 걸려함

1. 배너는 N개의 구간 중, 연속된 M개에 설치
2. 연속된 M개의 구간 중, [9*M/10] 개 이상의 Ai 값이 하나의 값으로 같아야 함

[] => 정수 올림 // cmath

걸 수 있는 지 확인

12 11

5 4 4 4 4 4 4 5 4 4 4 4

5 4 4 4 4 4 4 5 4 4 4
  4 4 4 4 4 4 5 4 4 4 4

[9*11 / 10] = 10 // 9.9 -> 올림


12 11 -> 1 + 1 = 2개

13 11 -> 2 + 1 => 3개

x x x x x x x x x x x x x


좌표 숫자

슬라이딩 윈도우
O(N) * O(logN) => O(NlogN)

logN <- map => unordered_map -> O(1)
=> O(N)으로 성능 향상 가능
*/