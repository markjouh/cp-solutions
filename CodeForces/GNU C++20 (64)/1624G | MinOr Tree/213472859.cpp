#include "bits/stdc++.h"
 
using namespace std;
 
constexpr int MXN = 2e5;
array<int, MXN> par, sz;
 
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
    vector<bool> on(30, true);
    for (int i = 29; i >= 0; i--) {
      on[i] = false;
      fill(par.begin(), par.begin() + n, -1);
      fill(sz.begin(), sz.begin() + n, 1);
      for (auto [u, v, w] : edges) {
        bool ok = true;
        for (int j = 0; j < 30; j++) {
          ok &= ((w >> j) & 1) <= on[j];
        }
        if (ok) {
          unite(u, v);
        }
      }
      int comps = 0;
      for (int j = 0; j < n; j++) {
        comps += get_root(j) == j;
      }
      if (comps > 1) {
        on[i] = true;
      }
    }
    int ans = 0;
    for (int i = 0; i < 30; i++) {
      ans += (1 << i) * on[i];
    }
    cout << ans << '\n';
  }
}