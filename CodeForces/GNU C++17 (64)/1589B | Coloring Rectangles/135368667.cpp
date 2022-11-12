#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n, m;
  cin >> n >> m;
  int ans = 0;
  for (int i = 0; i < 2; ++i) {
   if (n * m % 3 == 1) {
    ans = max(ans, n * m / 3 - 1 + (n * m % 3 + 3) / 2);
   } else {
    ans = max(ans, n * m / 3 + (n * m) % 3 / 2);
   }
  }
  cout << ans << '\n';
 }
}