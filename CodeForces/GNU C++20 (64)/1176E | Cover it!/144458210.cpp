#include <bits/stdc++.h>
using namespace std;
 
int main() {
#ifdef LOCAL
  freopen("input.in", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    vector<int> g[n + 1];
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    bool par[n + 1]{}, seen[n + 1]{};
    while (q.size()) {
      int u = q.front();
      q.pop();
      seen[u] = true;
      for (int v : g[u]) {
        if (!seen[v]) {
          q.push(v);
          par[v] = 1 - par[u];
        }
      }
    }
    vector<int> res[2];
    for (int i = 1; i <= n; i++) {
      res[par[i]].push_back(i);
    }
    if (res[0].size() > res[1].size()) {
      swap(res[0], res[1]);
    }
    cout << res[0].size() << '\n';
    for (int x : res[0]) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}