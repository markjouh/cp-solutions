#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int n, dx, dy;
 cin >> n >> dx >> dy;
 vector<pair<int, int>> pos(n);
 for (auto &[x, y] : pos) {
  cin >> x >> y;
 }
 vector<pair<int, int>> tents = {{dx - 1, dy}, {dx, dy - 1}, {dx + 1, dy}, {dx, dy + 1}};
 int best = INT_MIN;
 int xres, yres;
 for (auto [tx, ty] : tents) {
  if (tx < 0 || ty < 0) {
   continue;
  }
  int cur = 0;
  for (auto [x, y] : pos) {
   if (min(x, dx) <= tx && max(x, dx) >= tx && min(y, dy) <= ty && max(y, dy) >= ty) {
    cur++;
   }
  }
  if (cur > best) {
   best = cur;
   xres = tx;
   yres = ty;
  }
 }
 cout << best << '\n' << xres << ' ' << yres << '\n';
}