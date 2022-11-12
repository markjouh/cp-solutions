#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, x;
  cin >> n >> x;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
   cin >> a[i].first;
   a[i].second = 1;
  }
  for (int i = 0; i < a.size(); i++) {
   if (a[i].first % x) {
    break;
   }
   a.push_back({a[i].first / x, a[i].second * x});
  }
  long long ans = 0;
  for (int i = 0; i < a.size(); i++) {
   ans += a[i].first * a[i].second;
  }
  cout << ans << '\n';
 }
}