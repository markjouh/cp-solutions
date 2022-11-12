#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define siz(x) (int)(x).size()
#define fi first
#define se second
 
constexpr int M = 1e9 + 7;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int r, g;
    cin >> r >> g;
 
    int ans = 1;
    vector<int> dp(r + 1), next_dp(r + 1);
    dp[0] = 1;
    for (int i = 1; i <= 900; i++) {
        // build floor i using red blocks
        for (int j = 0; j + i <= r; j++) {
            (next_dp[j + i] += dp[j]) %= M;
        }
        // build floor i using green blocks
        int tot_used = (i - 1) * i / 2;
        for (int j = 0; j <= min(r, tot_used); j++) {
            int g_used = tot_used - j;
            if (g_used + i <= g) {
                (next_dp[j] += dp[j]) %= M;
            }
        }
        // update ans
        int tot = 0;
        for (int j = 0; j <= r; j++) {
            (tot += next_dp[j]) %= M;
        }
        if (tot > 0) {
            // cerr << "Floor " << i << ": " << tot << '\n';
            ans = tot;
            dp = next_dp;
            fill(all(next_dp), 0);
        } else {
            // cerr << "Unable to build floor " << i << ".\n";
            break;
        }
    }
 
    cout << ans << '\n';
}