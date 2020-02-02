#include <bits/stdc++.h>
using namespace std;
using LL = long long;  //类型别名
int main() {
    //键为坐标，值对应该坐标上下左右四个邻居位置存在垃圾的个数和四个对角位置中存在垃圾的个数
    map<array<LL, 2>, array<LL, 2>> m;
    LL n;
    array<LL, 2> p;
    cin >> n;
    while (n--) {
        cin >> p[0] >> p[1];
        m.insert({p, {0, 0}});  //将当前坐标插入哈希表中，默认邻居位置和对角位置垃圾个数均为0
        for (auto& i : m) {
            auto& p2 = i.first;
            if ((abs(p[0] - p2[0]) == 1 and p[1] == p2[1]) or
                (p[0] == p2[0] and abs(p[1] - p2[1]) == 1)) {  //邻居位置存在垃圾
                ++m[p][0];
                ++m[p2][0];
            } else if (abs(p[0] - p2[0]) == 1 and abs(p[1] - p2[1]) == 1) {  //对角位置存在垃圾
                ++m[p][1];
                ++m[p2][1];
            }
        }
    }
    array<LL, 5> ans{};  //存储最终结果
    for (auto& i : m)
        if (i.second[0] == 4)  //当前坐标可以作为选址
            ++ans[i.second[1]];  //递增其得分下的选址个数
    for (auto i : ans)
        cout << i << "\n";
    return 0;
}