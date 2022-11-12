#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    long long ans = 0;
    vector<int> a(n);
    deque<int> r;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      ans += a[i] / k;
      r.push_back(a[i] % k);
    }
    // for (int i = 0; i < k; i++) {
    //   if (i * 2 >= k) {
    //     ans += r[i] / 2;
    //     r[i] %= 2;
    //   }
    //   for (int j = i + 1; j < k; j++) {
    //     if (i + j >= k) {
    //       int mn = min(r[i], r[j]);
    //       r[i] -= mn;
    //       r[j] -= mn;
    //       ans += mn;
    //     }
    //   }
    // }
    sort(r.begin(), r.end(), greater<int>());
    while (r.size() > 1) {
      while (!r.empty() && r.front() + r.back() < k) {
        r.pop_back();
      }
      if (r.size() >= 2) {
        r.pop_front();
        r.pop_back();
        ans++;
      }
    }
    cout << ans << '\n';
  }
}