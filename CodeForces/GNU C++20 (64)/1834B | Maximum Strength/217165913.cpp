#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using pii = pair<int, int>;
 
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define F0R(i, n) FOR(i, 0, n)
#define RFOR(i, a, b) for (int i = (int)b - 1; i >= a; i--)
#define RF0R(i, n) RFOR(i, 0, n)
 
#define sz(x) static_cast<int>((x).size())
#define all(x) (x).begin(), (x).end()
 
template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
 
constexpr int MOD = 1e9 + 7; // 998244353;
constexpr int INF = INT_MAX / 2;
constexpr ll BIG = LLONG_MAX / 2;
 
void solve() {
    string a, b;
    cin >> a >> b;
    a = string(sz(b) - sz(a), '0') + a;
    int ans = 0;
    bool flag = false;
    F0R(i, sz(a)) {
        if (flag) {
            ans += 9;
        } else if (a[i] != b[i]) {
            ans += abs(a[i] - b[i]);
            flag = true;
        }
    }
    cout << ans << '\n';
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}