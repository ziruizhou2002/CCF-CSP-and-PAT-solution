#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    array<double, 3> p{};
    gg mi, xi, yi;
    cin >> mi >> xi >> yi;
    for (gg i = 99; i >= 10; --i) {
        gg j = i % 10 * 10 + i / 10;
        p = {i * 1.0, j * 1.0, j * 1.0 / yi};
        if (abs(p[2] - abs(i - j) * 1.0 / xi) < 1e-9) {
            cout << p[0];
            for (auto i : p) {
                cout << ' ' << (i > mi ? "Cong" : i < mi ? "Gai" : "Ping");
            }
            return 0;
        }
    }
    cout << "No Solution";
    return 0;
}