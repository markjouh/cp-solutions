#include <bits/stdc++.h>
using namespace std;
 
const int mxn = 2e5;
 
int a[mxn];
 
int main() {
#ifdef LOCAL
  freopen("input.in", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    for (int i = n - 1; i >= 0; i--) {
      cin >> a[i];
    }
    int id = 0, ans = 0;
    while (id < n) {
      while (id < n && a[id] == a[0]) {
        id++;
      }
      if (id < n) {
        ans++;
      }
      id *= 2;
    }
    cout << ans << '\n';
  }
}