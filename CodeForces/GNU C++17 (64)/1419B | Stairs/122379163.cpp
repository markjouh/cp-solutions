#include <bits/stdc++.h>
using namespace std;
 
long long ds(long long x) {
 return x * (x + 1) / 2;
}
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  long long a;
  cin >> a;
  int cur = 2, ans = 1;
  while (a > 0) {
   a -= ds((1ll << cur) - 1);
   if (a > 0) {
    ans++;
   }
   cur++;
  }
  cout << ans << '\n';
 }
}