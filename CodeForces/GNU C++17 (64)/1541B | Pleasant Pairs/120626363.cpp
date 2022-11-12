#include <bits/stdc++.h>
using namespace std;
 
int main() {
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) {
   cin >> v[i].first;
   v[i].second = i + 1;
  }
  sort(v.begin(), v.end());
  int mx = 2 * n + 1;
  int ans = 0;
  for (int i = 0; i < n; i++) {
   for (int j = i + 1; j < n; j++) {
    long long prod = (long long)v[i].first * v[j].first;
    if (prod > mx) break;
    if (prod == v[i].second + v[j].second) ans++;
   }
  }
  cout << ans << '\n';
 }
}