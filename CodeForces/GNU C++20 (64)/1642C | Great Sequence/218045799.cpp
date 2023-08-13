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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));
 
    map<int, int> mp;
    int pairs = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % x == 0 && mp[a[i] / x] > 0) {
            mp[a[i] / x]--;
            pairs++;
        } else {
            mp[a[i]]++;
        }
    }
 
    cout << n - 2 * pairs << '\n';
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
 
Can we just greedily form pairs or something?
 
*/