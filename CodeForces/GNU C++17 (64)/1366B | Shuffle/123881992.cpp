#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, x, m;
  cin >> n >> x >> m;
  int a = x, b = x;
  for (int i = 0; i < m; i++) {
   int l, r;
   cin >> l >> r;
   if (b >= l && a <= r) {
    a = min(a, l);
    b = max(b, r);
   }
  }
  cout << abs(a - b) + 1 << '\n';
 }
}