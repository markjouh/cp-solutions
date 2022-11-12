#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define FOR(i, n) for (int i = 0; i < (int)n; i++)
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> g(n);
    FOR(i, n-1) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      g[u].push_back({v, i});
      g[v].push_back({u, i});
    }
    bool ok = true;
    FOR(i, n) {
      ok &= g[i].size() < 3;
    }
    if (!ok) {
      cout << -1 << '\n';
      continue;
    }
    int leaf = 0;
    FOR(i, n) {
      if (g[i].size() == 1) {
        leaf = i;
        break;
      }
    }
    queue<int> q;
    vector<int> res(n-1);
    q.push(leaf);
    
    int curnode = leaf, lastnode = -1, lastedge = 3;
    FOR(i, n-1) {
      for (auto [f, s] : g[curnode]) {
        if (f != lastnode) {
          res[s] = 5-lastedge;
          lastedge = res[s];
          lastnode = curnode;
          curnode = f;
          break;
        }
      }
    }
 
    FOR(i, n-1) {
      cout << res[i] << ' ';
    }
    cout << '\n';
  }
}
 
/*
  Read the problem statement carefully
  Think about the problem in different ways
*/