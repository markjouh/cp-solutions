#include <bits/stdc++.h>
 
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = b - 1; i >= a; i--)
#define each(a, b) for (auto &a : b)
#define rep(a) FOR(_, 0, a)
 
using namespace std;
 
void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> pts(m);
  map<int, int> posindex;
  FOR(i, 0, m) {
    cin >> pts[i].second >> pts[i].first;
    posindex[pts[i].second] = i + 1;
  }
  sort(all(pts));
  pts.resize(n * 2);
  each(p, pts) {
    swap(p.first, p.second);
  }
  sort(all(pts));
  int weight = 0;
  each(p, pts) {
    weight += p.second;
  }
  cout << weight << '\n';
  FOR(i, 0, n) {
    cout << posindex[pts[i].first] << ' ' << posindex[pts[n * 2 - i - 1].first] << '\n';
  }
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