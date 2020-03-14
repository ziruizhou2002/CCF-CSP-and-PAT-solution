#include <bits/stdc++.h>
using namespace std;
using gg = long long;
vector<gg> prime;  //素数表存储在prime中，prime是全局变量
void getPrime(gg n = 100005) {
    // f[i]为true，表示数字i被筛去了；如果f[i]为false，表示数字i没有被筛去
    bitset<100005> f;  //这里默认n小于100005
    for (gg i = 2; i <= n; ++i)
        if (!f[i]) {  // i没有被筛去
            prime.push_back(i);
            for (gg j = i + i; j <= n; j += i)  //筛去i的所有倍数
                f[j] = true;
        }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, ans = 0;
    cin >> ni;
    getPrime(ni);
    for (gg i = 1; i < prime.size(); ++i) {
        if (prime[i] - prime[i - 1] == 2) {
            ++ans;
        }
    }
    cout << ans;
    return 0;
}