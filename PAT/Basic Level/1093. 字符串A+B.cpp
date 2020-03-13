#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    bitset<128> h;
    while (getline(cin, s)) {
        for (char c : s) {
            if (not h[c]) {
                h[c] = true;
                cout << c;
            }
        }
    }
    return 0;
}