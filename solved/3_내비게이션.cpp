#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int N;
pair<int, int> start_node;
pair<int, int> end_node;
vector<vector<pair<int, int>>> middle_nodes;

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
    cin >> N;
    cin >> start_node.first >> start_node.second;
    cin >> end_node.first >> end_node.second;

    for (int i = 0; i < N; i++) {
        int M;
        cin >> M;
        
        vector<pair<int, int>> tmp_vec;
        for (int j = 0; j < M; j++) {
            int x, y; cin >> x >> y;
            tmp_vec.emplace_back(make_pair(x, y));
        }

        middle_nodes.emplace_back(tmp_vec);
    }
}

void solve() {
    pair<long long, int> best_navi = make_pair(LLONG_MAX, 0); // 거리, 네비 번호

    int idx = 1;
    for (vector<pair<int ,int>> v : middle_nodes) {
        long long tmp_dis = 0;
        int pos_x = start_node.first, pos_y = start_node.second;

        for (pair<int, int> p : v) {
            tmp_dis += (long long)abs(p.first - pos_x) + abs(p.second - pos_y);

            pos_x = p.first;
            pos_y = p.second;
        }
        
        tmp_dis += (long long)abs(end_node.first - pos_x) + abs(end_node.second - pos_y);
    
        if (best_navi.first > tmp_dis) {
            best_navi.first = tmp_dis;
            best_navi.second = idx;
        }
        
        idx++;
    }

    cout << best_navi.second << endl;
}

/*
3
0 0 10 10
2
11 1
9 9
2
1 12
9 9
2
5 5
9 9
*/