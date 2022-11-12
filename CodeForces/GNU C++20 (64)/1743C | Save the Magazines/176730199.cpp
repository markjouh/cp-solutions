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
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        string s;
        cin >> n >> s;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<vector<ll>> dp(n, vector<ll>(2)); // [prefix size][last lid covered?] = max value
        if (s[0] == '1') {
            dp[0][1] = a[0];
        }
        for (int i = 1; i < n; i++) {
            if (s[i] == '1') {
                dp[i][0] = dp[i - 1][0] + a[i - 1];
                dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + a[i];
            } else {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            }
        }
        cout << max(dp[n - 1][0], dp[n - 1][1]) << '\n';
    }
}