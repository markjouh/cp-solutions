// Author: mzh
// Problem: C. Sequence Pair Weight
// Contest: Codeforces - Codeforces Round #721 (Div. 2)
// URL: https://codeforces.com/contest/1527/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
 
/*
For a given value a[j] in a, we can just count the number of pairs it
forms with all a[i] such that i < j in a.
 
For a pair of positions (i, j), the number of subsegments where this
pair occurs is equal to (i + 1) * (n - j). Since j and therefore n - j
are fixed, and a * c + b * c == (a + b) * c, we can just get the sum of
all positions i (1-indexed) and multiply by (n - j) for each value in a
to find the answer.
*/
 
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
    int ans = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      ans += mp[x] * (n - i);
      mp[x] += i + 1;
    }
    cout << ans << '\n';
  }
}