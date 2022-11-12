#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define FOR(i, n) for (int i = 0; i < (int)n; i++)
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> ti(n), hp(n);
    for (int &x : ti) {
      cin >> x;
    }
    for (int &x : hp) {
      cin >> x;
    }
    ll ans = 0;
    int ctri = 0, last = 0;
    for (int i = 0; i < n; i++) {
      int d = ti[i] - last, need = hp[i];
 
      for (int j = i + 1; j < n; j++) {
        need = max(need, hp[j] - (ti[j] - ti[i]));
      }
 
      if (need <= d) {
        ans += 1ll * ctri * (ctri + 1) / 2;
        ctri = need;
      } else {
        ctri += d;
      }
 
      last = ti[i];
    }
    ans += 1ll * ctri * (ctri + 1) / 2;
    cout << ans << '\n';
  }
}