#include <bits/stdc++.h>
using namespace std;
void output(string& s, array<int, 3> rgb = {0, 0, 0}) {
    for (char c : s) {
        if (c == 'R' || c == 'G' || c == 'B') {
            string t = to_string(rgb[c == 'R' ? 0 : c == 'G' ? 1 : 2]);
            for (char cc : t)
                printf("\\x%02X", cc);
        } else
            printf("\\x%02X", c);
    }
}
int main() {
    string back = "\x1b[48;2;R;G;Bm", reset = "\x1b[0m";
    const array<int, 3> RGBi = {7, 9, 11};
    int m, n, p, q;
    cin >> m >> n >> p >> q;
    vector<vector<array<int, 3>>> image(n);
    string rgb;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> rgb;
            if (rgb.size() == 2)
                rgb += string(5, rgb.back());
            else if (rgb.size() == 4)
                rgb = "#" + string(2, rgb[1]) + string(2, rgb[2]) + string(2, rgb[3]);
            image[i].push_back({0, 0, 0});
            for (int t = 0; t < 3; ++t)
                image[i].back()[t] = (rgb[2 * t + 1] - '0') * 16 + rgb[2 * t + 2] - '0';
        }
    }
    array<int, 3> last = {0, 0, 0}, start = {0, 0, 0};
    for (int i = 0; i < n / q; ++i) {
        for (int j = 0; j < m / p; ++j) {
            array<int, 3> cur = {0, 0, 0};
            for (int r = 0; r < q; ++r) {
                for (int s = 0; s < p; ++s) {
                    for (int t = 0; t < 3; ++t)
                        cur[t] += image[i * q + r][j * p + s][t];
                }
            }
            for (int t = 0; t < 3; ++t)
                cur[t] /= p * q;
            if (cur != last) {
                if (cur == start)
                    output(reset);
                else {
                    output(back, cur);
                }
            }
            last = cur;
            printf("\\x%02X", ' ');
        }
        if (last != start)
            output(reset);
        printf("\\x%02X", '\n');
    }
    return 0;
}