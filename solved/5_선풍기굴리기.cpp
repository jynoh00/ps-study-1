#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>

#define endl "\n"

using namespace std;

int a, b, h;

void input();
long double solve();

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    ios_base::sync_with_stdio(false);

    input();
    cout << fixed << setprecision(10) << solve() << endl;

    return 0;
}

void input() {
    cin >> a >> b >> h;
}

long double solve() {
    if (a == b) return -1;

    long double slide = sqrt(pow(abs(a-b), 2) + pow(h, 2));
    
    if (a == 0) return pow(slide, 2) * M_PI;

    long double x = a < b ? ((a * slide) / (b - a)) : ((b * slide) / (a - b));

    return (pow(x+slide, 2) * M_PI) - (pow(x, 2) * M_PI);
}


/*
a < b
a : b = x : x + slide

b * x = a * (x + slide)

bx = ax + a * slide

(b-a)x = a * slide

x = a * slide / (b - a)


a > b
b : a = x : x + slide
ax = b(x+slide)
ax-bx = b*slide
x = b * slide / (a - b)


이후

pow (x+slide, 2) * M_PI - pow(x, 2) * M_PI

*/