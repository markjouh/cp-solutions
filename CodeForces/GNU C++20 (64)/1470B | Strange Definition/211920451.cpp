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
 
VE<int> mn_fac;
 
void solve() {
    int N;
    cin >> N;
    map<VE<int>, int> cnt;
    REP(N) {
        int x;
        cin >> x;
        VE<int> odd_exp;
        while (x > 1) {
            int f = mn_fac[x], exp = 0;
            while (x % f == 0) {
                x /= f;
                exp++;
            }
            if (exp % 2) {
                odd_exp.push_back(f);
            }
        }
        sort(ALL(odd_exp));
        cnt[odd_exp]++;
    }
    int mx = 0, perfect = 0;
    for (auto [k, v] : cnt) {
        mx = max(mx, v);
        if (k.empty() || v % 2 == 0) {
            perfect += v;
        }
    }
    int Q;
    cin >> Q;
    REP(Q) {
        LL W;
        cin >> W;
        if (W == 0) {
            cout << mx << '\n';
        } else {
            cout << max(mx, perfect) << '\n';
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    const int N = 1e6;
    mn_fac.resize(N + 1, -1);
    for (LL i = 2; i <= N; i++) {
        if (mn_fac[i] == -1) {
            mn_fac[i] = i;
            for (LL j = i * i; j <= N; j += i) {
                mn_fac[j] = i;
            }
        }
    }
 
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}
 
// Read the statement carefully, take your time
// Don't be intimidated, the solution is probably simpler than you think
// CM soon :pray: