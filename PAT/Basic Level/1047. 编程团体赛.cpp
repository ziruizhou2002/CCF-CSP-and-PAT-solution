#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    gg n, k, s;
    cin >> n;
    array<gg, 1005> h{};
    while (n--) {
        char c;
        cin >> k >> c >> s >> s;
        h[k] += s;
    }
    auto i = max_element(h.begin(), h.end());
    cout << (i - h.begin()) << ' ' << *i;
    return 0;
}