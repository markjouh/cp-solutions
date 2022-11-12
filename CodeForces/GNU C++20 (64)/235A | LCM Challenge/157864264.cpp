#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define sz(x) int(size(x))
#define all(x) begin(x), end(x)
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  if (n < 3) {
    cout << n;
    return 0;
  }
  // The prime gap is small, so we only need to check the last ~200 or so.
  // This should work since we can replace any such value with a greater prime and obtain a higher answer.
  ll ans = 0;
  for (ll i = max(1, n - 200); i <= n; i++) {
    for (ll j = i + 1; j <= n; j++) {
      for (ll k = j + 1; k <= n; k++) {
        ans = max(ans, lcm(i, lcm(j, k)));
      }
    }
  }
  cout << ans;
}