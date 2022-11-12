#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    vector<int> color(n+1, -1); // -1 = unoccupied, 0 = enemy, 1 = player
    queue<int> q;
    for (int i = 0; i < k; i++) {
      int x;
      cin >> x;
      color[x] = 0;
      q.push(x);
    }
    vector<vector<int>> g(n+1);
    for (int i = 0; i < n-1; i++) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    color[1] = 1;
    q.push(1);
    while (q.size()) {
      int u = q.front();
      q.pop();
      for (int v : g[u]) {
        if (color[v] == -1) {
          color[v] = color[u];
          q.push(v);
        }
      }
    }
    bool ok = false;
    for (int i = 2; i <= n; i++) {
      ok |= g[i].size() == 1 && color[i] == 1;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}
 
/*
  Read the problem statement carefully
  Think about the problem in different ways
*/