#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, ans = 1, last, current;
    cin >> n >> last;
    for (int i = 1; i < n; ++i) {
        cin >> current;
        if (current != last) {
            ++ans;
            last = current;
        }
    }
    cout << ans;
    return 0;
}
