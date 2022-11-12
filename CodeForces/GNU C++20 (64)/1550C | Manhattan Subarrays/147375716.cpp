#include <bits/stdc++.h>
using namespace std;
 
int main() {
#ifdef LOCAL
  freopen("input.in", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
      cin >> x;
    }
    // An array of length n ^ 2 + 1 must have an increasing subsequence of at least n + 1,
    // so all subarrays with length >= 5 are bad. Also, all subarrays of length 1 and 2 are good.
    // Because of this, the answer can be expressed as n * 2 - 1 + (# of good subarrays with len 3 or 4)
    int ans = n * 2 - 1;
    for (int i = 0; i + 2 < n; i++) {
      ans +=
      !(a[i] <= a[i + 1] && a[i + 1] <= a[i + 2]) &&
      !(a[i] >= a[i + 1] && a[i + 1] >= a[i + 2]);
    }
    for (int i = 0; i + 3 < n; i++) {
      ans +=
      !(a[i] <= a[i + 1] && a[i + 1] <= a[i + 2]) &&
      !(a[i] <= a[i + 1] && a[i + 1] <= a[i + 3]) &&
      !(a[i] <= a[i + 2] && a[i + 2] <= a[i + 3]) &&
      !(a[i + 1] <= a[i + 2] && a[i + 2] <= a[i + 3]) &&
      !(a[i] >= a[i + 1] && a[i + 1] >= a[i + 2]) &&
      !(a[i] >= a[i + 1] && a[i + 1] >= a[i + 3]) &&
      !(a[i] >= a[i + 2] && a[i + 2] >= a[i + 3]) &&
      !(a[i + 1] >= a[i + 2] && a[i + 2] >= a[i + 3]);
    }
    cout << ans << '\n';
  }
}