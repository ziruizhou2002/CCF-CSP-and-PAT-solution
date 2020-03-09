#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    array<gg, (gg)1e5 + 5> h{};
    gg n;
    cin >> n;
    while (n--) {
        gg a, b;
        cin >> a >> b;
        h[a] += b;
    }
    auto i = max_element(h.begin(), h.end());
    cout << (i - h.begin()) << ' ' << *i;
    return 0;
}