#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int ck(int x) {
 return x < 0 ? 0 : x;
}
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int W, H, x1, y1, x2, y2, w, h;
  cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
  int ans = 1e9;
  if (H - (y2 - y1) >= h) {
   ans = min(ans, min(ck(h - y1), ck(h - (H - y2))));
  }
  if (W - (x2 - x1) >= w) {
   ans = min(ans, min(ck(w - x1), ck(w - (W - x2))));
  }
  cout << (ans == 1e9 ? -1 : ans) << '\n';
 }
}