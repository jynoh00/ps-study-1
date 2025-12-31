#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;
vector<pair<int, pair<int, int>>> stop_points; // x, (t, s)
int pos = 0;
long long ans_time = 0;

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
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int x, t, s;
        cin >> x >> t >> s;
        stop_points.emplace_back(make_pair(x, make_pair(t, s)));
    }
}

void solve() {
    sort(stop_points.begin(), stop_points.end()); // x 좌표 순서로 정렬
    
    for (int i = 0; i < stop_points.size(); i++) {
        ans_time += stop_points[i].first - pos;
        pos = stop_points[i].first;

        // 아직 신호등 안켜진 경우
        /* 켜지는 시간까지 대기 후 다음 신호등으로 이동 절차 (켜진 직후 초록불이기에 이동 가능) */
        if (stop_points[i].second.second > ans_time) {
            ans_time += stop_points[i].second.second - ans_time;
            
            if ((i + 1) == stop_points.size()) pos = stop_points[i].first; // 마지막 신호등이면 포지션 변경
            continue;
        }

        // 초록 신호등
        long long calcu_time = (ans_time - stop_points[i].second.second) / stop_points[i].second.first;
        
        if (calcu_time % 2 == 0) continue;

        ans_time += stop_points[i].second.first * calcu_time + stop_points[i].second.first + stop_points[i].second.second - ans_time;
    }

    cout << ans_time + (n - pos) << endl;
}

/*
0에서 출발

      x       x
0 1 2 3 4 5 6 7 8 9 10
. . . .
3s에 신호등 위치 도착

첫 신호등 

*/

        /*
        now_time = 3
        12 가능 34 불가능 56 가능 78 불가능 9,10 가능
        t = 2, s = 1

        now_time - 1 = 2

        now_time

        now_time - s 하고 /t했을 때

        t = 2 s = 1
        1, 2 가능
        3, 4 불가능
        5, 6 가능
        7, 8 불가능

        3이면 3-1 /2 = 1
        4이면 4-1 /2 = 1
        5이면 5-1 /2 = 2
        6이면 6-1 /2 = 2
        7이면 7-1 /2 = 3
        8이면 8-1 /2 = 3
        
        짝이면 가능 시간

        t = 5, s = 1

        3이면 5-1 /5 = 0
        4이면 5-1 /5 = 0
        5이면 5-1 /5 = 0
        6이면 6-1 /5 = 1
        7이면 1
        8이면 1
        9이면 1
        10이면 1
        11이면 2
        12이면 2

        짝이면 가능        


        5 3 2
        2 2-2 /3 = 0
        3 3-2 /3 = 0
        4 4-2 /3 = 0
        5 5-2 /3 = 1
        6 6-2 /3 = 1
        7 7-2 /3 = 1
        8 8-2 /3 = 2
        9 9-2 /3 = 2
        10-2 /3 = 2
        11-2 /3 = 3

        => 5, 6, 7이 불가 => 8을 반환하게 해야함 (다음 최소 가능 시간)

        나누어 떨어진다 => + ti
        나누어 떨어지지 않는다 => 

        => 아니 상관없이 ti * calcu_time + si

        "ti * calcu_time + si + ti" 한 결과가 다음 최소 가능 시간

        */

        // 신호등 빨강이면 기다린 후 다음 신호등으로 이동


/*
2 5 4
3 2 1
7 5 1
    x x       x
0 1 2 3 4 5 6 7 8 9 10
    2s
    4s
      5s
      5-1 /2 = 2 이동가능
              9s
              9-1 /5 = 1 이동 불가
              5*1 + 1 = 6 -> 6 + 5 = 11
              11s

                     14

*/