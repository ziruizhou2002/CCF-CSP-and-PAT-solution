#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg n;
    cin >> n;
    string s;
    while (cin >> s) {
        if (s.back() == 'T') {
            cout << (s[0] - 'A' + 1);
        }
    }
    return 0;
}