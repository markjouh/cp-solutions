// Author: mzh
// Problem: A. XOR Mixup
// Contest: Codeforces - Codeforces Round #803 (Div. 2)
// URL: https://codeforces.com/contest/1698/problem/A
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int x = 0;
      for (int j = 0; j < n; j++) {
        if (i != j) {
          x ^= a[j];
        }
      }
      if (x == a[i]) {
        ans = x;
        break;
      }
    }
    cout << ans << '\n';
  }
}