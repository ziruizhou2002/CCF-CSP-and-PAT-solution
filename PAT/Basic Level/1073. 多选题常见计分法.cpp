#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct Problem {
    gg score;  //题目分数
    string choice;  //正确选项
    Problem(gg s) : score(s), choice("") {}
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(1);  //保留一位小数
    vector<Problem> problems;
    gg n, m, a, b, c;
    cin >> n >> m;
    string s;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        problems.push_back(Problem(a));
        while (c--) {  //读取每个选项
            cin >> s;
            problems.back().choice += s;
        }
    }
    map<pair<gg, char>, gg> num;
    for (int i = 0; i < n; ++i) {
        double score = 0.0;
        for (int j = 0; j < m; ++j) {
            string t;  //存储学生选项具体选项
            cin >> s;  //读取题目的选项个数（没有用，略过就行）
            bool w = true;  //有没有错选的选项
            do {  //读取学生全部选项
                cin >> s;
                if (problems[j].choice.find(s[0]) == -1) {  //错误选项
                    ++num[{j + 1, s[0]}];
                    w = false;
                }
                t.push_back(s[0]);
            } while (s.back() != ')');
            if (w)  //没有错选的选项，计算分值
                score +=
                    problems[j].score / (problems[j].choice == t ? 1.0 : 2.0);
            for (char c : problems[j].choice) {  //漏选选项也是错误的选项
                if (t.find(c) == -1)
                    ++num[{j + 1, c}];
            }
        }
        cout << score << '\n';  //输出学生分数
    }
    using ppgc = pair<pair<gg, char>, gg>;
    if (num.empty()) {  //没有错误的选项
        cout << "Too simple";
    } else {
        //获取最大的选项错误次数
        gg Max = max_element(num.begin(), num.end(),
                             [](const ppgc& p1, const ppgc& p2) {
                                 return p1.second < p2.second;
                             })
                     ->second;
        for (const auto& p : num) {
            if (p.second == Max) {
                cout << Max << ' ' << p.first.first << '-' << p.first.second
                     << '\n';
            }
        }
    }
    return 0;
}