// by ask
 
#include <bits/stdc++.h>
using namespace std;
 
const long long MOD = 1e9 + 7;
 
int main() {
 ios::sync_with_stdio(0);
 cin.tie(0);
 
    int T, L, R;
    cin >> T >> L >> R;
 
    vector<long long> DP(R + 1, 1e18);
    DP[1] = 0;
 
    for (int i = 1; i < R; i++) {
        for (int j = 2; i * j <= R; j++) {
            DP[i * j] = min(DP[i * j], DP[i] + 1ll * i * j * (j - 1) / 2);
        }
    }
 
    long long t_exp = 1, ans = 0;
    for (int i = L; i <= R; i++) {
        long long cost = DP[i] % MOD;
        long long term = t_exp * cost % MOD;
        ans = (ans + term) % MOD;
        t_exp = t_exp * T % MOD;
    }
    cout << ans << '\n';
}