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
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n);
    for (int i = 0; i < m; i++) {
      int x;
      cin >> x;
      x--;
      cnt[x]++;
    }
    int l = 0, r = m * 2;
    while (l + 1 < r) {
      int mid = l + (r - l) / 2;
      long long free = 0, jobs = m;
      for (int i = 0; i < n; i++) {
        int t = min(cnt[i], mid);
        jobs -= t;
        free += (mid - t) / 2;
      }
      (free >= jobs ? r : l) = mid;
    }
    cout << r << '\n';
  }
}