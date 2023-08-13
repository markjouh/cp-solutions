#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "debug.h"
#else
#define dbg(x...)
#endif
 
typedef long long ll;
 
#define sz(x) static_cast<int>(size(x))
#define all(x) begin(x), end(x)
 
void solve() {
    int n;
    cin >> n;
    map<int, ll> freq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }
    int q;
    cin >> q;
    while (q--) {
        ll x, y;
        cin >> x >> y;
 
        // ll lo = -2e9, hi = x / 2 + 1;
        // while (lo + 1 < hi) {
        //     ll mid = lo + (hi - lo) / 2;
        //     (mid * (x - mid) <= y ? lo : hi) = mid;
        // }
 
        ll ans = -2e9;
        for (ll i = 1ll << 32; i != 0; i >>= 1) {
            if (ans + i <= x - ans - i && (ans + i) * (x - ans - i) <= y) {
                ans += i;
            }
        }
 
        if (ans * (x - ans) != y) {
            cout << 0 << ' ';
            continue;
        }
 
        if (ans == x - ans) {
            cout << freq[ans] * (freq[ans] - 1) / 2 << ' ';
        } else {
            cout << freq[ans] * freq[x - ans] << ' ';
        }
    }
    cout << '\n';
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