#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define REP(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = b - 1; i >= (int)a; i--)
#define PER(i, a) ROF(i, 0, a)
 
template<class T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin.exceptions(cin.failbit);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<ll> a(n);
    REP(i, n) {
      cin >> a[i];
    }
    ll pref = 0;
    PER(i, n - 1) {
      a[i] -= pref;
      if (a[i] > a[i + 1]) {
        pref += a[i] - a[i + 1];
        a[i] = a[i + 1];
      }
    }
    ll ans = pref;
    ll mn = 0;
    REP(i, n) {
      ckmin(mn, a[i]);
    }
    if (mn < 0) {
      ans += -mn;
      REP(i, n) {
        a[i] -= mn;
      }
    }
    ll mx = 0;
    REP(i, n) {
      ckmax(mx, a[i]);
    }
    ans += mx;
    cout << ans << '\n';
  }
}