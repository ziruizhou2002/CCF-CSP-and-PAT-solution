#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setfill('0');
    gg n, m, a, b, r, k;
    cin >> m >> n >> a >> b >> r;
    for (auto i = 0; i < m; ++i) {
        for (auto j = 0; j < n; ++j) {
            cin >> k;
            k = k >= a and k <= b ? r : k;
            cout << setw(3) << k << (j == n - 1 ? '\n' : ' ');
        }
    }
    return 0;
}