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
    int ans = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            bool b;
            cin >> b;
            if (b) {
                ans = abs(2 - i) + abs(2 - j);
            }
        }
    }
    cout << ans << '\n';
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}
 
/*
*/