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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));
 
    int cnt_mx = count(all(a), a[n - 1]);
    if (cnt_mx == n) {
        cout << -1 << '\n';
    } else {
        cout << n - cnt_mx << ' ' << cnt_mx << '\n';
        for (int i = 0; i < n - cnt_mx; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
        for (int i = n - 1; i >= n - cnt_mx; i--) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
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