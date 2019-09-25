#include <bits/stdc++.h>
using namespace std;
int main() {
    int red, yellow, green, n, k, t, ans = 0;
    cin >> red >> yellow >> green >> n;
    while (cin >> k >> t)
        if (k == 0 || k == 1)
            ans += t;
        else if (k == 2)
            ans += t + red;
    cout << ans;
    return 0;
}
