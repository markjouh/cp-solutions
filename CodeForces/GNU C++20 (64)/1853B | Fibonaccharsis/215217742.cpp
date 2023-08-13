#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
 
template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }
 
void solve() {
  int n, k;
  cin >> n >> k;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
 
    int a = n, b = i;
    bool ok = true;
 
    for (int j = 3; j <= k; j++) {
      int c = a - b;
      a = b;
      b = c;
 
      if (b > a) {
        ok = false;
        break; 
      }
    }
    if (ok) {
      ans++;
    }
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
 
 