#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    gg n, t, help = 1;
    cin >> n;
    gg ans[5]{}, num[5]{};  // ans记录A[1]~A[5]，num记录数字出现次数
    while (n--) {
        cin >> t;
        if (t % 10 == 0) {  // A[1]
            ans[0] += t;
            ++num[0];
        } else if (t % 5 == 1) {  // A[2]
            ans[1] += help * t;
            help *= -1;
            ++num[1];
        } else if (t % 5 == 2) {  // A[3]
            ++ans[2];
            ++num[2];
        } else if (t % 5 == 3) {  // A[4]
            ans[3] += t;
            ++num[3];
        } else if (t % 5 == 4 and t > ans[4]) {  // A[5]
            ans[4] = t;
            ++num[4];
        }
    }
    for (int i = 0; i < 5; ++i) {
        cout << (i == 0 ? "" : " ");
        if (num[i] == 0) {
            cout << 'N';
        } else {
            cout << fixed << setprecision(i == 3 ? 1 : 0)
                 << (i == 3 ? ans[i] * 1.0 / num[i] : ans[i] * 1.0);
        }
    }
    return 0;
}