#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
 
template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }
 
void solve() {
  int n, k;
  cin >> n >> k;
  vector<ll> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < k; i++) {
    int p;
    cin >> p;
    p--;
    c[p] = 0;
  }
  vector<vector<int>> g(n);
  vector<int> in(n);
  for (int u = 0; u < n; u++) {
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
      int v;
      cin >> v;
      v--;
      g[u].push_back(v);
      in[v]++;
    }
  }
 
  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (in[i] == 0) {
      q.push(i);
    }
  }
  vector<int> ord;
  while (sz(q)) {
    int u = q.front();
    q.pop();
    ord.push_back(u);
    for (int v : g[u]) {
      if (--in[v] == 0) {
        q.push(v);
      }
    }
  }
  reverse(all(ord));
 
  vector<ll> ans(n);
  for (int u : ord) {
    if (sz(g[u]) == 0) {
      ans[u] = c[u];
      continue;
    }
    for (int v : g[u]) {
      ans[u] += ans[v];
    }
    ckmin(ans[u], c[u]);
  }
 
  for (int i = 0; i < n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}