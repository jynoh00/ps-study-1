#include <iostream>

#define MAX 10001
#define endl "\n"

using namespace std;

int T;

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
    int N, A, B, u, v;
    cin >> T;

    for (int i = 1; i <= T; i++) {
        cin >> N >> A >> B;
        
        for (int n = 1; n <= N; n++) {
            cin >> u >> v;
        }
    }
}

void solve() {
    for (int i = 1; i <= T; i++) {
        cout << "Material Management " << i << endl;
        cout << "Classification ---- End!" << endl;
    }
}

/*

크기 합 < A
무게 합 < B

그룹 수 최소화

부품 관리 횟수 T

부품 개수 N
크기 제한 A, B
u, v가 N개

2

3   N
4 5 A B
2 3 u1 v1
1 4 u2 v2
3 1 u3 v3

2   N
2 2 A B
2 2 u1 v1
2 2 u2 v2

*/