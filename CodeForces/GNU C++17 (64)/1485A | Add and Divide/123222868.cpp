#include <bits/stdc++.h>
using namespace std;
 
int simulate(int x, int div) {
 if (div == 1) {
  return INT_MAX;
 }
 int res = 0;
 while (x > 0) {
  x /= div;
  res++;
 }
 return res;
}
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int a, b;
  cin >> a >> b;
  int ans = simulate(a, b);
  for (int i = 1; i <= 15; i++) {
   int next = simulate(a, b + i) + i;
   ans = min(ans, next);
  }
  cout << ans << '\n';
 }
}