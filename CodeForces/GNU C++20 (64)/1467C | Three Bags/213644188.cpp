// Problem: C. Three Bags
// Contest: Codeforces - Codeforces Round 695 (Div. 2)
// URL: https://codeforces.com/contest/1467/problem/C
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
  array<int, 3> sz;
  for (int i = 0; i < 3; i++) {
    cin >> sz[i];
  }
  vector<int> mn(3, 1e9), sum(3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < sz[i]; j++) {
      int x;
      cin >> x;
      mn[i] = min(mn[i], x);
      sum[i] += x;
    }
  }
  int tot = sum[0] + sum[1] + sum[2];
  for (int i = 0; i < 3; i++) {
    mn[i] *= 2;
    sum[i] *= 2;
  }
  cout << max({tot - mn[0] - mn[1], tot - mn[0] - mn[2], tot - mn[1] - mn[2], tot - sum[0], tot - sum[1], tot - sum[2]}) << '\n';
}