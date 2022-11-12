#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ans = 1e9, pref = 0;
    vector<int> occ(n + 1, -2);
    occ[0] = -1;
    for (int i = 0; i < n; i++) {
      pref += a[i];
      if (pref - s >= 0 && occ[pref - s] != -2) {
        ans = min(ans, n - (i - occ[pref - s]));
      }
      if (occ[pref] == -2) {
        occ[pref] = i;
      }
    }
    cout << (ans == 1e9 ? -1 : ans) << '\n';
  }
}