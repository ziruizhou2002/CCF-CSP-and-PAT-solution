#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    gg n;
    cin >> n;
    do {
        string s = to_string(n);
        while (s.size() < 4)
            s.push_back('0');
        sort(s.begin(), s.end());
        gg a = stoll(s);
        sort(s.begin(), s.end(), greater<char>());
        gg b = stoll(s);
        n = b - a;
        printf("%04lld - %04lld = %04lld\n", b, a, n);
    } while (n != 0 and n != 6174);
    return 0;
}