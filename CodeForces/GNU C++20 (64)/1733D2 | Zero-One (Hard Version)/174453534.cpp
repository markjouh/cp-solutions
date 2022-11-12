#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define siz(x) (int)(x).size()
#define fi first
#define se second
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  ll x, y;
  string a, b;
  cin >> n >> x >> y >> a >> b;
  vector<int> diff;
  for (int i = 0; i < n; i++) {
   if (a[i] != b[i]) {
    diff.push_back(i);
   }
  }
  if (siz(diff) % 2) {
   cout << -1 << '\n';
   continue;
  }
  if (siz(diff) == 0) {
   cout << 0 << '\n';
   continue;
  }
  if (siz(diff) == 2 && x >= y) {
   if (diff[0] + 1 == diff[1]) {
    cout << min(x, 2 * y) << '\n';
   } else {
    cout << y << '\n';
   }
  } else {
   vector<vector<ll>> dp(siz(diff) + 1, vector<ll>(siz(diff) / 2 + 1, 2e18));
   dp[0][0] = dp[1][0] = 0;
   for (int i = 1; i < siz(diff); i++) {
    for (int j = 0; j <= siz(diff) / 2; j++) {
     dp[i + 1][j] = dp[i][j];
    }
    for (int j = 1; j <= siz(diff) / 2; j++) {
     dp[i + 1][j] = min(dp[i + 1][j], dp[i - 1][j - 1] + diff[i] - diff[i - 1]);
    }
   }
   ll ans = 2e18;
   for (int i = 0; i <= siz(diff) / 2; i++) {
    ans = min(ans, dp[siz(diff)][i] * x + (siz(diff) / 2 - i) * y);
   }
   cout << ans << '\n';
  }
 }
}