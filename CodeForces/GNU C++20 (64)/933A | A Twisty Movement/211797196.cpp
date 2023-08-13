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
 
#define UMIN(A, B) A = min(A, B)
#define UMAX(A, B) A = max(A, B)
 
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define RALL(X) (X).rbegin(), (X).rend()
#define F first
#define S second
 
constexpr AR<int, 4> req = {1, 2, 1, 2};
 
void solve() {
    int N;
    cin >> N;
    VE<int> A(N);
    F0R(i, N) {
        cin >> A[i];
    }
    VE<VE<int>> dp(N + 1, VE<int>(4));
    FOR(i, 1, N + 1) {
        F0R(j, 4) {
            UMAX(dp[i][j], dp[i - 1][j]);
            if (A[i - 1] == req[j]) {
                UMAX(dp[i][j], dp[i - 1][j] + 1);
            } else if (j > 0) {
                UMAX(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }
    cout << dp[N][3] << '\n';
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