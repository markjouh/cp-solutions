#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int tc;
 cin >> tc;
 while (tc--) {
  int n, m;
  cin >> n >> m;
  m++;
  int ans = 0;
  for (int i = 30; i >= 0 && n < m; i--) {
   if ((m >> i & 1) && (n >> i & 1) == 0) {
    ans += 1 << i;
    n += 1 << i;
   }
  }
  cout << ans << '\n';
 }
}