#include <bits/stdc++.h>
using namespace std;
using gg = long long;
inline gg
    compare(char c1,
            char c2) {  //得出甲乙谁胜谁负，甲胜返回1，乙胜返回-1，平局返回0
    return c1 == c2 ? 0 :
                      (c1 == 'J' and c2 == 'B') or (c1 == 'B' and c2 == 'C') or
                              (c1 == 'C' and c2 == 'J') ?
                      1 :
                      -1;
}
char maxWin(map<char, gg>& m) {  //获取获胜最多的手势
    char c = 'B';
    for (auto& i : m) {
        if (i.second > m[c])
            c = i.first;
    }
    return c;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    array<gg, 3> ans{};  //记录甲的胜平负次数
    array<map<char, gg>, 2> win{};  //记录甲乙获胜的各手势次数
    gg n;
    cin >> n;
    while (n--) {
        char c1, c2;
        cin >> c1 >> c2;
        gg c = compare(c1, c2);
        if (c == 1) {
            ++ans[0];
            ++win[0][c1];
        } else if (c == -1) {
            ++ans[2];
            ++win[1][c2];
        } else {
            ++ans[1];
        }
    }
    for (auto i = ans.begin(); i != ans.end();
         ++i) {  //正序输出，表示甲的胜平负次数
        cout << *i << (i == ans.end() - 1 ? "\n" : " ");
    }
    for (auto i = ans.rbegin(); i != ans.rend();
         ++i) {  //倒序输出，表示乙的胜平负次数
        cout << *i << (i == ans.rend() - 1 ? "\n" : " ");
    }
    cout << maxWin(win[0]) << " " << maxWin(win[1]);
    return 0;
}