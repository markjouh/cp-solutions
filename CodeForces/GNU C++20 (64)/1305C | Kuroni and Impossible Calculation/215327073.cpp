#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
 
template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }
 
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n <= m) {
    int ans = 1;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        ans = 1ll * ans * abs(a[i] - a[j]) % m;
      }
    }
    cout << ans << '\n';
  } else {
    cout << 0 << '\n';
  }
}
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t = 1;
  /* cin >> t; */
  while (t--) {
    solve();
  }
  return 0;
}
 
 