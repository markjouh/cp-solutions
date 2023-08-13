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
    vector<vector<int>> g(n);
    vector<int> in_deg(n);
    for (int v = 1; v < n; v++) {
        int p;
        cin >> p;
        p--;
        g[p].push_back(v);
        in_deg[v]++;
    }
 
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in_deg[i] == 0) {
            q.push(i);
        }
    }
    vector<int> topsort;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topsort.push_back(u);
        for (int v : g[u]) {
            if (--in_deg[v] == 0) {
                q.push(v);
            }
        }
    }
    reverse(all(topsort));
 
    vector<int> subtree_sz(n, 1);
    int ans = 0;
    for (int u : topsort) {
        vector<int> children_sz;
        for (int v : g[u]) {
            children_sz.push_back(subtree_sz[v]);
            subtree_sz[u] += subtree_sz[v];
        }
 
        vector<bool> formable(n + 1);
        formable[0] = true;
        for (int x : children_sz) {
            for (int i = n - x; i >= 0; i--) {
                if (formable[i]) {
                    formable[i + x] = true;
                }
            }
        }
 
        int best = 0;
        for (int i = 0; i <= n; i++) {
            if (formable[i]) {
                best = max(best, i * (subtree_sz[u] - 1 - i));
            }
        }
        ans += best;
        dbg(u + 1, children_sz, best);
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