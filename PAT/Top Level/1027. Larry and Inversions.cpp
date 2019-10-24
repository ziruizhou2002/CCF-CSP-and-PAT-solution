#include <bits/stdc++.h>
using namespace std;
auto lowbit = [](int x) { return x & (-x); };
vector<int> c(1005);
void update(int x, int v) {
    for (int i = x; i < c.size(); i += lowbit(i))
        c[i] += v;
}
int getSum(int x) {
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        sum += c[i];
    return sum;
}
int main() {
    int n, a;
    cin >> n;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> A[i];
    int ans[n + 1][n + 1] = {};
    for (int i = 1; i <= n; ++i) {
        fill(c.begin(), c.end(), 0);
        for (int j = i; j <= n; ++j) {
            update(A[j], 1);
            ans[i][j] = ans[i][j - 1] + j - i + 1 - getSum(A[j]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            int k = ans[1][n] - 2 * ans[i][j] + (j - i) * (j - i + 1) / 2;
            cout << k << (i == n && j == n ? "" : " ");
        }
    }
    return 0;
}