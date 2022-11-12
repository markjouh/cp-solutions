#include <bits/stdc++.h>
using namespace std;
 
int main() {
#ifdef LOCAL
  freopen("input.in", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> pos(n), spe(n);
  for (int &x : pos) {
    cin >> x;
  }
  for (int &x : spe) {
    cin >> x;
  }
  double l = 0, r = 1e9;
  for (int i = 0; i < 100; i++) {
    double mid = l + (r - l) / 2;
    double rngl = 0, rngr = 1e9;
    for (int j = 0; j < n; j++) {
      double d = mid * spe[j];
      rngl = max(rngl, pos[j] - d);
      rngr = min(rngr, pos[j] + d);
    }
    (rngl <= rngr ? r : l) = mid;
  }
  cout << setprecision(10) << fixed << r << '\n';
}