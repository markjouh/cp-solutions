#include "bits/stdc++.h"
 
using namespace std;
 
#define int int64_t
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    string s_bg;
    cin >> s_bg;
    int bg = 0;
    for (int i = 0; i < n; i++) {
      bg += (1 << i) * (s_bg[i] - '0');
    }
    vector<vector<pair<int, int>>> g(1 << n);
    while (m--) {
      int d;
      string s_rem, s_add;
      cin >> d >> s_rem >> s_add;
      int rem = 0, add = 0;
      for (int i = 0; i < n; i++) {
        rem += (1 << i) * (s_rem[i] - '0');
        add += (1 << i) * (s_add[i] - '0');
      }
      for (int i = 0; i < (1 << n); i++) {
        int v = (i & (~rem)) | add;
        g[i].push_back({v, d});
      }
    }
    set<pair<int, int>> q;
    q.insert({0, bg});
    vector<int> dist(1 << n, 1e9);
    dist[bg] = 0;
    while (!q.empty()) {
      int u = q.begin()->second;
      q.erase(q.begin());
      for (auto [v, w] : g[u]) {
        if (dist[u] + w < dist[v]) {
          dist[v] = dist[u] + w;
          q.insert({dist[v], v});
        }
      }
    }
    cout << (dist[0] == 1e9 ? -1 : dist[0]) << '\n';
  }
}