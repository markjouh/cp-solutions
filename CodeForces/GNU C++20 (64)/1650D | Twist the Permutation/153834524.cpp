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
  deque<int> a(n);
  each(x, a) {
    cin >> x;
  }
  vector<int> ans(n + 1);
  for (int i = n; i >= 1; i--) {
    while (a.back() != i) {
      a.push_back(a.front());
      a.pop_front();
      ans[i]++;
    }
    a.pop_back();
  }
  FOR(i, 1, n + 1) {
    cout << ans[i] << ' ';
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