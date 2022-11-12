// Author: mzh
// Problem: C. 3SUM Closure
// Contest: Codeforces - Codeforces Round #803 (Div. 2)
// URL: https://codeforces.com/contest/1698/problem/C
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
    int zeroes = 0, pos = 0, neg = 0;
    vector<int> a;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x == 0) {
        zeroes++;
      } else {
        a.push_back(x);
        pos += x > 0;
        neg += x < 0;
      }
    }
    // We can't have more than 2 number with the same positive/negative sign
    if (pos > 2 || neg > 2) {
      cout << "NO\n";
      continue;
    }
    // There's no point in having more than 3 of the same number
    for (int i = 0; i < min(zeroes, 3ll); i++) {
      a.push_back(0);
    }
    // m <= 7
    bool ok = true;
    int m = a.size();
    for (int i = 0; i < m; i++) {
      for (int j = i + 1; j < m; j++) {
        for (int k = j + 1; k < m; k++) {
          ok &= find(a.begin(), a.end(), a[i] + a[j] + a[k]) != a.end();
        }
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}