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
 
constexpr int INF = INT_MAX / 2;
 
void solve() {
    int mx_y = -INF, mn_x = INF, mx_x = -INF;
    for (int i = 0; i < 3; i++) {
        int x, y;
        cin >> x >> y;
        if (y > mx_y) {
            mx_y = y;
            mn_x = INF;
            mx_x = -INF;
        }
        if (y == mx_y) {
            mn_x = min(mn_x, x);
            mx_x = max(mx_x, x);
        }
    }
    cout << mx_x - mn_x << '\n';
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