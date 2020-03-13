#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ai, bi;
    cin >> ai >> bi;
    ai *= bi;
    while (ai % 10 == 0)
        ai /= 10;
    while (ai != 0) {
        cout << ai % 10;
        ai /= 10;
    }
    return 0;
}