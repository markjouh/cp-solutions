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
  vector<pair<double, double>> pts_v, pts_h;
  pts_v.push_back({x1, (-a * x1 - c) / b});
  pts_v.push_back({(-b * y1 - c) / a, y1});
  pts_h.push_back({x2, (-a * x2 - c) / b});
  pts_h.push_back({(-b * y2 - c) / a, y2});
  double ans = abs(x1 - x2) + abs(y1 - y2);
  for (auto [x3, y3] : pts_v) {
    for (auto [x4, y4] : pts_h) {
      ans = min(ans, dist(x1, y1, x3, y3) + dist(x3, y3, x4, y4) + dist(x4, y4, x2, y2));
    }
  }
  cout << setprecision(10) << fixed << ans << '\n';
}