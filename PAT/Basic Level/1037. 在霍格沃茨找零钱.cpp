#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg g1, s1, k1, g2, s2, k2;
    char c;  //读取小数点
    cin >> g1 >> c >> s1 >> c >> k1 >> g2 >> c >> s2 >> c >> k2;
    //将输入数据统一转换到最小单位
    gg t1 = (g1 * 17 + s1) * 29 + k1, t2 = (g2 * 17 + s2) * 29 + k2;
    t2 -= t1;
    cout << t2 / 29 / 17 << '.' << abs(t2) / 29 % 17 << '.' << abs(t2) % 29;
    return 0;
}