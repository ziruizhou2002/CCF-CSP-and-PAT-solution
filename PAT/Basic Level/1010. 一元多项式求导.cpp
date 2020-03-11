#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg c, e;
    bool space = false;
    while (cin >> c >> e) {
        c *= e;
        --e;
        if (c != 0) {
            cout << (space ? " " : "") << c << " " << e;
            space = true;
        }
    }
    if (not space)
        cout << "0 0";
    return 0;
}