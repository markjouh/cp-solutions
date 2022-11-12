#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, k;
  cin >> n >> k;
  vector<int> cnt(n), ans(n), pos;
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
   int a;
   cin >> a;
   cnt[a - 1]++;
   if (cnt[a - 1] <= k) {
    v.push_back({a, i});
   }
  }
  sort(v.begin(), v.end());
  v.resize(v.size() - v.size() % k);
  for (int i = 0; i < v.size(); i++) {
   ans[v[i].second] = i % k + 1;
  }
  for (int i = 0; i < n; i++) {
   cout << ans[i] << ' ';
  }
  cout << '\n';
 }
}