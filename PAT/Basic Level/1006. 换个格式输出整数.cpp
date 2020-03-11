#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string n;
    cin >> n;
    int s = n.size();  // s为字符串长度
    for (int i = 0; i < s; ++i) {
        // j不仅负责计数，还负责遍历从'1'到n[i]之间的字符
        for (char j = '1'; j <= n[i]; ++j) {
            // i为j-3说明是百位，i为j-2说明是十位，否则是个位
            cout << (i == s - 3 ? 'B' : i == s - 2 ? 'S' : j);
        }
    }
    return 0;
}