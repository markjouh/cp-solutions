#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 1;
 
int n, m;
int type[N];
vector<pair<int, int>> g[N];
 
bool ok;
int ct[2];
 
void dfs(int id) {
 ++ct[type[id]];
 for (auto p : g[id]) {
  if (type[p.first] == -1) {
   type[p.first] = type[id] ^ p.second;
   dfs(p.first);
  } else if (type[p.first] != type[id] ^ p.second) {
   ok = false;
  }
 }
}
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  cin >> n >> m;
  memset(type, -1, sizeof type);
  for (int i = 1; i <= n; ++i) {
   g[i].clear();
  }
  for (int i = 0; i < m; ++i) {
   int u, v;
   string s;
   cin >> u >> v >> s;
   bool ctype = s == "imposter";
   g[u].push_back({v, ctype});
   g[v].push_back({u, ctype});
  }
  ok = true;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
   if (type[i] == -1) {
    ct[0] = ct[1] = 0;
    type[i] = 0;
    dfs(i);
    ans += max(ct[0], ct[1]);
   }
  }
  cout << (ok ? ans : -1) << '\n';
 }
}