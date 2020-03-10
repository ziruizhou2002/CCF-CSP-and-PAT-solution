#include <bits/stdc++.h>
using namespace std;
using gg = long long;  //类型别名
int main() {
    ios::sync_with_stdio(false);
    gg n, a;
    unordered_set<gg> us;  //存储被覆盖的数
    cin >> n;
    vector<gg> v;
    while (n--) {
        cin >> a;
        v.push_back(a);
        while (a != 1) {
            if (a % 2 == 1)
                a = a * 3 + 1;
            a /= 2;
            us.insert(a);
        }
    }
    sort(v.begin(), v.end(), greater<gg>());  //从大到小排序
    bool first = true;  //标志是否是第一个输出的数字，控制输出空格
    for (auto i : v) {
        if (not us.count(i)) {  // i是关键数
            cout << (first ? "" : " ") << i;
            first = false;
        }
    }
    return 0;
}