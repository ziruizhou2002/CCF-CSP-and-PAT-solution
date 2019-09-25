#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, t = 0, k = 0, p = -1;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int a, b = 0, c;
        cin >> a;
        t += a;
        for (int j = 0; j < m; ++j) {
            cin >> c;
            b += c;
        }
        t += b;
        if (abs(b) > p) {
            k = i;
            p = abs(b);
        }
    }
    cout << t << " " << k << " " << p;
    return 0;
}
