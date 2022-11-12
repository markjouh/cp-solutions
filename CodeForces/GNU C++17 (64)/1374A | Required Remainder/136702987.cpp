#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int x, y, n;
  cin >> x >> y >> n;
  int ans = n / x * x;
  if (ans + y > n) {
   ans -= x;
  }
  ans += y;
  cout << ans << '\n';
 }
}