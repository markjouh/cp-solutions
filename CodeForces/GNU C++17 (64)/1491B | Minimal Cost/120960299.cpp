#include <bits/stdc++.h>
using namespace std;
 
int main() {
 int t;
 cin >> t;
 while (t--) {
  int n, vertcost, horcost;
  cin >> n >> vertcost >> horcost;
  vector<int> v(n);
  for (auto &x : v) cin >> x;
  int ans = horcost + min(vertcost, horcost);
  for (int i = 1; i < n; i++) {
   int diff = abs(v[i] - v[i - 1]);
   if (diff == 1) ans = min(ans, min(vertcost, horcost));
   else if (diff > 1) ans = 0;
  }
  cout << ans << '\n';
 }
}