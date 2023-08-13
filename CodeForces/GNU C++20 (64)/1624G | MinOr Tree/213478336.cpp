#include "bits/stdc++.h"
 
using namespace std;
 
constexpr int MXN = 2e5;
int par[MXN], sz[MXN];
int comps;
 
int get_root(int u) {
  if (par[u] == -1) {
    return u;
  }
  return par[u] = get_root(par[u]);
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
  comps--;
}
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edges(m);
    for (auto &[u, v, w] : edges) {
      cin >> u >> v >> w;
      u--; v--;
    }
    int ans = INT_MAX - (1 << 30);
    for (int i = 29; i >= 0; i--) {
      ans ^= (1 << i);
      fill(par, par + n, -1);
      fill(sz, sz + n, 1);
      comps = n;
      for (auto [u, v, w] : edges) {
        if (ans == (ans | w)) {
          unite(u, v);
        }
      }
      if (comps > 1) {
        ans ^= (1 << i);
      }
    }
    cout << ans << '\n';
  }
}