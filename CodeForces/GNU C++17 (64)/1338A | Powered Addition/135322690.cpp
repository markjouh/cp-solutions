#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  int diff = -1e9, mx = -1e9;
  for (int i = 0; i < n; ++i) {
   int x;
   cin >> x;
   diff = max(diff, mx - x);
   mx = max(mx, x);
  }
  int bal = 0, add = 1, ans = 0;
  while (bal < diff) {
   bal += add;
   add *= 2;
   ++ans;
  }
  cout << ans << '\n';
 
 }
}