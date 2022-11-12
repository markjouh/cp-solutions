#include <bits/stdc++.h>
using namespace std;
 
const int mxn = 2e5 + 1;
 
bool bipartite;
 
vector<int> g[mxn][2];
int color[mxn];
int ct[3];
 
void dfs(int u, int c) {
  color[u] = c;
  ct[c]++;
  for (int v : g[u][0]) {
    if (color[v]) {
      bipartite &= color[v] == c;
    } else {
      dfs(v, c);
    }
  }
  for (int v : g[u][1]) {
    if (color[v]) {
      bipartite &= color[v] != c;
    } else {
      dfs(v, 3 - c);
    }
  }
}
 
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
    bipartite = true;
    for (int i = 1; i <= n; i++) {
      g[i][0].clear();
      g[i][1].clear();
    }
    fill(color, color + n + 1, 0);
    for (int i = 0; i < m; i++) {
      int u, v;
      string s;
      cin >> u >> v >> s;
      bool t = s == "imposter";
      g[u][t].push_back(v);
      g[v][t].push_back(u);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (!color[i]) {
        ct[1] = 0;
        ct[2] = 0;
        dfs(i, 1);
        ans += max(ct[1], ct[2]);
      }
    }
    cout << (bipartite ? ans : -1) << '\n';
  }
}