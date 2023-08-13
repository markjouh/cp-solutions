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
 
vector<int> p, h;
vector<vector<int>> g;
 
bool ok;
vector<int> total, happy;
 
void dfs(int u, int par) {
    int children_happy = 0;
    for (int v : g[u]) {
        if (v != par) {
            dfs(v, u);
            total[u] += total[v];
            children_happy += happy[v];
        }
    }
 
    happy[u] = (total[u] + h[u]) / 2;
 
    ok &= (total[u] + h[u]) % 2 == 0;
    ok &= happy[u] <= total[u];
    ok &= children_happy <= happy[u];
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    p = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    h = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    g = vector<vector<int>>(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    ok = true;
    total = p;
    happy = vector<int>(n);
    dfs(0, -1);
 
    cout << (ok ? "YES\n" : "NO\n");
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
 
The number of people who will be scanned by the i'th detector is equal to the number of people living in the subtree of i.
Let a be the number of happy people that visit a city, and b unhappy
(a + b) + (a - b) = 2a
a = ((a + b) + (a - b)) / 2
 
*/