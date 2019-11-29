#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    int a[N][M];
    vector<pair<int, int> > v;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < N; ++i) {
        int current = a[i][0], num = 1;
        for (int j = 1; j < M; ++j) {
            if (a[i][j] == current)
                ++num;
            else {
                current = a[i][j];
                num = 1;
            }
            if (num >= 3) {
                v.push_back({i, j});
                if (num == 3) {
                    v.push_back({i, j - 1});
                    v.push_back({i, j - 2});
                }
            }
        }
    }
    for (int i = 0; i < M; ++i) {
        int current = a[0][i], num = 1;
        for (int j = 1; j < N; ++j) {
            if (a[j][i] == current)
                ++num;
            else {
                current = a[j][i];
                num = 1;
            }
            if (num >= 3) {
                v.push_back({j, i});
                if (num == 3) {
                    v.push_back({j - 1, i});
                    v.push_back({j - 2, i});
                }
            }
        }
    }
    for (int i = 0; i < v.size(); ++i)
        a[v[i].first][v[i].second] = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}