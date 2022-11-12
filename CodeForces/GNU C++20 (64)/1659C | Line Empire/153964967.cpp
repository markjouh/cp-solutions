#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int MXN = 2e5+1;
ll x[MXN], suf[MXN];
 
int main() {
#ifdef LOCAL
  freopen("input.in", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    ll n, a, b;
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) {
      cin >> x[i];
    }
    suf[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
      suf[i] = suf[i+1] + x[i];
    }
    ll ans = accumulate(x, x + n, 0ll)*b;
    for (int i = 0; i < n; i++) {
      ans = min(ans, x[i]*a + x[i]*b + (suf[i+1]-(n-i-1)*x[i])*b);
    }
    cout << ans << '\n';
  }
}