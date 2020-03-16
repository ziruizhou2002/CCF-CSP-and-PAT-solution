#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg n;
    cin >> n;
    vector<double> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());
    cout << floor(accumulate(v.begin() + 1, v.end(), v[0],
                             [](double a, double b) { return (a + b) / 2; }));
    return 0;
}