#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  ll k, n, a, b;
  cin >> k >> n >> a >> b;
  ll sum = n * a, ans = n;
  if (sum >= k) {
   ans -= (sum - k + a - b) / (a - b);
  }
  ans = max(ans, -1ll);
  cout << ans << '\n';
 }
}