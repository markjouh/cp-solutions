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
 
void solve() {
    int n;
    cin >> n;
    vector<int> sec(n);
    ll sum_sec = 0, mn = 1e9;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        vector<ll> a(m);
        for (int j = 0; j < m; j++) {
            cin >> a[j];
        }
        sort(all(a));
        sec[i] = a[1];
        sum_sec += a[1];
        mn = min(mn, a[0]);
    }
 
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, sum_sec - sec[i] + mn);
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
 
/*
*/