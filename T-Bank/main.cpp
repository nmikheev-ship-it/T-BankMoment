#include <bits/stdc++.h>
using namespace std;

bool inRange(int l, int r, int x) {
    return l <= x && x <= r;
}

bool print_in_range(int l, int r) {
    int f0 = 0, f1 = 1;
    bool flag = false;
    while (f0 <= r) {
        if (inRange(l, r, f0)) {
            flag = true;
            cout << f0 << ' ';
        }
        int tmp = f1;
        f1 += f0;
        f0 = tmp;
    }
    return flag;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int l, r;
    cin >> l >> r;
    bool tmp = print_in_range(l, r);
    if (!tmp) {
        cout << "В заданном диапазоне нет чисел Фибоначчи\n";
    }
}