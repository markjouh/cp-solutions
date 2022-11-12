#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define all(x) (x).begin(), (x).end()
#define siz(x) (int)(x).size()
#define fi first
#define se second

constexpr int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w;
    cin >> h >> w;
    vector<vector<char>> grid(h, vector<char>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> dp(h, vector<int>(w));
    dp[0][0] = 1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i + 1 < h && grid[i + 1][j] != '#') {
                (dp[i + 1][j] += dp[i][j]) %= MOD;
            }
            if (j + 1 < w && grid[i][j + 1] != '#') {
                (dp[i][j + 1] += dp[i][j]) %= MOD;
            }
        }
    }
    cout << dp[h - 1][w - 1] << '\n';
}