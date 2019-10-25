#include <bits/stdc++.h>
using namespace std;
auto lowbit = [](int x) { return x & (-x); };
vector<int> c(100005);
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
    int n;
    long long ans = 0;
    cin >> n;
    vector<int> A(n), left(n);
    for (int i = 0; i < A.size(); ++i) {
        cin >> A[i];
        update(A[i], 1);
        left[i] = i + 1 - getSum(A[i]);
    }
    fill(c.begin(), c.end(), 0);
    for (int i = A.size() - 1; i >= 0; --i) {
        update(A[i], 1);
        ans += left[i] * 1LL * getSum(A[i] - 1);
    }
    cout << ans;
    return 0;
}