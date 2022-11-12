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
    int n;
    cin >> n;
    vector<double> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    vector<vector<double>> dp(n + 1, vector<double>(n + 1)); // dp[i][j] = chance of i heads and j tails, from the prefix of size i+j
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int k = i + j;
            if (k >= n) {
                break;
            }
            dp[i + 1][j] += p[k] * dp[i][j];
            dp[i][j + 1] += (1 - p[k]) * dp[i][j];
        }
    }
    double ans = 0;
    for (int i = (n + 1) / 2; i <= n; i++) {
        ans += dp[i][n - i];
    }
    cout << setprecision(10) << fixed << ans << '\n';
}