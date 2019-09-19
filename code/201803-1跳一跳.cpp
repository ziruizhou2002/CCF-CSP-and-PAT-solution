#include <bits/stdc++.h>
using namespace std;
int main() {
    int a = 1, ans = 0, num = 0;  //a存储输入数据，ans为最终得分，num为连跳方块中心次数
    while (cin >> a && a != 0)  //数据输入还没完成且a!=0
        if (a == 1) {  //如果a==1
            ans += a;  //加上1分
            num = 0;  //连跳方块中心次数归零
        } else if (a == 2)  //a==2
            ans += 2 * (++num);  //递增连跳方块中心次数，得分为该次数乘2
    cout << ans;
    return 0;
}
