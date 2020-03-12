#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni;
    cin >> ni;
    using Player = array<gg, 3>;
    vector<Player> v(ni);
    for (gg i = 0; i < ni; ++i) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }
    auto ans = minmax_element(
        v.begin(), v.end(), [](const Player& p1, const Player& p2) {
            return hypot(p1[1], p1[2]) < hypot(p2[1], p2[2]);
        });
    cout << setfill('0') << setw(4) << (*ans.first)[0] << ' ' << setw(4)
         << (*ans.second)[0];
    return 0;
}