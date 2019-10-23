#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    cout << n / 10 + n / 50 * 2 + n % 50 / 30;
    return 0;
}
