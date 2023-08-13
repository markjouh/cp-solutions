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
    vector<int> a(n);
    unordered_map<ll, ll> freq;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
 
    }
    sort(all(a));
    a.resize(unique(all(a)) - a.begin());
    ll ans = 0;
    for (ll i : a) {
        if (freq[i] > 2) {
            ans += freq[i] * (freq[i] - 1) * (freq[i] - 2);
        }
 
        vector<int> factors;
        for (ll j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                factors.push_back(j);
                if (j * j != i) {
                    factors.push_back(i / j);
                }
            }
        }
        factors.erase(find(all(factors), i));
 
        for (ll f : factors) {
            if (freq.count(f) && freq.count(i * (i / f))) {
                ans += freq[f] * freq[i] * freq[i * (i / f)];
            }
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