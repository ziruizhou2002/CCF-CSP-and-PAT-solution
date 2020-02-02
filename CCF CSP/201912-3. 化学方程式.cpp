#include <bits/stdc++.h>
using namespace std;
int n;
string formula;
unordered_map<string, int> ans;
int computeDigit(int& first, int last) {
    int i = 0;
    for (; first <= last and isdigit(formula[first]); ++first)
        i = i * 10 + formula[first] - '0';
    return i == 0 ? 1 : i;
}
void f(int first, int last, int e) {
    if (first == last or (last - first == 1 and islower(formula[last]))) {
        ans[formula.substr(first, last - first + 1)] += e;
        return;
    }
    e *= computeDigit(first, last);
    for (int i = first, j = i + 1; i <= last; i = j, ++j) {
        if (isupper(formula[i])) {
            if (j <= last and islower(formula[j]))
                ++j;
            int k = j;
            f(i, k - 1, e * computeDigit(j, last));
        } else if (formula[i] == '(') {
            for (int num = 1; num != 0; ++j) {
                if (formula[j] == '(')
                    ++num;
                else if (formula[j] == ')')
                    --num;
            }
            int k = j;
            f(i + 1, k - 1, e * computeDigit(j, last));
        }
    }
}
void expression(int first, int last, int e) {
    for (int i = first, j = first; i <= last; i = j + 1) {
        j = formula.find('+', i);
        if (j == string::npos or j > last)
            j = last + 1;
        f(i, j - 1, e);
    }
}
int main() {
    cin >> n;
    while (n--) {
        cin >> formula;
        ans.clear();
        int k = formula.find('=');
        expression(0, k - 1, 1);
        expression(k + 1, formula.size() - 1, -1);
        auto i = find_if(ans.begin(), ans.end(), [](const pair<string, int>& p) { return p.second != 0; });
        cout << ((i == ans.end()) ? "Y" : "N") << "\n";
    }
    return 0;
}
