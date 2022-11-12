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
  long long l = 0, r = 1e16;
  while (l + 1 < r) {
    long long mid = l + (r - l) / 2;
    long long x = x1 + mid / n * wind[n].first + wind[mid % n].first;
    long long y = y1 + mid / n * wind[n].second + wind[mid % n].second;
    (abs(x - x2) + abs(y - y2) <= mid ? r : l) = mid;
  }
  cout << (r == 1e16 ? -1 : r) << '\n';
}