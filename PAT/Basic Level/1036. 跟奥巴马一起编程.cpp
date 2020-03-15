#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    gg n;
    char c;
    cin >> n >> c;
    for (gg i = 0; i < n; ++i)
        cout << c;
    cout << '\n';
    gg row = (n + 1) / 2;
    for (gg i = 0; i < row - 2; ++i) {
        cout << c;
        for (gg j = 0; j < n - 2; ++j)
            cout << ' ';
        cout << c << '\n';
    }
    for (gg i = 0; i < n; ++i)
        cout << c;
    return 0;
}