#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
 
template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }
 
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> ht(n);
  for (int i = 0; i < n; i++) {
    cin >> ht[i];
  }
 
  vector<int> dst = ht;
  sort(all(dst));
  dst.resize(unique(all(dst)) - dst.begin());
  for (int i = 0; i < n; i++) {
    ht[i] = lower_bound(all(dst), ht[i]) - dst.begin();
  }
 
  vector<vector<pii>> add_e(sz(dst));
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    add_e[max(ht[u], ht[v])].push_back({u, v});
  }
 
  int q;
  cin >> q;
  vector<array<int, 3>> quer(q);
  for (auto &[u, v, e] : quer) {
    cin >> u >> v >> e;
    u--; v--;
  }
  vector<vector<pii>> chk(n);
  for (int i = 0; i < q; i++) {
    chk[quer[i][0]].push_back({quer[i][1], i});
    chk[quer[i][1]].push_back({quer[i][0], i});
  }
 
  vector<int> root(n);
  vector<vector<int>> cont(n);
  for (int i = 0; i < n; i++) {
    root[i] = i;
    cont[i] = {i};
  }
 
  vector<int> mn_conn(q, INT_MAX);
  for (int i = 0; i < q; i++) {
    if (quer[i][0] == quer[i][1]) {
      mn_conn[i] = 0;
    }
  }
  for (int i = 0; i < sz(dst); i++) {
    for (auto [a, b] : add_e[i]) {
      a = root[a];
      b = root[b];
      if (a == b) {
        continue;
      }
      if (sz(cont[a]) < sz(cont[b])) {
        swap(a, b);
      }
      for (int x : cont[b]) {
        root[x] = a;
        cont[a].push_back(x);
 
        for (auto [v, idx] : chk[x]) {
          if (root[v] == root[x]) {
            ckmin(mn_conn[idx], dst[i]);
          }
        }
      }
      cont[b].clear();
    }
  }
 
  // cout << "DEBUG " << quer[0][0] << ' ' << ht[0] << '\n';
 
  for (int i = 0; i < q; i++) {
    // cout << dst[quer[i][0]] << ' ' << quer[i][2] << ' ' << mn_conn[i] << '\n';
    cout << (dst[ht[quer[i][0]]] + quer[i][2] >= mn_conn[i] ? "YES\n" : "NO\n");
  }
  cout << '\n';
}
 
int main() {
#ifndef ONLINE_JUDGE
  freopen("a.in", "r", stdin);
#endif
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t = 1;
  cin >> t;
  while (t--) {
  solve();
  }
  return 0;
}