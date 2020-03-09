#include <bits/stdc++.h>
using namespace std;
int main() {
    string A, B;
    int Da, Db, a = 0, b = 0;
    cin >> A >> Da >> B >> Db;
    for (auto c : A)
        if (c - '0' == Da)
            a = a * 10 + Da;
    for (auto c : B)
        if (c - '0' == Db)
            b = b * 10 + Db;
    printf("%d", a + b);
    return 0;
}