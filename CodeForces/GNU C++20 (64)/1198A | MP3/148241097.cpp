#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
 
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, t;
  cin >> n >> t;
 
  // Get modified array b
  vector<int> a(n), b, pre, suf;
  for (int &x : a) cin >> x;
  sort(a.begin(), a.end());
  
  int len = 1;
  int unique = 1;
  for (int i = 1; i < n; i++) {
    if (a[i] != a[i-1]) {
      b.push_back(len);
      len = 0;
      unique++;
    }
    len++;
  }
  b.push_back(len);
 
  // Create a prefix and suffix sum
  int m = b.size();
  pre.resize(m+1);
  for (int i = 1; i <= m; i++) {
    pre[i] = pre[i-1] + b[i-1];
  }
  suf.resize(m+1);
  for (int i = m-1; i >= 0; i--) {
    suf[i] = suf[i+1] + b[i];
  }
 
  // Calculate the number of unique values to remove
  int l = 0, r = unique+1;
  while (l+1 < r) {
    int mid = l+(r-l)/2;
    (log2(mid) <= t*8/n ? l : r) = mid;
  }
  int rem = max(0, unique-l);
 
  // Get prefix + suffix with total length rem with minimum sum
  int ans = 1e9;
  for (int i = 0; i <= rem; i++) {
    ans = min(ans, pre[i]+suf[m-(rem-i)]);
  }
 
  cout << ans << '\n';
}