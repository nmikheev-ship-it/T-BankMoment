#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()

bool inRange(ll l, ll r, ll x) {
    return l <= x && x <= r;
}

void solve() {
    ll f2 = 0, f1 = 1;
    ll l, r;
    cin >> l >> r;
    bool fl = false;
    while (f2 <= r) {
        if (inRange(l, r, f2)) {
            fl = true;
            cout << f2 << ' ';
        }
        ll tmp = f1;
        f1 += f2;
        f2 = tmp;
    }
    if (!fl) {
        cout << "В заданном диапазоне нет чисел Фибоначчи\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    solve();
    return 0;
}