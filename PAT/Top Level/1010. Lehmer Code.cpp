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
    cin >> n;
    vector<int> A(n);
    map<int, int> m;
    for (int i = 0; i < A.size(); ++i) {
        cin >> A[i];
        m.insert({A[i], i});
    }
    int j = 1;
    for (auto& i : m) {
        A[i.second] = j++;
    }
    for (int i = A.size() - 1; i >= 0; --i) {
        update(A[i], 1);
        A[i] = getSum(A[i] - 1);
    }
    for (int i = 0; i < A.size(); ++i)
        cout << A[i] << (i == A.size() - 1 ? "" : " ");
    return 0;
}