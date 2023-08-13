#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
using namespace std;
 
using LL = long long;
using PII = pair<int, int>;
template<class T> using VE = vector<T>;
template<class T, size_t SZ> using AR = array<T, SZ>;
 
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
 
template<typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
void solve() {
    int N, M;
    cin >> N >> M;
    VE<PII> ranges(M);
    F0R(i, M) {
        cin >> ranges[i].F >> ranges[i].S;
        ranges[i].F--;
        ranges[i].S--;
    }
    int Q;
    cin >> Q;
    VE<int> changes(Q);
    F0R(i, Q) {
        cin >> changes[i];
        changes[i]--;
    }
    int lo = -1, hi = Q + 1;
    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        VE<int> apply;
        F0R(i, mid) {
            apply.push_back(changes[i]);
        }
        sort(ALL(apply));
        bool ok = false;
        F0R(i, M) {
            const int l = ranges[i].F, r = ranges[i].S;
            const int lb = lower_bound(ALL(apply), l) - apply.begin();
            const int ub = upper_bound(ALL(apply), r) - apply.begin();
            if ((ub - lb) * 2 > r - l + 1) {
                ok = true;
                break;
            }
        }
        (ok ? hi : lo) = mid;
    }
    cout << (hi == Q + 1 ? -1 : hi) << '\n';
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