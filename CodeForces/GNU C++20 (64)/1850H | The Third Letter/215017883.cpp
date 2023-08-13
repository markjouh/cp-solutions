#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
 
template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }
 
constexpr ll INF = 1e18;
 
vector<vector<pii>> g;
vector<ll> d;
 
void dfs(int u) {
  for (auto [v, w] : g[u]) {
    if (d[v] == INF) {
      d[v] = d[u] + w;
      dfs(v);
    }
  }
}
 
void solve() {
  int n, m;
  cin >> n >> m;
  g = vector<vector<pii>>(n);
  for (int i = 0; i < m; i++) {
    int a, b, d;
    cin >> a >> b >> d;
    a--; b--;
    g[b].push_back({a, d});
    g[a].push_back({b, -d});
  }
  d = vector<ll>(n, INF);
  for (int i = 0; i < n; i++) {
    if (d[i] == INF) {
      d[i] = 0;
      dfs(i);
    }
  }
  bool ok = true;
  for (int u = 0; u < n; u++) {
    for (auto [v, w] : g[u]) {
      ok &= d[v] == d[u] + w;
    }
  }
  cout << (ok ? "YES\n" : "NO\n");
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    #ifndef ONLINE_JUDGE
      cout << string(32, '_') << endl;
    #endif
    solve();
  }
  return 0;
}
 