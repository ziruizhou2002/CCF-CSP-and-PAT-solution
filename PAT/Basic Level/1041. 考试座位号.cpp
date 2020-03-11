#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    array<array<gg, 2>, 1005> h{};
    gg n, a, b, c;
    cin >> n;
    while (n--) {
        cin >> a >> b >> c;
        h[b] = {a, c};
    }
    cin >> n;
    cout << setfill('0');
    while (n--) {
        cin >> a;
        cout << setw(16) << h[a][0] << ' ' << h[a][1] << '\n';
    }
    return 0;
}