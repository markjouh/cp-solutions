#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz(x) int(size(x))
#define all(x) begin(x), end(x)
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  string s1, s2;
  cin >> n >> s1 >> s2;
  vector<vector<int>> g(26, vector<int>(26));
  for (int i = 0; i < n; i++) {
    if (s1[i] != s2[i]) {
      g[s1[i] - 'a'].push_back(s2[i] - 'a');
      g[s2[i] - 'a'].push_back(s1[i] - 'a');
    }
  }
  vector<pair<int, int>> res;
  vector<bool> vis(26);
  for (int i = 0; i < 26; i++) {
    if (!vis[i]) {
      vector<int> vert;
      queue<int> q;
      q.push(i);
      vis[i] = true;
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        vert.push_back(u);
        for (int v : g[u]) {
          if (!vis[v]) {
            q.push(v);
            vis[v] = true;
          }
        }
      }
      for (int j = 0; j < sz(vert) - 1; j++) {
        res.push_back({vert[j], vert[j + 1]});
      }
    }
  }
  cout << sz(res) << '\n';
  for (auto [f, s] : res) {
    cout << char(f + 'a') << ' ' << char(s + 'a') << '\n';
  }
}