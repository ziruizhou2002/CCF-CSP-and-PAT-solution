#include <bits/stdc++.h>
using namespace std;
using gg = long long;
bool isPrime(gg n) {
    if (n < 2)  // n小于2，一定不是素数
        return false;
    for (gg i = 2; i <= (gg)sqrt(n); ++i)  //遍历2~根号n所有的数
        if (n % i == 0)  // n能被i整除，说明n不是素数
            return false;
    return true;  // n不能被2~n任何数整除，则n是素数
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg mi, ni;
    cin >> mi >> ni;
    for (gg i = 2, j = 0; j <= ni; ++i) {
        if (isPrime(i)) {
            ++j;
            if (j >= mi and j <= ni) {
                cout << i << ((j - mi + 1) % 10 == 0 or j == ni ? '\n' : ' ');
            }
        }
    }
    return 0;
}