#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
 
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
 
ll factorial(int x) {
  ll res = 1;
  for (ll i = 2; i <= x; i++) {
    res *= i;
  }
  return res;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<ll> fac(16);
  for (int i = 0; i <= 15; i++) {
    fac[i] = factorial(i);
  }
  int tc;
  cin >> tc;
  while (tc--) {
    ll n;
    cin >> n;
    int ans = 1e9;
    for (int mask = 0; mask <= (1 << 15); mask++) {
      int cur = 0;
      ll m = n;
      for (int bit = 0; bit <= 15; bit++) {
        if ((mask >> bit) & 1 && fac[bit] <= m) {
          m -= fac[bit];
          cur++;
        }
      }
      for (int bit = 0; bit <= 40; bit++) {
        cur += (m >> bit) & 1;
      }
      ans = min(ans, cur);
    }
    cout << ans << '\n';
  }
}