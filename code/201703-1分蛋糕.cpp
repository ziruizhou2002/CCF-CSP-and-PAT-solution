#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k, sum = 0, a, ans = 0;
    cin >> n >> k;
    for (int i = 0; cin >> a && i < n; ++i)
        if (i == n - 1 || sum + a >= k) {
            ++ans;
            sum = 0;
        } else
            sum += a;
    cout << ans;
    return 0;
}