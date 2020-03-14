#include <bits/stdc++.h>
using namespace std;
using gg = long long;
gg gcd(gg a, gg b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ki, a1, b1, a2, b2;
    char c;
    cin >> a1 >> c >> b1 >> a2 >> c >> b2 >> ki;
    double n1 = (a1 * 1.0 * ki / b1), n2 = (a2 * 1.0 * ki / b2);
    if (n1 > n2)
        swap(n1, n2);
    bool space = false;
    for (gg i = floor(n1 + 1); i <= ceil(n2 - 1); ++i) {
        if (gcd(i, ki) == 1) {
            cout << (space ? " " : "") << i << '/' << ki;
            space = true;
        }
    }
    return 0;
}