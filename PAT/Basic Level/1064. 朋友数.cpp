#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg n;
    set<gg> s;
    cin >> n;
    while (n--) {
        gg sum = 0, a;
        cin >> a;
        do {
            sum += a % 10;
            a /= 10;
        } while (a != 0);
        s.insert(sum);
    }
    cout << s.size() << '\n';
    for (auto i = s.begin(); i != s.end(); ++i) {
        cout << (i == s.begin() ? "" : " ") << *i;
    }
    return 0;
}