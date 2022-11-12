#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define siz(x) (int)(x).size()
#define fi first
#define se second
 
constexpr int MOD = 1e8;
 
ll dp[101][101][11][11]; // [footmen used][horsemen used][footmen suffix][horsemen suffix] = ways
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
 
    dp[0][0][0][0] = 1;
 
    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            for (int k = 0; k <= k1; k++) {
                for (int l = 0; l <= k2; l++) {
                    // add footman
                    if (i + 1 <= n1 && k + 1 <= k1) {
                        (dp[i + 1][j][k + 1][0] += dp[i][j][k][l]) %= MOD;
                    }
                    // add horseman
                    if (j + 1 <= n2 && l + 1 <= k2) {
                        (dp[i][j + 1][0][l + 1] += dp[i][j][k][l]) %= MOD;
                    }
                }
            }
        }
    }
 
    ll ans = 0;
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {
            (ans += dp[n1][n2][i][j]) %= MOD;
        }
    }
    cout << ans << '\n';
}