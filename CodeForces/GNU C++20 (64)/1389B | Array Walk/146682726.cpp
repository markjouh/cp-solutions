#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, z; cin >> n >> k >> z;
    vector<int> a(n), pre;
    for (int &x : a) {
      cin >> x;
    }
    pre = a;
    for (int i = 1; i < n; i++) {
      pre[i] += pre[i-1];
    }
    long long ans = 0;
    for (int i = 1; i < n; i++) {
      if (i > k) {
        continue;
      }
      int ck = k-i, l = min(z, (ck+1)/2), r = min(l, ck/2);
      long long cur = pre[i] + a[i-1]*l + a[i]*r;
      if (ck-l-r) {
        cur += pre[min(n-1, i+ck-l-r)] - pre[i];
      }
      ans = max(ans, cur);
    }
    cout << ans << '\n';
  }
}