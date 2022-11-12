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
    int n, w;
    cin >> n >> w;
    vector<pair<int, int>> items(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i].fi >> items[i].se;
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(w + 1, -2e18)); // [prefix size][weight incurred] = max value
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        dp[i + 1] = dp[i];
        for (int j = 0; j + items[i].fi <= w; j++) {
            dp[i + 1][j + items[i].fi] = max(dp[i + 1][j + items[i].fi], dp[i][j] + items[i].se);
        }
    }
    cout << *max_element(all(dp[n])) << '\n';
}