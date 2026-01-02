#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

#define endl "\n"

using namespace std;

int N, K;
long long ans = -1;
vector<vector<int>> lectures;

long long max(long long a, long long b) { return a > b ? a : b; } 
void input();
void solve();

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    ios_base::sync_with_stdio(false);

    input();
    solve();

    cout << ans << endl;

    return 0;
}

void input() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        lectures.emplace_back(vector<int>{a, b, c});
    }
}

void solve() {
    vector<int> sum_lecture_a, sum_lecture_b, sum_lecture_c;
    long long sum_a = 0, sum_b = 0, sum_c = 0;

    for (vector<int> lecture : lectures) {
        sum_lecture_a.emplace_back(lecture[0] + lecture[1]);
        sum_lecture_b.emplace_back(lecture[0] + lecture[2]);
        sum_lecture_c.emplace_back(lecture[1] + lecture[2]);
    }

    sort(sum_lecture_a.rbegin(), sum_lecture_a.rend());
    sort(sum_lecture_b.rbegin(), sum_lecture_b.rend());
    sort(sum_lecture_c.rbegin(), sum_lecture_c.rend());
    
    for (int i = 0; i < K; i++) {
        sum_a += sum_lecture_a[i];
        sum_b += sum_lecture_b[i];
        sum_c += sum_lecture_c[i];
    }

    ans = max(sum_a, max(sum_b, sum_c));
}

/* dfs 방식 시간 초과
int calcu_ans() {
    vector<int> sum = {0, 0, 0};

    for (int i = 0; i < N; i++) {
        if (isSelected[i]) {
            sum[0] += lectures[i][0];
            sum[1] += lectures[i][1];
            sum[2] += lectures[i][2];
        }
    }

    sort(sum.rbegin(), sum.rend());

    return sum[0] + sum[1];
}

void dfs(int cnt) {
    if (cnt == K) {
        ans = max(ans, calcu_ans());
        return;
    }

    for (int i = 0; i < N; i++) { // 전체 강의
        isSelected[i] = true;
        dfs(cnt+1);
        isSelected[i] = false;
    }
}
*/

/*
강의 N개

i번째 강의는 ai, bi, ci씩 올림

K개의 강의만 수강

모두 기르기 힘듦 => 두 가지 역량만 최대화

N개 중 K개 골랐을 때 두 종류 역량의 합 최댓값

3 2
2 4 10
55 8 2
1 9 5
*/

/*

2개만 정하고 
2개의 합 기준 정렬 (내림차순)
K개 더한 결과 아웃풋

비교 3개 (2개 고르는 경우의 수)
*/