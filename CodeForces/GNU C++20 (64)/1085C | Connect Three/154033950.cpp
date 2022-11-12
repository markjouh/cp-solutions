#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (int i = a; i < b; i++)
#define per(i,a,b) for (int i = b-1; i >= a; i--)
 
int pts[3][2];
 
void mv(int &a, int b) {
  a < b ? a++ : a--;
}
 
int main() {
#ifdef LOCAL
  freopen("input.in", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  rep(i,0,3) rep(j,0,2) cin >> pts[i][j];
  int ans = 1e9;
  int ty = 0, tx = 0;
  rep(i,0,1e3+1) rep(j,0,1e3+1) {
    int cur = 0;
    rep(k,0,3) cur += abs(i-pts[k][0]) + abs(j-pts[k][1]);
    if (cur < ans) {
      ans = cur;
      tx = i;
      ty = j;
    }
  }
  cout << ans+1 << '\n';
  cout << tx << ' ' << ty << '\n';
  rep(i,0,3) {
    while (pts[i][0] != tx) {
      cout << pts[i][0] << ' ' << pts[i][1] << '\n';
      mv(pts[i][0],tx);
    }
    while (pts[i][1] != ty) {
      cout << pts[i][0] << ' ' << pts[i][1] << '\n';
      mv(pts[i][1],ty);
    }
  }
}