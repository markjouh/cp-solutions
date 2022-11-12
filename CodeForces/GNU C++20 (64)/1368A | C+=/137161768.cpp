#include <bits/stdc++.h>
using namespace std;
 
// Read the problem statement carefully
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int a, b, n;
  cin >> a >> b >> n;
  int ans = 0;
  while (a <= n && b <= n) {
   if (a < b) {
    a += b;
   } else {
    b += a;
   }
   ++ans;
  }
  cout << ans << '\n';
 }
}