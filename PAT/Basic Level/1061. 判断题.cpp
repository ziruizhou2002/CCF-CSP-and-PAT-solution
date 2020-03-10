#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    gg n, m;
    cin >> n >> m;
    vector<array<gg, 2>> problems(m);
    for (auto i = 0; i < m; ++i)
        cin >> problems[i][0];
    for (auto i = 0; i < m; ++i)
        cin >> problems[i][1];
    while (n--) {
        gg s = 0, a;
        for (int i = 0; i < m; ++i) {
            cin >> a;
            if (a == problems[i][1]) {
                s += problems[i][0];
            }
        }
        cout << s << '\n';
    }
    return 0;
}