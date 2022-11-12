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
    int m = n * 1e3;
    vector<ll> dp(m + 1, 2e18), new_dp; // (prefix size)[tot value] = min weight
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        new_dp = dp;
        for (int j = 0; j < m; j++) {
            if (dp[j] + items[i].fi <= w) {
                new_dp[j + items[i].se] = min(new_dp[j + items[i].se], dp[j] + items[i].fi);
            }
        }
        dp = new_dp;
    }
    for (int i = m; i >= 0; i--) {
        if (dp[i] != 2e18) {
            cout << i << '\n';
            return 0;
        }
    }
}