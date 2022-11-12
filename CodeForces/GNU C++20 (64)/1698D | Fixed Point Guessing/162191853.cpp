// Author: mzh
// Problem: D. Fixed Point Guessing
// Contest: Codeforces - Codeforces Round #803 (Div. 2)
// URL: https://codeforces.com/contest/1698/problem/D
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
    int l = 0, r = n;
    while (l + 1 < r) {
      int mid = l + (r - l) / 2;
      cout << "? " << l + 1 << ' ' << mid << endl;
      int cnt = 0;
      for (int i = l; i < mid; i++) {
        int x;
        cin >> x;
        if (x > l && x <= mid) {
          cnt++;
        }
      }
      (cnt % 2 ? r : l) = mid;
    }
    cout << "! " << r << endl;
  }
}