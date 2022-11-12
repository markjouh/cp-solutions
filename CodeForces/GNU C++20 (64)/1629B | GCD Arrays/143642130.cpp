#include <bits/stdc++.h>
using namespace std;
 
int main() {
#ifdef LOCAL
  freopen("input.in", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int l, r, k;
    cin >> l >> r >> k;
    cout << ((l == r && l != 1) || ((r - l + 1) / 2 + (l % 2 && r % 2) <= k) ? "YES" : "NO") << '\n';
  }
}