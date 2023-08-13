#include "bits/stdc++.h"
 
using namespace std;
 
// #define int long long
 
const int INF = 0x3f3f3f3f;
 
const int N = 5e3, M = 2e4;
 
int cnt[N], mn_ab[N], mn_ba[N];
 
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
    memset(cnt, 0, sizeof(cnt));
    memset(mn_ab, INF, sizeof(mn_ab));
    memset(mn_ba, INF, sizeof(mn_ba));
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
      if (mn_ab[j] == INF && mn_ba[j] != INF) {
        ans = max(ans, (cnt[j] + 1) * n - n + mn_ba[j]);
      } else {
        ans = max(ans, cnt[j] * n - n + mn_ab[j]);
      }
    }
    cout << ans << ' ';
  }
  cout << '\n';
}