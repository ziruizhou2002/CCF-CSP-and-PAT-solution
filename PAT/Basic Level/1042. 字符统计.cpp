#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    array<gg, 128> h{};
    string s;
    getline(cin, s);
    for (char c : s) {
        if (isalpha(c)) {
            ++h[tolower(c)];
        }
    }
    auto i = max_element(h.begin(), h.end());
    cout << (char)(i - h.begin()) << ' ' << *i;
    return 0;
}