// Author: mzh
// Problem: B. Rising Sand
// Contest: Codeforces - Codeforces Round #803 (Div. 2)
// URL: https://codeforces.com/contest/1698/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define int int64_t
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (k == 1) {
      if (n % 2 == 0) {
        n--;
      }
      cout << n / 2 << '\n';
    } else {
      int ans = 0;
      for (int i = 1; i < n - 1; i++) {
        ans += a[i] > a[i - 1] + a[i + 1];
      }
      cout << ans << '\n';
    }
  }
}