#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct Student {
    string name, number;
    gg score;
    Student(gg s = 0) : score(s) {}
};
int main() {
    gg n;
    cin >> n;
    Student Max(-1), Min(101), temp;
    for (gg i = 0; i < n; ++i) {
        cin >> temp.name >> temp.number >> temp.score;
        if (Max.score < temp.score)
            Max = temp;
        if (Min.score > temp.score)
            Min = temp;
    }
    cout << Max.name << " " << Max.number << "\n" << Min.name << " " << Min.number;
    return 0;
}