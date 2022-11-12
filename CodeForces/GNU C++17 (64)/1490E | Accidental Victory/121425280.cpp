#include <bits/stdc++.h>
using namespace std;
 
void solve() {
 int n;
 cin >> n;
 vector<pair<int, int>> v(n);
 for (int i = 0; i < n; i++) {
  cin >> v[i].first;
  v[i].second = i + 1;
 }
 sort(v.begin(), v.end());
 long long sum = 0;
 vector<int> res;
 for (auto x : v) {
  if (x.first > sum) {
   res.clear();
  }
  sum += x.first;
  res.push_back(x.second);
 }
 sort(res.begin(), res.end());
 cout << res.size() << '\n';
 for (int x : res) {
  cout << x << ' ';
 }
 cout << '\n';
}
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  solve();
 }
}