例题1 - 4  【PAT B -
        1026】程序运行时间
【题意概述】 给出两个时钟打点数C_1和C_2，假设常数CLK_TCK为100，求C_1到C_2间的时间。注意运行时间的秒数为\left(
            C_2 - C_1\right)\div CLK_TCK。
【输入输出格式】 输入在一行中顺序给出2个整数C1和C2，且C_1 <
    C_2。 运行时间必须按照“hh : mm : ss”（即2位的时 : 分 : 秒）格式输出。不足1秒的时间四舍五入到秒。
【数据规模】 0\le C_1,
    C_2\le{10} ^ 7
【算法设计】 我们可以很轻松地求出以秒为单位的运行时间，那么如何得到“时 : 分
    : 秒”格式下的时间呢？假设以秒为单位的运行时间为t，“时 : 分
    : 秒”格式下的时分秒数分别为h、m、s，我们有以下公式：
      h =\lfloor t /
         3600\rfloor m =\left\lfloor t /
                        60\right\rfloor\ mod\ 60 s = t\ mod\ 60 秒数的四舍五入可以用round函数来实现。
【C++ 代码】 1 2 3 4 5 6 7 8 9 10 #include<bits / stdc++.h> using namespace std;
using gg = long long;
int main() {
    gg a, b;
    cin >> a >> b;
    a = (gg)round((b - a) / 100.0);
    printf("%02lld:%02lld:%02lld", a / 3600, a / 60 % 60, a % 60);
    return 0;
}
