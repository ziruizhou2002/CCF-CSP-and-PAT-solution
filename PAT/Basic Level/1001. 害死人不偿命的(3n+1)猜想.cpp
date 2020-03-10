#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    gg n, ans = 0;
    cin >> n;
    for (; n != 1; ++ans) {
        if (n % 2 == 1) {  // n???
            n = 3 * n + 1;
        }
        n /= 2;
    }
    cout << ans;
    return 0;
}