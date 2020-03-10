#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    gg a, b;
    cin >> a >> b;
    a = (gg)round((b - a) / 100.0);
    printf("%02lld:%02lld:%02lld", a / 3600, a / 60 % 60, a % 60);
    return 0;
}