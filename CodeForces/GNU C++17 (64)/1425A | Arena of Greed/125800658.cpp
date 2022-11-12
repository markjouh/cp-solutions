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
  ll ans = 0, move = 1;
  while (n > 0) {
   ll x = (n % 2 || (n > 8 && n % 4 == 0) ? 1 : n / 2);
   if (move % 2) {
    ans += x;
   }
   n -= x;
   move++;
  }
  cout << ans << '\n';
 }
}