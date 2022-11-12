// Author: mzh
// Problem: C. Watering Flowers
// Contest: Codeforces - Codeforces Round #340 (Div. 2)
// URL: https://codeforces.com/contest/617/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define int int64_t
 
int sq(int x) {
  return x * x;
}
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, x1, y1, x2, y2;
  cin >> n >> x1 >> y1 >> x2 >> y2;
  
  vector<int> d1(n), d2(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    d1[i] = sq(x1 - x) + sq(y1 - y);
    d2[i] = sq(x2 - x) + sq(y2 - y);
  }
  
  vector<int> to_try = d1;
  to_try.push_back(0);
  
  int ans = 2e18;
  for (int r1 : to_try) {
    int r2 = 0;
    for (int i = 0; i < n; i++) {
      if (d1[i] > r1) {
        r2 = max(r2, d2[i]);
      }
    }
    ans = min(ans, r1 + r2);
  }
  cout << ans;
}