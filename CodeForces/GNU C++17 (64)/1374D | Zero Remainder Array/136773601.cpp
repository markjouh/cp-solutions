#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n, k;
  cin >> n >> k;
  map<int, int> mp;
  for (int i = 0; i < n; ++i) {
   int x;
   cin >> x;
   if (x % k) {
    ++mp[k - x % k];
   }
  }
  long long ans = 0;
  for (auto [f, s] : mp) {
   ans = max(ans, f + 1ll * k * (s - 1));
  }
  ans += ans > 0;
  cout << ans << '\n';
 }
}