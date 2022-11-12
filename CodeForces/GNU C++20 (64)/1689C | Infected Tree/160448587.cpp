#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    queue<int> q;
    vector<int> dep(n, 1e9);
    q.push(0);
    dep[0] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : g[u]) {
        if (dep[v] == 1e9) {
          q.push(v);
          dep[v] = dep[u] + 1;
        }
      }
    }
    vector<int> par(n);
    for (int i = 1; i < n; i++) {
      for (int v : g[i]) {
        if (dep[v] < dep[i]) {
          par[i] = v;
          break;
        }
      }
    }
    vector<int> ord(n) ;
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {
      return dep[i] < dep[j];
    });
    vector<int> children(n);
    children[0] = g[0].size();
    for (int i = 1; i < n; i++) {
      children[i] = g[i].size() - 1;
    }
    vector<int> cost(n);
    cost[0] = 1;
    for (int i = 1; i < n; i++) {
      cost[ord[i]] = children[par[ord[i]]] + cost[par[ord[i]]];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (children[i] == 0) {
        ans = max(ans, n - cost[i]);
      }
      if (children[i] == 1) {
        ans = max(ans, n - cost[i] - 1);
      }
    }
    cout << ans << '\n';
  }
}