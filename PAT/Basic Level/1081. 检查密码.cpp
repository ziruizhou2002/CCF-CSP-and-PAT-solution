#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg n;
    cin >> n;
    cin.get();  //吸收换行符
    string s;
    while (n--) {
        getline(cin, s);
        bool shuzi = false, zimu = false, feifa = false;
        for (char c : s) {
            if (isdigit(c))
                shuzi = true;
            if (isalpha(c))
                zimu = true;
            if (not isalnum(c) and c != '.')
                feifa = true;
        }
        if (s.size() < 6) {
            cout << "Your password is tai duan le.\n";
        } else if (feifa) {
            cout << "Your password is tai luan le.\n";
        } else if (not shuzi) {
            cout << "Your password needs shu zi.\n";
        } else if (not zimu) {
            cout << "Your password needs zi mu.\n";
        } else {
            cout << "Your password is wan mei.\n";
        }
    }
    return 0;
}