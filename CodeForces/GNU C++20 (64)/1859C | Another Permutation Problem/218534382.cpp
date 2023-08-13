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
    int ans = 0;
    for (int i = 1; i <= n; i++) { // put i at position j, let it be the max product
        for (int j = 1; j <= n; j++) {
            const int mx_v = i * j;
            int cur_ans = 0;
 
            set<int> rem;
            for (int k = 1; k <= n; k++) {
                if (k != i) {
                    rem.insert(k);
                }
            }
 
            bool ok = true;
            for (int k = n; k >= 1; k--) {
                if (k != j) {
                    auto ub = rem.upper_bound(mx_v / k);
                    if (ub == rem.begin()) {
                        ok = false;
                        break;
                    }
                    ub = prev(ub);
                    cur_ans += k * (*ub);
                    rem.erase(ub);
                }
            }
 
            if (ok) {
                ans = max(ans, cur_ans);
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
 
/*
*/