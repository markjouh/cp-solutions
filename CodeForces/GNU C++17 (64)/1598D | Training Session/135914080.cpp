#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int)(a).size()
 
template <class T, class S> inline bool ckmax(T& a, const S& b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S> inline bool ckmin(T& a, const S& b) { return (a > b ? a = b, 1 : 0); }
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  int prob[n][2];
  int f[n + 1] = {}, s[n + 1] = {};
  for (int i = 0; i < n; ++i) {
   cin >> prob[i][0] >> prob[i][1];
   ++f[prob[i][0]];
   ++s[prob[i][1]];
  }
  ll ans = 1ll * n * (n - 1) * (n - 2) / 6;
  for (int i = 0; i < n; ++i) {
   ans -= 1ll * (f[prob[i][0]] - 1) * (s[prob[i][1]] - 1);
  }
  cout << ans << '\n';
 }
}
 