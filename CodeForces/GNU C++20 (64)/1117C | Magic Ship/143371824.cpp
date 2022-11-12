#include <bits/stdc++.h>
using namespace std;
 
int main() {
#ifdef LOCAL
  freopen("input.in", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int x1, y1, x2, y2, n;
  string s;
  cin >> x1 >> y1 >> x2 >> y2 >> n >> s;
  vector<pair<int, int>> wind(n + 1);
  for (int i = 1; i <= n; i++) {
    wind[i] = wind[i - 1];
    switch (s[i - 1]) {
      case 'U': wind[i].second++; break;
      case 'D': wind[i].second--; break;
      case 'L': wind[i].first--; break;
      case 'R': wind[i].first++; break;
    }
  }
  long long l = 0, r = 1e14 + 1;
  while (l + 1 < r) {
    long long mid = l + (r - l) / 2;
    long long x = x1 + mid / n * wind[n].first + wind[mid % n].first;
    long long y = y1 + mid / n * wind[n].second + wind[mid % n].second;
    (abs(x - x2) + abs(y - y2) <= mid ? r : l) = mid;
  }
  cout << (r == 1e14 + 1 ? -1 : r) << '\n';
}
 
/*
The longest possible successful trip is when we are in the bottom left corner and the dest
is in the top right corner (1e9, 1e9), while the wind has 1e5 - 1 going left/down, and 1
going either up/right. This will take 1e9 * 1e5 = 1e14 operations.
*/