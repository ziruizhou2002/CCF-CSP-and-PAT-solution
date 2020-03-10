#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    gg n, d, k, k1 = 0, k2 = 0;
    double e, a;
    cin >> n >> e >> d;
    for (gg i = 0; i < n; ++i) {
        cin >> k;
        gg num = 0;
        for (gg j = 0; j < k; ++j) {
            cin >> a;
            if (a < e) {
                ++num;
            }
        }
        if (num > k / 2 and k <= d)
            ++k1;
        else if (num > k / 2 and k > d)
            ++k2;
    }
    printf("%.1f%% %.1f%%", k1 * 100.0 / n, k2 * 100.0 / n);
    return 0;
}