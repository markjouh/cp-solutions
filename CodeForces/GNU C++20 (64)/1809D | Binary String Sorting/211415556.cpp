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
 
// Horrendous impl, once I get AC I'll rewrite it
 
constexpr LL cost = 1e12;
 
void solve() {
    string S;
    cin >> S;
    int N = SZ(S);
    VE<int> pref(N);
    F0R(i, N) {
        pref[i] = (S[i] == '0');
        if (i) {
            pref[i] += pref[i - 1];
        }
    }
    VE<int> suf(N);
    RF0R(i, N) {
        suf[i] = (S[i] == '1');
        if (i + 1 < N) {
            suf[i] += suf[i + 1];
        }
    }
    LL ans = 1e18;
    F0R(i, N + 1) {
        int keep_pref = i > 0 ? pref[i - 1] : 0;
        int keep_suf = i < N ? suf[i] : 0;
        ans = min(ans, 1ll * (N - keep_pref - keep_suf) * (cost + 1));
    }
    F0R(i, N - 1) {
        if (S[i] == '1' && S[i + 1] == '0') {
            int keep_pref = i > 0 ? pref[i - 1] : 0;
            int keep_suf = i + 2 < N ? suf[i + 2] : 0;
            ans = min(ans, 1ll * (N - keep_pref - keep_suf - 2) * (cost + 1) + cost);
        }
    }
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
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