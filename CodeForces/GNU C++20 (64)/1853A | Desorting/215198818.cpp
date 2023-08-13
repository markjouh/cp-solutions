#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
 
template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }
 
void solve() {
  int n;
  cin >> n;
  int mx = -1e9, ans = 1e9;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x < mx) {
      ans = 0;
    } else {
      ckmin(ans, (x - mx) / 2 + 1);
    }
    ckmax(mx, x);
  }
  cout << ans << '\n';
}
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
 
 