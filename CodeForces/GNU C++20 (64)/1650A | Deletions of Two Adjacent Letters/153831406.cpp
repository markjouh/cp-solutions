#include <bits/stdc++.h>
 
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = b - 1; i >= a; i--)
#define each(a, b) for (auto &a : b)
#define rep(a) FOR(_, 0, a)
 
using namespace std;
 
void solve() {
  string s;
  char c;
  cin >> s >> c;
  bool ok = false;
  FOR(i, 0, sz(s)) {
    ok |= s[i] == c && i % 2 == 0 && (sz(s) - i - 1) % 2 == 0;
  }
  cout << (ok ? "YES\n" : "NO\n");
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