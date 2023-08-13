#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <cstdint>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
 
using namespace std;
 
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define RALL(X) (X).rbegin(), (X).rend()
#define F first
#define S second
 
#define VE vector
#define AR array
 
typedef long long LL;
typedef pair<int, int> PII;
 
// vector<bool> isprime;
// vector<LL> primes, mnfactor;
 
// void sieve(LL n) {
//     isprime.resize(n + 1);
//     fill(ALL(isprime), 1);
//     isprime[0] = isprime[1] = false;
//     mnfactor.resize(n + 1);
//     // Runs in O(n * log(log(n))).
//     for (LL i = 2; i <= n; i++) {
//         if (isprime[i]) {
//             primes.push_back(i);
//             mnfactor[i] = i;
//             for (LL j = i * i; j <= n; j += i) {
//                 isprime[j] = false;
//                 mnfactor[j] = i;
//             }
//         }
//     }
// }
 
// void solve() {
//     int T, L, R;
//     cin >> T >> L >> R;
//     vector<LL> dp(R + 1, 1e18); // dp[i] = mn cost to have i people remaining
//     dp[R] = 0;
//     for (int i = R; i > L; i--) {
//         for (auto p : primes) {
//             if (i / p < L) {
//                 break;
//             }
//             if (i % p == 0) {
//                 dp[i / p] = min(dp[i / p], dp[i] + p * (i / p) * (i / p - 1) / 2);
//             }
//         }
//     }
//     for (int i = 1; i <= R; i++) {
//         cout << dp[i] << ' ';
//     }
//     cout << '\n';
//     LL t_exp = 1, ans = 0;
//     for (int i = L; i <= R; i++) {
//         LL cost = dp[i] % MOD;
//         LL term = t_exp * cost % MOD;
//         ans = (ans + term) % MOD;
//         t_exp = t_exp * T % MOD;
//     }
//     cout << ans << '\n';
// }
 
// Try working in reverse
// Start at 1, and perform operations to increase the size
 
constexpr int MOD = 1e9 + 7;
 
void solve() {
    int T, L, R;
    cin >> T >> L >> R;
    VE<LL> dp(R + 1, 1e18); // dp[i] = cost to reach 1 from i
    dp[1] = 0;
    for (int i = 1; i < R; i++) {
        for (int j = 2; i * j <= R; j++) { // We used to have i * j elements, then divided into groups of j
            dp[i * j] = min(dp[i * j], dp[i] + 1ll * i * j * (j - 1) / 2);
        }
    }
    // cout << dp[R] << '\n';
    // for (int i = 1; i <= R; i++) {
    //     cout << dp[i] << ' ';
    // }
    // cout << '\n';
    LL t_exp = 1, ans = 0;
    for (int i = L; i <= R; i++) {
        LL cost = dp[i] % MOD;
        LL term = t_exp * cost % MOD;
        ans = (ans + term) % MOD;
        t_exp = t_exp * T % MOD;
    }
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    // sieve(5e6);
    while (T--) {
        solve();
    }
}
 
// Read the statement carefully, take your time
// Don't be intimidated, the solution is probably simpler than you think
// CM soon :pray: