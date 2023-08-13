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
 
// just testing to see how much faster this is
int qmod(int x, const int &MOD) {
    return x < MOD ? x : x - MOD;
}
 
void solve() {
    int n, d;
    cin >> n >> d;
    vector<bool> a(n);
    for (int i = 0; i < n; i++) {
        bool b;
        cin >> b;
        a[i] = b;
    }
    vector<bool> vis(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            int u = i;
            vector<bool> cycle;
            while (!vis[u]) {
                vis[u] = true;
                cycle.push_back(a[u]);
                u = qmod(u + d, n);
            }
 
            const int m = sz(cycle);
            int running = 0, longest = 0;
            for (int j = 0; j < 2 * m; j++) {
                running = cycle[qmod(j, m)] ? running + 1 : 0;
                longest = max(longest, running);
            }
 
            ans = max(ans, longest == 2 * m ? INF : longest);
        }
    }
    cout << (ans == INF ? -1 : ans) << '\n';
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
 
I think we do smth with jumps of d
a_0 after 0 shifts is a_0
a_0 after 1 shift is a_0 & a_-d
a_0 after 2 shifts is a_0 & a_-d & a_-2d
...
 
a_0 stops changing after a finite number of moves
Either it becomes 0, or it visits everything in its cycle
 
Just construct the cycles and find the longest subarray of contiguous 1's
 
*/