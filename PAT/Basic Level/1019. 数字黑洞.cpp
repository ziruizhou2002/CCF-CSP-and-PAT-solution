#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cout << setfill('0');
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
        cout << setw(4) << b << " - " << setw(4) << a << " = " << setw(4) << n << '\n';
    } while (n != 0 and n != 6174);
    return 0;
}