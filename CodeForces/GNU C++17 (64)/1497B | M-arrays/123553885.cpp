#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, m;
  cin >> n >> m;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
   int a;
   cin >> a;
   mp[a % m]++;
  }
  int ans = 0;
  for (auto x : mp) {
   if (x.first == 0 || x.first * 2 == m) {
    ans++;
   } else if (x.first * 2 < m || mp[m - x.first] == 0) {
    ans += 1 + max(0, abs(x.second - mp[m - x.first]) - 1);
   }
  }
  cout << ans << '\n';
 }
}