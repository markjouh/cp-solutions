#include "bits/stdc++.h"

using namespace std;

#define int long long

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<string> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  vector<string> d(m + 1);
  for (int i = 1; i <= m; i++) {
    cin >> d[i];
  }
  vector<int> p(m + 1);
  for (int i = 0; i <= m; i++) {
    cin >> p[i];
  }
  map<string, int> mp;
  for (int i = 1; i <= m; i++) {
    mp[d[i]] = p[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (mp.count(c[i])) {
      ans += mp[c[i]];
    } else {
      ans += p[0];
    }
  }
  cout << ans << '\n';
}
