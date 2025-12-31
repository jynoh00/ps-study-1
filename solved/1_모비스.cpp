#include <iostream>
#include <string>

#define endl "\n"

using namespace std;

string sticker;
int mobis[5]; // MOBIS

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
    cin >> sticker;
}

void solve() {
    for (char c : sticker) {
        if (c == 'M') mobis[0]++;
        if (c == 'O') mobis[1]++;
        if (c == 'B') mobis[2]++;
        if (c == 'I') mobis[3]++;
        if (c == 'S') mobis[4]++;
    }

    for (int i : mobis) {
        if (i < 1) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

/*
MOBIS

Mobile + System
->
Mobility Beyond Integrated Solution

MOBIS 만들 수 있는 지

*/