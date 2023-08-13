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
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
template <typename T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
vector<vector<array<int, 3>>> g;
vector<ll> pref_a, pref_b, ans;
 
indexed_set<ll> on_path;
 
void dfs(int u) {
    on_path.insert(pref_b[u]);
    ans[u] = on_path.order_of_key(pref_a[u] + 1);
 
    for (auto [v, a, b] : g[u]) {
        pref_a[v] = pref_a[u] + a;
        pref_b[v] = pref_b[u] + b;
        dfs(v);
    }
 
    on_path.erase(pref_b[u]);
}
 
void solve() {
    int n;
    cin >> n;
    g = vector<vector<array<int, 3>>>(n);
    for (int i = 1; i < n; i++) {
        int p, a, b;
        cin >> p >> a >> b;
        g[--p].push_back({i, a, b});
    }
    pref_a = pref_b = ans = vector<ll>(n);
 
    dfs(0);
 
    for (int i = 1; i < n; i++) {
        cout << ans[i] - 1 << ' ';
    }
    cout << '\n';
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
 
Let A_i be the sum of all a on the path from 1 to i, and B_i be the sum of all b from 1 to i
Just dfs from the root, the answer for the current vertex is the number of B_i on the path <= A_i
We can query this using an indexed set
 
*/