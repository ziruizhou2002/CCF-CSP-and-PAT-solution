#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const gg no = INT_MAX + 1ll;  //表示空结点
unordered_map<gg, gg> um;  //存储结点与其在中根序列中的位置
gg LCA(vector<gg>& pre, vector<gg>& in, gg r, gg left, gg right, gg p, gg q) {
    if (left > right)  //序列为空，返回空指针
        return no;
    if (pre[r] == p or pre[r] == q)
        return pre[r];
    gg i = um[pre[r]];
    auto k1 = LCA(pre, in, r + 1, left, i - 1, p, q),
         k2 = LCA(pre, in, r + 1 + i - left, i + 1, right, p, q);
    return k1 == no ? k2 : k2 == no ? k1 : pre[r];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg mi, ni, u, v;
    cin >> mi >> ni;
    vector<gg> pre(ni), in(ni);
    for (gg i = 0; i < ni; ++i) {
        cin >> in[i];
        um[in[i]] = i;
    }
    for (gg i = 0; i < ni; ++i)
        cin >> pre[i];
    while (mi--) {
        cin >> u >> v;
        bool f1 = um.count(u), f2 = um.count(v);
        if (not f1 and not f2) {
            cout << "ERROR: " << u << " and " << v << " are not found.\n";
        } else if (not f1) {
            cout << "ERROR: " << u << " is not found.\n";
        } else if (not f2) {
            cout << "ERROR: " << v << " is not found.\n";
        } else {
            gg ans = LCA(pre, in, 0, 0, ni - 1, u, v);
            if (ans == u or ans == v) {
                cout << (ans == u ? u : v) << " is an ancestor of "
                     << (ans == u ? v : u) << ".\n";
            } else {
                cout << "LCA of " << u << " and " << v << " is " << ans << ".\n";
            }
        }
    }
    return 0;
}