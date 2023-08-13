#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
using namespace std;
 
#define int int64_t
 
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
#define PB push_back
#define F first
#define S second
 
// let X be the amount of cycles of 2, 4, 8, 6 to go through from some state (S, K)
 
// the total discount (which we want to maximize) is:
// (S + 20X) * (K - 4X)
// SK - 4SX + 20KX - 80X^2
// -80X^2 + (20K - 4S)X + SK
 
// the vertex V of the parabola is at -B / 2A
// V.x = (4S - 16K) / (-160)
 
// find, plug in, and ckmax the ceil and floor of this
 
void solve() {
    int S, K;
    cin >> S >> K;
    int ans = S * K;
    if (S % 10 == 5) {
        ans = max(ans, (S + 5) * (K - 1));
    } else if (S % 10) {
        if (S % 2) {
            S += S % 10;
            K--;
        }
        F0R(i, 4) {
            auto try_x = [&](int x) {
                x = max(x, (int)0);
                return (S + 20 * x) * (K - 4 * x);
            };
            auto ceil_div = [](int a, int b) {
                return (a + b - 1) / b;
            };
            auto get_best = [&]() {
                int flr = (4 * S - 20 * K) / -160;
                int ceil = (4 * S - 20 * K - 159) / -160;
                return max(try_x(flr), try_x(ceil));
            };
 
            ans = max(ans, get_best());
 
            S += S % 10;
            K--;
            if (K < 0) {
                break;
            }
        }
    }
    cout << ans << '\n';
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}
 
// Read the statement carefully, take your time
// Don't be intimidated, the solution is probably simpler than you think
// CM soon :pray: