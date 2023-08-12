#include "bits/stdc++.h"

using namespace std;

#define int long long

// what does the special operation in this problem do?
// all it does is add the condition that, we can only return to a vertex if we have moved an odd distance since our last visit
// this means that we should find an odd cycle
// each edge in this cycle should be between two vertices with differing colors, except for one (we return to the start through this edge)
// how do we find this?

// find two vertices of the same color u, v connected by an edge
// build a graph with only edges between different colors
// there is an odd cycle that fufills the above constraints if u and v are connected in the graph

// oops, I forgot that the path between u and v in g needs to be of even length
// wait, actually since u and v are of the same color all paths must neccessarily be of even length
// then idk what the issue is

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> e(m);
  for (auto &[u, v] : e) {
    cin >> u >> v;
    u--; v--;
  }
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  vector<vector<int>> g(n);
  vector<pair<int, int>> same;
  for (auto [u, v] : e) {
    if (c[u] != c[v]) {
      g[u].push_back(v);
      g[v].push_back(u);
    } else {
      same.push_back({u, v});
    }
  }
  vector<int> comp(n, -1);
  int cur = 0;
  for (int i = 0; i < n; i++) {
    if (comp[i] == -1) {
      queue<int> q;
      q.push(i);
      comp[i] = cur++;
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
          if (comp[v] == -1) {
            comp[v] = comp[u];
            q.push(v);
          }
        }
      }
    }
  }
  bool ok = false;
  for (auto [u, v] : same) {
    if (comp[u] == comp[v]) {
      ok = true;
      break;
    }
  }
  cout << (ok ? "Yes\n" : "No\n");
}
 