#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    array<array<gg, 2>, 1005> h{};
    gg n, a, b, c;
    cin >> n;
    while (n--) {
        cin >> a >> b >> c;
        h[b] = {a, c};
    }
    cin >> n;
    while (n--) {
        cin >> a;
        printf("%016lld %lld\n", h[a][0], h[a][1]);
    }
    return 0;
}