#include "bits/stdc++.h"
 
using namespace std;
 
#define int long long
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = -1e18;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      mx = max(mx, a[i]);
    }
    if (mx <= 0) {
      cout << mx << '\n';
      continue;
    }
    int even = 0, odd = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] > 0) {
        (i % 2 ? odd : even) += a[i];
      }
    }
    cout << max(even, odd) << '\n';
  }
}