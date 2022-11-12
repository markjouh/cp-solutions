#include <bits/stdc++.h>
 
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = b - 1; i >= a; i--)
#define each(a, b) for (auto &a : b)
#define rep(a) FOR(_, 0, a)
 
using namespace std;
 
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> next(n + 1);
  FOR(i, 1, n + 1) {
    cin >> next[i].first >> next[i].second;
  }
  int cur = 1;
  vector<bool> seen(n + 1);
  rep(n) {
    cout << cur << ' ';
    seen[cur] = true;
    auto f = next[cur].first, s = next[cur].second;
    cur = (!seen[f] && (next[f].first == s || next[f].second == s) ? f : s);
  }
}
 
int main() {
#ifdef LOCAL
  freopen("input.in", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}