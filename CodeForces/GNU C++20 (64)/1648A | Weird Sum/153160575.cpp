#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> colors(1e5 + 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int c;
      cin >> c;
      colors[c].push_back({i, j});
    }
  }
  ll ans = 0;
  for (auto &v : colors) {
    int sz = sz(v);
    if (sz > 1) {
      sort(all(v));
      ll pre = v[0].first;
      for (int i = 1; i < sz; i++) {
        ans += 1ll * v[i].first * i - pre;
        pre += v[i].first;
      }
      for (auto &[f, s] : v) {
        swap(f, s);
      }
      sort(all(v));
      pre = v[0].first;
      for (int i = 1; i < sz; i++) {
        ans += 1ll * v[i].first * i - pre;
        pre += v[i].first;
      }
    }
  }
  cout << ans << '\n';
}