#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, l, r, s;
  cin >> n >> l >> r >> s;
  l--;
  r--;
  vector<int> v(r - l + 1);
  iota(v.begin(), v.end(), 1);
  s -= accumulate(v.begin(), v.end(), 0);
  if (s < 0) {
   cout << -1 << '\n';
   continue;
  }
  int lim = n - v.back();
  for (int i = v.size() - 1; i >= 0; i--) {
   v[i] += min(lim, s);
   s -= min(lim, s);
  }
  if (s > 0) {
   cout << -1 << '\n';
   continue;
  }
  vector<int> excess;
  for (int i = 1; i <= n; i++) {
   if (!count(v.begin(), v.end(), i)) {
    excess.push_back(i);
   }
  }
  for (int i = 0; i < l; i++) {
   cout << excess[i] << ' ';
  }
  for (int x : v) {
   cout << x << ' ';
  }
  for (int i = l; i < excess.size(); i++) {
   cout << excess[i] << ' ';
  }
  cout << '\n';
 }
}