#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    int mn_x = 0, mx_x = 0;
    int mn_y = 0, mx_y = 0;
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      mn_x = min(mn_x, x);
      mx_x = max(mx_x, x);
      mn_y = min(mn_y, y);
      mx_y = max(mx_y, y);
    }
    cout << 2 * (mx_x - mn_x) + 2 * (mx_y - mn_y) << '\n';
  }
}