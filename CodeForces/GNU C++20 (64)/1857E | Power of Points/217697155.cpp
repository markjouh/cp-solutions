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
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(all(p));
 
    vector<ll> pref(n);
    for (ll i = 1; i < n; i++) {
        pref[p[i].second] = pref[p[i - 1].second] + i * (p[i].first - p[i - 1].first);
    }
    vector<ll> suff(n);
    for (ll i = n - 2; i >= 0; i--) {
        suff[p[i].second] = suff[p[i + 1].second] + (n - i - 1) * (p[i + 1].first - p[i].first);
    }
 
    for (int i = 0; i < n; i++) {
        cout << pref[i] + suff[i] + n << ' ';
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