// Problem: A. Divide and Conquer
// Contest: Codeforces - Codeforces Round 838 (Div. 2)
// URL: https://codeforces.com/contest/1762/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
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
    int tot = 0, change = 1e9;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      tot += x;
      
      int p = x % 2, cnt = 0;
      while (x > 0 && x % 2 == p) {
        x /= 2;
        cnt++;
      }
      change = min(change, cnt);
    }
    cout << (tot % 2 ? change : 0) << '\n';
  }
}