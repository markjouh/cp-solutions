#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    string s;
    cin >> n >> s;
    vector<int> g(n);
    for (int i = 0; i < n; i++) {
      cin >> g[i];
      g[i]--;
    }
    long long ans = 1;
    vector<bool> vis(n);
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        int u = i;
        string comp;
        comp += s[u];
        vis[u] = true;
        while (!vis[g[u]]) {
          u = g[u];
          comp += s[u];
          vis[u] = true;
        }
        // number of shifts needed for a full rotation
        int m = comp.size(), mn = m;
        for (int j = 1; j < m; j++) {
          if (m % j == 0) {
            bool ok = true;
            for (int k = 0; k < m; k++) {
              ok &= comp[k] == comp[(k + j) % m];
            }
            if (ok) {
              mn = j;
              break;
            }
          }
          
        }
        ans = lcm(ans, mn);
      }
    }
    cout << ans << '\n';
  }
}