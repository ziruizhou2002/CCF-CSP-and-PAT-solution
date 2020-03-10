#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    gg n, ans1 = 0, ans2 = 0;
    cin >> n;
    while (n--) {
        gg a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        if (a2 == a1 + b1 and b2 != a1 + b1) {
            ++ans2;
        } else if (a2 != a1 + b1 and b2 == a1 + b1) {
            ++ans1;
        }
    }
    cout << ans1 << ' ' << ans2;
    return 0;
}