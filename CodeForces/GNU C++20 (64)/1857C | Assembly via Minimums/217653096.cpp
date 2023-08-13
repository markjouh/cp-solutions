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
    const int m = n * (n - 1) / 2;
 
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(all(b));
    reverse(all(b));
 
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (i < n - 1) {
            ans.push_back(b.back());
        }
        for (int j = 0; j < n - i - 1; j++) {
            b.pop_back();
        }
    }
    ans.push_back(1e9);
 
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
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