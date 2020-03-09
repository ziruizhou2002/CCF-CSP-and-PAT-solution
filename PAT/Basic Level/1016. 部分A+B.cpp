#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    string A, B;
    gg Da, Db, a = 0, b = 0;
    cin >> A >> Da >> B >> Db;
    for (auto c : A)
        if (c - '0' == Da)
            a = a * 10 + Da;
    for (auto c : B)
        if (c - '0' == Db)
            b = b * 10 + Db;
    printf("%lld", a + b);
    return 0;
}