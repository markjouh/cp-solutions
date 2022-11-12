#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int u = 0; u < n; u++) {
    int v;
    cin >> v;
    g[u].push_back(v - 1);
  }
  for (int u = 1; u < n; u++) {
    g[u].push_back(u - 1);
  }
  for (int u = 0; u < n - 1; u++) {
    g[u].push_back(u + 1);
  }
  queue<int> q;
  q.push(0);
  vector<bool> vis(n);
  vector<int> ans(n);
  vis[0] = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : g[u]) {
      if (!vis[v]) {
        q.push(v);
        vis[v] = true;
        ans[v] = ans[u] + 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << ' ';
  }
}