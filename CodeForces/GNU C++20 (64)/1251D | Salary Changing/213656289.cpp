// Problem: D. Salary Changing
// Contest: Codeforces - Educational Codeforces Round 75 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1251/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#include "bits/stdc++.h"
 
using namespace std;
 
#define int long long
 
// the median salaries that we can acheive come in a range
// the configuration that acheives the lowest median salary is when we pay everyone the minimum possible
// if we binary search on the lowest median upwards, we have a monotonic function
// now, we just need to be able to check "can we get a median >= x?" in linear time
 
// let k be the center index (n / 2)
// we don't really care about the values of [0, k), they're just filler
// everything [k, n) must be >= mid (in our binsearch)
// so, we must take n - k elements with right border >= mid and raise their salaries if < mid
// if there are more than n - k candidates, we take the ones with higher left border, as we already paid all minimum expenses
// and want to minimize the additional cost.
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, s;
    cin >> n >> s;
    vector<pair<int, int>> p(n);
    int tot_l = 0;
    for (auto &[l, r] : p) {
      cin >> l >> r;
      tot_l += l;
    }
    sort(p.begin(), p.end());
    int lo = p[n / 2].first, hi = 2e14 + 1;
    while (lo + 1 < hi) {
      int mid = lo + (hi - lo) / 2;
      vector<int> d;
      for (auto [l, r] : p) {
        if (r >= mid) {
          d.push_back(l);
        }
      }
      if ((int)d.size() < n / 2 + 1) {
        hi = mid;
        continue;
      }
      sort(d.rbegin(), d.rend());
      int cost = 0;
      for (int i = 0; i < n / 2 + 1; i++) {
        cost += max(0ll, mid - d[i]);
      }
      (tot_l + cost <= s ? lo : hi) = mid;
    }
    cout << lo << '\n';
  }
}