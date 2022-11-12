// Author: mzh
// Problem: A. NIT orz!
// Contest: Codeforces - Codeforces Global Round 21
// URL: https://codeforces.com/contest/1696/problem/0
// Memory Limit: 512 MB
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
    int n, z;
    cin >> n >> z;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      ans = max(ans, x | z);
    }
    cout << ans << '\n';
  }
}