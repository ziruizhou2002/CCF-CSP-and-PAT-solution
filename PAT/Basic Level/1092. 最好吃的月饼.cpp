#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, mi, ai;
    cin >> ni >> mi;
    vector<gg> v(ni);
    while (mi--) {
        for (int i = 0; i < v.size(); ++i) {
            cin >> ai;
            v[i] += ai;
        }
    }
    gg ans = *max_element(v.begin(), v.end());
    cout << ans << '\n';
    bool space = false;
    for (gg i = 0; i < v.size(); ++i) {
        if (v[i] == ans) {
            cout << (space ? " " : "") << (i + 1);
            space = true;
        }
    }
    return 0;
}