#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    string s;
    gg n;
    cin >> s >> n;
    while (--n) {
        string t;
        for (gg i = 0, j; i < s.size(); i = j) {
            j = s.find_first_not_of(s[i], i + 1);
            if (j == -1)
                j = s.size();
            t += string(1, s[i]) + to_string(j - i);
        }
        s = t;
    }
    cout << s;
    return 0;
}