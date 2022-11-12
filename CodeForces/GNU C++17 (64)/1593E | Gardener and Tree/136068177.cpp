#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> g(n);
  vector<int> deg(n);
  for (int i = 0; i < n - 1; ++i) {
   int u, v;
   cin >> u >> v;
   --u; --v;
   g[u].push_back(v);
   g[v].push_back(u);
   ++deg[u];
   ++deg[v];
  }
  queue<int> q;
  for (int i = 0; i < n; ++i) {
   if (deg[i] == 1) {
    q.push(i);
   }
  }
  vector<int> dep(n, 1);
  while (q.size()) {
   int u = q.front();
   for (int& v : g[u]) {
    if (--deg[v] == 1) {
     q.push(v);
     dep[v] = dep[u] + 1;
    }
   }
   q.pop();
  }
  int ans = 0;
  for (int x : dep) {
   ans += x > k;
  }
  cout << ans << '\n';
 }
}