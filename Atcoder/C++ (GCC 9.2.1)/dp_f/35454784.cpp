#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define all(x) (x).begin(), (x).end()
#define siz(x) (int)(x).size()
#define fi first
#define se second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t;
    cin >> s >> t;
    int n = siz(s), m = siz(t);
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1e9));
    vector<vector<char>> save(n + 1, vector<char>(m + 1, '*'));
    vector<vector<pair<int, int>>> prev(n + 1, vector<pair<int, int>>(m + 1));
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i < n && dp[i][j] > dp[i + 1][j]) {
                // dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                dp[i + 1][j] = dp[i][j];
                prev[i + 1][j] = {i, j};
            }
            if (j < m && dp[i][j] > dp[i][j + 1]) {
                // dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
                dp[i][j + 1] = dp[i][j];
                prev[i][j + 1] = {i, j};
            }
            if (i < n && j < m && s[i] == t[j] && dp[i][j] + 1 > dp[i + 1][j + 1]) {
                // dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
                dp[i + 1][j + 1] = dp[i][j] + 1;
                save[i + 1][j + 1] = s[i];
                prev[i + 1][j + 1] = {i, j};
            }
        }
    }
    int i = n, j = m;
    string ans;
    while (i > 0 || j > 0) {
        if (save[i][j] != '*') {
            ans += save[i][j];
        }
        auto p = prev[i][j];
        i = p.fi;
        j = p.se;
    }
    reverse(all(ans));
    cout << ans << '\n';
    // cout << dp[n][m] << '\n';
}