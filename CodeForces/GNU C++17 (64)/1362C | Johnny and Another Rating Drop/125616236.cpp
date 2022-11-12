#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  ll n;
  cin >> n;
  ll ans = n;
  for (ll i = 2; i <= n; i *= 2) {
   ans += n / i;
  }
  cout << ans << '\n';
 }
}