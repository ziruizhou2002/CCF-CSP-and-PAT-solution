#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, A[1005];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    cout << (A[0] + A[1]) / 2;
    for (int i = 1; i < n - 1; ++i)
        cout << " " << (A[i - 1] + A[i] + A[i + 1]) / 3;
    cout << " " << (A[n - 1] + A[n - 2]) / 2;
    return 0;
}
