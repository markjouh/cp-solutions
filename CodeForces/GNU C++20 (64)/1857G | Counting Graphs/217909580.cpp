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
 
constexpr int MOD = 998244353;
 
ll bin_exp(ll base, ll exp) {
    ll res = 1;
    while (exp) {
        if (exp & 1) {
            res = res * base % MOD;
        }
        base = base * base % MOD;
        exp >>= 1;
    }
    return res;
}
 
vector<int> par;
vector<ll> sz;
 
int get_root(int u) {
    return par[u] == -1 ? u : par[u] = get_root(par[u]);
}
 
void unite(int a, int b) {
    a = get_root(a);
    b = get_root(b);
    if (a == b) {
        return;
    }
    if (sz[a] < sz[b]) {
        swap(a, b);
    }
    par[b] = a;
    sz[a] += sz[b];
}
 
void solve() {
    int n, s;
    cin >> n >> s;
    vector<array<int, 3>> edges(n - 1);
    for (auto &[w, u, v] : edges) {
        cin >> u >> v >> w;
        u--; v--;
    }
    sort(all(edges));
    dbg(edges);
 
    par = vector<int>(n, -1);
    sz = vector<ll>(n, 1);
 
    ll ans = 1;
    for (auto [w, u, v] : edges) {
        u = get_root(u);
        v = get_root(v);
        ans = ans * bin_exp(s - w + 1, sz[u] * sz[v] - 1) % MOD;
        unite(u, v);
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