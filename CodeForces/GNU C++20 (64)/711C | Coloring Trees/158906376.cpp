#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, g;
    cin >> n >> m >> g;
    vector<int> color(n);
    for (int i = 0; i < n; i++) {
        cin >> color[i];
    }
    vector<vector<int>> cost(n, vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> cost[i][j];
        }
    }
    vector<vector<long long>> dp(g, vector<long long>(m + 1, 1e18));
    if (color[0] == 0) {
        for (int i = 1; i <= m; i++) {
            dp[0][i] = cost[0][i];
        }
    } else {
        dp[0][color[0]] = 0;
    }
    for (int i = 0; i < n - 1; i++) {
        vector<vector<long long>> new_dp(g, vector<long long>(m + 1, 1e18));
        if (color[i + 1] == 0) {
            for (int j = 0; j < g; j++) {
                for (int k = 1; k <= m; k++) { // last tree color
                    for (int l = 1; l <= m; l++) { // current tree color (to assign)
                        int new_g = j + (k != l); // groups increase if the trees are different colors
                        if (new_g < g) {
                            new_dp[new_g][l] = min(new_dp[new_g][l], dp[j][k] + cost[i + 1][l]);
                        }
                    }
                }
            }
        } else {
            for (int j = 0; j < g; j++) {
                for (int k = 1; k <= m; k++) {
                    int new_g = j + (k != color[i + 1]);
                    if (new_g < g) {
                        new_dp[new_g][color[i + 1]] = min(new_dp[new_g][color[i + 1]], dp[j][k]);
                    }
                }
            }
        }
        dp = new_dp;
    }
    long long ans = *min_element(dp[g - 1].begin(), dp[g - 1].end());
    cout << (ans >= 1e18 ? -1 : ans) << '\n';
}