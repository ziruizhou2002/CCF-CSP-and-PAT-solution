#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a, b, MAX = 0;
    cin >> n >> a;
    while (cin >> b) {
        MAX = max(MAX, abs(a - b));
        a = b;
    }
    cout << MAX;
    return 0;
}