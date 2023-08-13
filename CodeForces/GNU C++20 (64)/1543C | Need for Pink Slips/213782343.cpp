// Problem: C. Need for Pink Slips
// Contest: Codeforces - Codeforces Round 730 (Div. 2)
// URL: https://codeforces.com/contest/1543/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#include "bits/stdc++.h"
 
using namespace std;
 
#define int long long
 
// the sum of c, m, and p is very small, and v is quite large by comparison
// it turns out that the game can't last for more than 12 moves or so
// we can just do a naive bruteforce
// the expected value is just the probability * value for all possible end states
 
typedef long double ld;
 
const ld eps = 1e-9;
 
ld go(ld c, ld m, ld p, ld v, int len = 1) {
  ld ans = p * len;
  if (c > eps) {
    ld d = min(c, v);
    if (m > eps) {
      ans += c * go(c - d, m + d / 2, p + d / 2, v, len + 1);
    } else {
      ans += c * go(c - d, m, p + d, v, len + 1);
    }
  }
  if (m > eps) {
    ld d = min(m, v);
    if (c > eps) {
      ans += m * go(c + d / 2, m - d, p + d / 2, v, len + 1);
    } else {
      ans += m * go(c, m - d, p + d, v, len + 1);
    }
  }
  return ans;
}
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    ld c, m, p, v;
    cin >> c >> m >> p >> v;
    cout << setprecision(20) << fixed << go(c, m, p, v) << '\n';
  }
}