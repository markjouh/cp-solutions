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
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
   cin >> a[i].first >> a[i].second;
  }
  bool ok = true;
  for (int i = 0; i < n; i++) {
   ok = true;
   for (int j = 0; j < n; j++) {
    if (abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second) > k) {
     ok = false;
     break;
    }
   }
   if (ok) {
    cout << 1 << '\n';
    break;
   }
  }
  if (!ok) {
   cout << -1 << '\n';
  }
 }
}