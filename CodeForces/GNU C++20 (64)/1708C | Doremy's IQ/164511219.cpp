#include <bits/stdc++.h>
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int l = 0, r = n + 1;
    vector<bool> res(n);
    while (l + 1 < r) {
      int mid = l + (r - l) / 2;
      int iq = q;
      int skips = n - mid, cnt = 0;
      vector<bool> cur(n);
      for (int i = 0; i < n; i++) {
        if (iq >= a[i]) {
          cnt++;
          cur[i] = 1;
        }
        if (iq < a[i] && skips > 0) {
          skips--;
        } else if (iq < a[i] && iq > 0) {
          iq--;
          cnt++;
          cur[i] = 1;
        }
      }
      if (cnt >= mid) {
        l = mid;
        res = cur;
      } else {
        r = mid;
      }
    }
    for (int i = 0; i < n; i++) {
      cout << res[i];
    }
    cout << '\n';
  }
}