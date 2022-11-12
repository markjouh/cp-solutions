#include <bits/stdc++.h>
 
#define int int64_t
 
using namespace std;
 
vector<vector<int>> g;
vector<int> score;
vector<pair<int, int>> dp;
 
void dfs(int u, int mn_p, int mx_p) {
    int n = g[u].size();
    if (n == 0) {
        dp[u] = {mn_p * score[u], mx_p * score[u]};
        return;
    }
    int def = 0;
    vector<int> add;
    for (int v : g[u]) {
        dfs(v, mn_p / n, (mx_p + n - 1) / n);
        def += dp[v].first;
        add.push_back(dp[v].second - dp[v].first);
    }
    sort(add.rbegin(), add.rend());
    dp[u].first = mn_p * score[u] + def + accumulate(add.begin(), add.begin() + mn_p % n, 0ll);
    dp[u].second = mx_p * score[u] + def;
    if (mx_p % n == 0) {
        dp[u].second += accumulate(add.begin(), add.end(), 0ll);
    } else {
        dp[u].second += accumulate(add.begin(), add.begin() + mx_p % n, 0ll);
    }
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        g.clear();
        g.resize(n);
        for (int i = 1; i < n; i++) {
            int p;
            cin >> p;
            g[p - 1].push_back(i);
        }
        score.clear();
        score.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> score[i];
        }
        dp.clear();
        dp.resize(n);
        dfs(0, k, k);
        cout << dp[0].first << '\n';
    }
}