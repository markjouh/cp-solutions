#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  long long k;
  cin >> n >> m >> k;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
  }
  int l = 0, r = 1e9 + 1;
  while (l + 1 < r) {
    int mid = l + (r - l) / 2;
    int cnt = 0;
    vector<vector<int>> g2(n);
    vector<int> in(n);
    for (int u = 0; u < n; u++) {
      if (a[u] <= mid) {
        cnt++;
        for (int v : g[u]) {
          if (a[v] <= mid) {
            g2[u].push_back(v);
            in[v]++;
          }
        }
      }
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
      if (a[i] <= mid && in[i] == 0) {
        q.push(i);
      }
    }
    vector<int> t;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      t.push_back(u);
      for (int v : g2[u]) {
        if (--in[v] == 0) {
          q.push(v);
        }
      }
    }
    if ((int)t.size() < cnt) {
      r = mid;
    } else {
      int mx = 0;
      vector<int> dp(n, 1);
      for (int u : t) {
        for (int v : g2[u]) {
          dp[v] = max(dp[v], dp[u] + 1);
        }
        mx = max(mx, dp[u]);
      }
      (mx >= k ? r : l) = mid;
    }
  }
  cout << (r == 1e9 + 1 ? -1 : r) << '\n';
}