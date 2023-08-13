#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
using namespace std;
 
typedef long long LL;
typedef pair<int, int> PII;
 
#define VE vector
#define AR array
 
#define FOR(i, A, B) for (int i = A; i < B; i++)
#define F0R(i, N) FOR(i, 0, N)
#define RFOR(i, A, B) for (int i = B - 1; i >= A; i--)
#define RF0R(i, N) RFOR(i, 0, N)
#define REP(N) F0R(_, N)
 
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define RALL(X) (X).rbegin(), (X).rend()
#define F first
#define S second
 
constexpr int MOD = 1e9 + 7;
 
void solve() {
    int N;
    cin >> N;
    VE<int> X(N);
    F0R(i, N) {
        cin >> X[i];
    }
    VE<int> pw(N);
    pw[0] = 1;
    F0R(i, N - 1) {
        pw[i + 1] = pw[i] * 2 % MOD;
    }
    int ans = 0;
    F0R(i, N - 1) {
        FOR(j, i + 1, N) {
            int l1 = -1, r1 = i; // l1: latest one that works
            while (l1 + 1 < r1) {
                int mid = l1 + (r1 - l1) / 2;
                (X[i] - X[mid] > X[j] - X[i] ? l1 : r1) = mid;
            }
            int l2 = j, r2 = N; // r2: earliest one that works
            while (l2 + 1 < r2) {
                int mid = l2 + (r2 - l2) / 2;
                (X[mid] - X[j] >= X[j] - X[i] ? r2 : l2) = mid;
            }
            ans = (ans + pw[N - r2 + l1 + 1]) % MOD;
        }
    }
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
}
 
// Read the statement carefully, take your time
// Don't be intimidated, the solution is probably simpler than you think
// CM soon :pray: