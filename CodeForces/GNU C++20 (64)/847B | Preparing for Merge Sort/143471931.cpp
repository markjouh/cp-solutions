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
  vector<vector<int>> a(n);
  int m = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    int l = 0, r = m;
    while (l < r) {
      int mid = l + (r - l) / 2;
      a[mid].back() < x ? r = mid : l = mid + 1;
    }
    a[r].push_back(x);
    m = max(m, r + 1);
  }
  for (int i = 0; i < m; i++) {
    for (int x : a[i]) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}