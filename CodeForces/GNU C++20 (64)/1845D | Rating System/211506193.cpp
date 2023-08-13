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
 
void solve() {
    int N;
    cin >> N;
    VE<LL> A(N);
    F0R(i, N) {
        cin >> A[i];
    }
    VE<LL> pref(N + 1);
    F0R(i, N) {
        pref[i + 1] = pref[i] + A[i];
    }
    LL suf = 0, mx = 0, best = 0;
    LL ans = 0;
    RF0R(i, N) {
        suf += A[i];
        mx = max(mx, suf);
        if (pref[i] + mx > best) {
            best = pref[i] + mx;
            ans = pref[i];
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