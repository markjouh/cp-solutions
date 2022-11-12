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
  int X1 = 1e9, X2 = -1e9, Y1 = 1e9, Y2 = -1e9;
  map<pair<int, int>, int> pts;
  for (int i = 0; i < n; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    X1 = min(X1, x1);
    X2 = max(X2, x2);
    Y1 = min(Y1, y1);
    Y2 = max(Y2, y2);
    pts[{x1, y1}]++;
    pts[{x1, y2}]++;
    pts[{x2, y1}]++;
    pts[{x2, y2}]++;
  }
  int corners = 0;
  for (auto [f, s] : pts) {
    corners += s == 1;
  }
  // oops I submitted my debug code earlier
  cout << (corners == 4 && X2 - X1 == Y2 - Y1 ? "YES" : "NO") << '\n';
}