#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int l, r;
  cin >> l >> r;
  int ans = 0;
  while (l != 0 || r != 0) {
   ans += r - l;
   l /= 10;
   r /= 10;
  }
  cout << ans << '\n';
 }
}