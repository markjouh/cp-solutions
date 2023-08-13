#include "bits/stdc++.h"
 
using namespace std;
 
#define int long long
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    int q;
    cin >> q;
    int h_mn = 1, h_mx = 1e18;
    while (q--) {
      int t;
      cin >> t;
      if (t == 1) {
        int a, b, n;
        cin >> a >> b >> n;
        int x = max(h_mn, (a - b) * (n - 1) + 1 + b * (n > 1));
        int y = min(h_mx, (a - b) * (n - 1) + a);
        if (x <= y) {
          cout << 1 << ' ';
          h_mn = x;
          h_mx = y;
        } else {
          cout << 0 << ' ';
        }
      } else {
        int a, b;
        cin >> a >> b;
        int d_mn = 1 + max(0ll, (h_mn - a + a - b - 1) / (a - b));
        int d_mx = 1 + max(0ll, (h_mx - a + a - b - 1) / (a - b));
        cout << (d_mn == d_mx ? d_mn : -1) << ' ';
      }
    }
    cout << '\n';
  }
}