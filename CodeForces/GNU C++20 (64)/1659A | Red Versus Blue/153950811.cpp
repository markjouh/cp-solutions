#include <bits/stdc++.h>
 
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = b - 1; i >= a; i--)
#define each(a, b) for (auto &a : b)
#define rep(a) FOR(_, 0, a)
 
using namespace std;
 
void solve() {
  int n, r, b;
  cin >> n >> r >> b;
  int cur = 0;
  rep(n) {
    int m = (r + b) / (b + 1);
    if (cur == m) {
      cout << 'B';
      r -= m;
      b--;
      cur = 0;
    } else {
      cout << 'R';
      cur++;
    }
  }
  cout << '\n';
}
 
int main() {
#ifdef LOCAL
  freopen("input.in", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  rep(tc) {
    solve();
  }
}