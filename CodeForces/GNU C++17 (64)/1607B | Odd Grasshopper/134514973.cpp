#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  ll x, n;
  cin >> x >> n;
  for (ll i = n / 4 * 4 + 1; i <= n; ++i) {
   if (x % 2) {
    x += i;
   } else {
    x -= i;
   }
  }
  cout << x << '\n';
 }
}