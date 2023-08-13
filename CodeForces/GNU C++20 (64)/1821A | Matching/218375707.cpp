#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "debug.h"
#else
#define dbg(x...)
#endif
 
using ll = long long;
 
#define sz(x) static_cast<int>(size(x))
#define all(x) begin(x), end(x)
 
template <class T> bool ckmin(T &a, const T b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T &a, const T b) { return a < b ? a = b, 1 : 0; }
 
constexpr array<int, 6> P = {1, 10, 100, 1000, 10000, 100000};
 
void solve() {
    string s;
    cin >> s;
 
    if (s[0] == '0') {
        cout << 0 << '\n';
        return;
    }
    
    int ans = 1;
    for (int i = 0; i < sz(s); i++) {
        if (s[i] == '?') {
            ans *= (i == 0 ? 9 : 10);
        }
    }
    cout << ans << '\n';
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}