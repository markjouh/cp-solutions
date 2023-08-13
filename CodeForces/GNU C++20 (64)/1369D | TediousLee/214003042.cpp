#include <bits/stdc++.h>
 
using namespace std;
 
#define int int64_t
 
const int MOD = 1e9 + 7;
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    const int MAXN = 2e6;
    vector<int> dp(MAXN); // dp[i] = max claws in a RDB of level i
    for (int i = 2; i < MAXN; i++) {
        dp[i] = dp[i - 1] + 2 * dp[i - 2] + (i % 3 == 2 ? 4 : 0);
        dp[i] %= MOD;
    }
    
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        cout << dp[N - 1] << '\n';
    }
}