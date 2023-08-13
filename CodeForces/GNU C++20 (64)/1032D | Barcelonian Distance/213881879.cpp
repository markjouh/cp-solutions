// Problem: D. Barcelonian Distance
// Contest: Codeforces - Technocup 2019 - Elimination Round 3
// URL: https://codeforces.com/contest/1032/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#include "bits/stdc++.h"
 
using namespace std;
 
#define int long long
#define double long double
 
double dist(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  double a, b, c, x1, y1, x2, y2;
  cin >> a >> b >> c >> x1 >> y1 >> x2 >> y2;
  double line_x1 = (-a * x1 - c) / b;
  double line_y1 = (-b * y1 - c) / a;
  double line_x2 = (-a * x2 - c) / b;
  double line_y2 = (-b * y2 - c) / a;
  double ans = abs(x1 - x2) + abs(y1 - y2);
  if (line_y1 >= min(x1, x2) && line_y1 <= max(x1, x2) && line_x2 >= min(y1, y2) && line_x2 <= max(y1, y2)) {
    ans = min(ans, abs(x1 - line_y1) + dist(line_y1, y1, x2, line_x2) + abs(y2 - line_x2));
  }
  if (line_y1 >= min(x1, x2) && line_y1 <= max(x1, x2) && line_y2 >= min(x1, x2) && line_y2 <= max(x1, x2)) {
    ans = min(ans, abs(x1 - line_y1) + dist(line_y1, y1, line_y2, y2) + abs(x2 - line_y2));
  }
  if (line_x1 >= min(y1, y2) && line_x1 <= max(y1, y2) && line_y2 >= min(x1, x2) && line_y2 <= max(x1, x2)) {
    ans = min(ans, abs(y1 - line_x1) + dist(x1, line_x1, line_y2, y2) + abs(x2 - line_y2));
  }
  if (line_x1 >= min(y1, y2) && line_x1 <= max(y1, y2) && line_x2 >= min(y1, y2) && line_x2 <= max(y1, y2)) {
    ans = min(ans, abs(y1 - line_x1) + dist(x1, line_x1, x2, line_x2) + abs(y2 - line_x2));
  }
  cout << setprecision(10) << fixed << ans << '\n';
}