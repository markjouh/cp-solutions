#include <bits/stdc++.h>
using namespace std;
 
void solve() {
 int n, m, x;
 cin >> n >> m >> x;
 vector<int> blocks(n), ans;
 for (auto &x : blocks) cin >> x;
 set<pair<int, int>> towers;
 for (int i = 0; i < m; i++) {
  towers.emplace(0, i);
 }
 cout << "YES" << '\n';
 for (int i = 0; i < n; i++) {
  auto it = towers.begin();
  int hei = it -> first, pos = it -> second;
  ans.push_back(pos + 1);
  hei += blocks[i];
  towers.erase(it);
  towers.emplace(hei, pos);
 }
 for (auto x : ans) cout << x << ' ';
 cout << '\n';
}
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  solve();
 }
}