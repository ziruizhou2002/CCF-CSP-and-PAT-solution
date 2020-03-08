#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    gg t, a, b, c;
    cin >> t;
    for (gg i = 1; i <= t; ++i) {
        cin >> a >> b >> c;
        cout << "Case #" << i << ": " << (a + b > c ? "true" : "false") << "\n";
    }
    return 0;
}