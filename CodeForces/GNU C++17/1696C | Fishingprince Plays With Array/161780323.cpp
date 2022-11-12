// Author: mzh
// Problem: C. Fishingprince Plays With Array
// Contest: Codeforces - Codeforces Global Round 21
// URL: https://codeforces.com/contest/1696/problem/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define int int64_t
 
vector<pair<int, int>> expand(vector<int> a, int m) {
  int n = a.size();
  vector<pair<int, int>> rng;
  for (int i = 0; i < n; i++) {
     int len = 1, val = a[i];
     while (val % m == 0) {
       val /= m;
       len *= m;
     }
     rng.push_back({val, len});
  }
  vector<pair<int, int>> res;
  res.push_back({rng[0].first, rng[0].second});
  for (int i = 1; i < n; i++) {
    if (rng[i].first == res.back().first) {
      res.back().second += rng[i].second;
    } else {
      res.push_back(rng[i]);
    }
  }
  return res;
}
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int k;
    cin >> k;
    vector<int> b(k);
    for (int i = 0; i < k; i++) {
      cin >> b[i];
    }
    cout << (expand(a, m) == expand(b, m) ? "Yes\n" : "No\n");
  }
}