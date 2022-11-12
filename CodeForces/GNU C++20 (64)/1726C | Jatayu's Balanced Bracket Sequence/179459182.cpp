#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    s += ')';
    vector<vector<int>> lev(n + 1);
    vector<vector<int>> g(n * 2);
    int c_lev = 0;
    for (int i = 0; i < n * 2 + 1; i++) {
      if (s[i] == '(') {
        lev[c_lev].push_back(i);
        c_lev++;
      } else {
        for (int j = 0; j < (int)lev[c_lev].size() - 1; j++) {
          g[lev[c_lev][j]].push_back(lev[c_lev][j + 1]);
        }
        lev[c_lev].clear();
        c_lev--;
        if (c_lev != -1) {
          lev[c_lev].push_back(i);
        }
      } 
    }
    int cnt = 0;
    vector<int> comp(n * 2, -1);
    queue<int> q;
    for (int i = 0; i < n * 2; i++) {
      if (comp[i] == -1) {
        q.push(i);
        comp[i] = cnt++;
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
    // for (int u = 0; u < n * 2; u++) {
    //   for (int v : g[u]) {
    //     cout << u << ' ' << v << '\n';
    //   }
    // }
    cout << cnt << '\n';
  }
}