#include "bits/stdc++.h"
 
using namespace std;
 
#define int long long
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> c(m);
  for (auto &[a, b] : c) {
    cin >> a >> b;
    a--; b--;
  }
  for (int i = 0; i < n; i++) {
    vector<int> cnt(n), mn_ab(n, 1e9), mn_ba(n, 1e9);
    for (auto [a, b] : c) {
      a -= i;
      if (a < 0) {
        a += n;
      }
      b -= i;
      if (b < 0) {
        b += n;
      }
      cnt[a]++;
      if (a < b) {
        mn_ab[a] = min(mn_ab[a], b);
      } else {
        mn_ba[a] = min(mn_ba[a], b);
      }
    }
    int ans = 0;
    for (int j = 0; j < n; j++) {
      if (cnt[j] == 0) {
        continue;
      }
      if (mn_ab[j] == 1e9 && mn_ba[j] != 1e9) {
        ans = max(ans, (cnt[j] + 1) * n - n + mn_ba[j]);
      } else {
        ans = max(ans, cnt[j] * n - n + mn_ab[j]);
      }
    }
    cout << ans << ' ';
  }
  cout << '\n';
}