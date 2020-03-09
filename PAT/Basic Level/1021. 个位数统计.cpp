#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    array<gg, 10> h{};
    string s;
    cin >> s;
    for (char c : s) {
        ++h[c - '0'];
    }
    for (int i = 0; i < h.size(); ++i) {
        if (h[i] > 0) {
            cout << i << ':' << h[i] << '\n';
        }
    }
    return 0;
}