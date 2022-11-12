// Author: mzh
// Problem: B. NIT Destroys the Universe
// Contest: Codeforces - Codeforces Global Round 21
// URL: https://codeforces.com/contest/1696/problem/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
 
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    while (!a.empty() && a.back() == 0) {
      a.pop_back();
    }
    reverse(a.begin(), a.end());
    while (!a.empty() && a.back() == 0) {
      a.pop_back();
    }
    if (accumulate(a.begin(), a.end(), 0ll) == 0ll) {
      cout << 0 << '\n';
    } else if (find(a.begin(), a.end(), 0) == a.end()) {
      cout << 1 << '\n';
    } else {
      cout << 2 << '\n';
    }
  }
}