#include "bits/stdc++.h"
using namespace std;
 
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define F0R(i, N) FOR(i, 0, N)
#define RFOR(i, a, b) for (int i = b - 1; i >= a; i--)
#define RF0R(i, n) RFOR(i, 0, n)
#define REP(n) F0R(_, n)
 
#define int long long
#define ve vector
#define ar array
 
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
 
template<class T> bool ckmin(T &a, T b) {
    return b < a ? a = b, 1 : 0;
}
template<class T> bool ckmax(T &a, T b) {
    return b > a ? a = b, 1 : 0;
}
 
// let X be the amount of cycles of 2, 4, 8, 6 to go through from some state (s, k)
 
// the total discount (which we want to maximize) is:
// (s + 20X) * (k - 4X)
// SK - 4SX + 20KX - 80X^2
// -80X^2 + (20K - 4S)X + SK
 
// the vertex V of the parabola is at -B / 2A
// V.x = (4S - 16K) / (-160)
 
// find, plug in, and ckmax the ceil and floor of this
 
void solve() {
    int s, k;
    cin >> s >> k;
    int ans = s * k;
    if (s % 10 == 5) {
        ans = max(ans, (s + 5) * (k - 1));
    } else if (s % 10) {
        if (s % 2) {
            s += s % 10;
            k--;
        }
        F0R(i, 4) {
            auto try_x = [&](int x) {
                ckmax(x, 0ll);
                return (s + 20 * x) * (k - 4 * x);
            };
            auto get_best = [&]() {
                int flr = (4 * s - 20 * k) / -160;
                int ceil = (4 * s - 20 * k - 159) / -160;
                return max(try_x(flr), try_x(ceil));
            };
 
            ans = max(ans, get_best());
 
            s += s % 10;
            k--;
        }
    }
    cout << ans << '\n';
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    REP(t) {
        solve();
    }
}
 
// Read the statement carefully, take your time
// Don't be intimidated, the solution is probably simpler than you think
// CM soon :pray: