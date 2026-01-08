#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

#define endl "\n"

using namespace std;

int N, M;
vector<int> abilities;

void input();
int solve();

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
    
    int ability;
    for (int i = 0; i < N; i++) {
        cin >> ability;
        abilities.emplace_back(ability);
    }
}

int solve() {
    sort(abilities.begin(), abilities.end()); // 오름차순
    
    int cnt = 0;
    int left = 0, right = N-1;

    while (left < right) {
        if (abilities[left] + abilities[right] >= M) {
            cnt++;
            left++;
            right--;            
            
            continue;
        }

        left++;
    }

    return cnt;
}

/*
만족하는 팀만 견학 가능

1. 팀원이 두명
2. 팀의 능력치가 M 이상, 모든 팀원의 능력치 합

N명이 견학 신청

N명으로 최대한 많은 팀을 견학 보내고 싶음.

최대 몇 팀이 가능할까

10
3 5 7 3 5 6

x   x x   x
3 3 5 5 6 7

3 7 o
3 6 x
5 6 o
5 5 -


0 1
0,1
0,2
0,3
0,4
0,5
0,6 => 가능 => 1,2

1 2
...


2 3

*/