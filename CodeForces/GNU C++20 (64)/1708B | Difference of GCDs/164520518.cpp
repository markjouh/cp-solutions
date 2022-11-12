#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
 
// I thought the values in a[i] had to be distinct...
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    ll n, l, r;
    cin >> n >> l >> r;
    bool ok = true;
    vector<int> res(n);
    for (int i = 1; i <= n; i++) {
      res[i - 1] = (l + i - 1) / i * i;
      ok &= res[i - 1] <= r;
    }
    if (ok) {
      cout << "YES\n";
      for (int i = 0; i < n; i++) {
        cout << res[i] << ' ';
      }
      cout << '\n';
    } else {
      cout << "NO\n";
    }
  }
}