#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg mi, ki;
    cin >> mi;
    while (mi--) {
        cin >> ki;
        gg m = 1;
        for (gg i = ki; i != 0; i /= 10)
            m *= 10;
        for (gg n = 1; n < 10; ++n) {
            if (n * ki * ki % m == ki) {
                cout << n << ' ' << n * ki * ki << '\n';
                goto loop;
            }
        }
        cout << "No\n";
    loop:;
    }
    return 0;
}