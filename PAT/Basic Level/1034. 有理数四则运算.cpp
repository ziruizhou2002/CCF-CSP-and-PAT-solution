#include <bits/stdc++.h>
using namespace std;
using gg = long long;
//通过欧几里得算法计算两个正整数的最大公约数
gg gcd(gg a, gg b) { return b == 0 ? a : gcd(b, a % b); }
//以下代码进行分数的输入、输出、化简以及加减乘除四则运算
using F = array<gg, 2>;
//分数的输入，针对的是按a/b的格式给出分数形式，分母不为0
F input() {
    F f;
    char c;  //吸收'/'符号
    cin >> f[0] >> c >> f[1];
    return f;
}
//分数的化简
void simplify(array<gg, 2>& f) {
    if (f[0] == 0) {  //如果分子f[0]为0，则令f[1]=1
        f[1] = 1;
        return;
    }
    if (f[1] < 0) {  //如果分母f[1]为负，将分子f[0]和分母f[1]都取相反数
        f[1] = -f[1];
        f[0] = -f[0];
    }
    gg d = gcd(abs(f[0]), abs(f[1]));  //求出分子f[0]和分母f[1]绝对值的最大公约数
    f[0] /= d;
    f[1] /= d;
}
//分数的加法
F Plus(const F& f1, const F& f2) {
    F f;
    f[0] = f1[0] * f2[1] + f2[0] * f1[1];
    f[1] = f1[1] * f2[1];
    simplify(f);
    return f;
}
//分数的减法
F Sub(const F& f1, const F& f2) {
    F f;
    f[0] = f1[0] * f2[1] - f2[0] * f1[1];
    f[1] = f1[1] * f2[1];
    simplify(f);
    return f;
}
//分数的乘法
F Multiply(const F& f1, const F& f2) {
    F f;
    f[0] = f1[0] * f2[0];
    f[1] = f1[1] * f2[1];
    simplify(f);
    return f;
}
//分数的除法
F Div(const F& f1, const F& f2) {
    F f;
    f[0] = f1[0] * f2[1];
    f[1] = f1[1] * f2[0];
    simplify(f);
    return f;
}
//分数输出
void output(const F& f) {
    if (f[0] < 0)
        cout << '(';
    if (f[1] == 1) {
        cout << f[0];
    } else if (abs(f[0]) < f[1]) {
        cout << f[0] << "/" << f[1];
    } else
        cout << f[0] / f[1] << " " << abs(f[0]) % f[1] << "/" << f[1];
    if (f[0] < 0)
        cout << ')';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto f1 = input(), f2 = input();
    simplify(f1);
    simplify(f2);
    unordered_map<char, function<F(F, F)>> um = {
        {'+', Plus}, {'-', Sub}, {'*', Multiply}, {'/', Div}};
    for (char c : {'+', '-', '*', '/'}) {
        output(f1);
        cout << ' ' << c << ' ';
        output(f2);
        cout << " = ";
        if (c == '/' and f2[0] == 0) {
            cout << "Inf\n";
        } else {
            auto f3 = um[c](f1, f2);
            output(f3);
            cout << '\n';
        }
    }
    return 0;
}