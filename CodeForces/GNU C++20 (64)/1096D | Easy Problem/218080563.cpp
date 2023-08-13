#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "debug.h"
#else
#define dbg(x...)
#endif
 
typedef long long ll;
 
#define sz(x) static_cast<int>(size(x))
#define all(x) begin(x), end(x)
 
constexpr ll INF = LLONG_MAX / 2;
 
void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> dp(5, INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        vector<ll> new_dp(5, INF);
        for (int j = 0; j < 4; j++) {
            if (s[i] == "hard"[j]) {
                new_dp[j] = min(new_dp[j], dp[j] + a[i]);
                new_dp[j + 1] = min(new_dp[j + 1], dp[j]);
            } else {
                new_dp[j] = min(new_dp[j], dp[j]);
            }
        }
        dp = new_dp;
    }
    ll ans = INF;
    for (int i = 0; i < 4; i++) {
        ans = min(ans, dp[i]);
    }
    cout << ans << '\n';
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}
 
/*
 
We can probably use dp
dp[i][j] = prefix of i, completed characters j = min ambiguity
 
*/