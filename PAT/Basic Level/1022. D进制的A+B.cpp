#include <bits/stdc++.h>
using namespace std;
vector<int> trans10toR(int i, int R) {
    vector<int> ans;
    do {
        ans.push_back(i % R);
        i /= R;
    } while (i != 0);
    reverse(ans.begin(), ans.end());
    return ans;
}
int main() {
    int a, b, d;
    cin >> a >> b >> d;
    auto r = trans10toR(a + b, d);
    for (int i : r)
        cout << i;
    return 0;
}