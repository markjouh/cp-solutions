#include <bits/stdc++.h>
using namespace std;
 
int main() {
#ifdef LOCAL
  freopen("input.in", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, t;
  cin >> n >> t;
  vector<vector<double>> a(n);
  for (int i = 0; i < n; i++) {
    a[i].resize(i + 1);
  }
  while (t--) {
    a[0][0]++;
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < i + 1; j++) {
        if (a[i][j] > 1) {
          double overflow = (a[i][j] - 1) / 2;
          a[i][j] = 1;
          a[i + 1][j] += overflow;
          a[i + 1][j + 1] += overflow;
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i + 1; j ++) {
      ans += a[i][j] >= 1;
    }
  }
  cout << ans << '\n';
}