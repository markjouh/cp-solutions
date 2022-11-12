#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  if (a == 1 && b == 1 && n + m > 1) {
   a++;
  }
  if (a == n && b == m && n + m > 1) {
   a--;
  }
  cout << 1 << ' ' << 1 << ' ' << n << ' ' << m << '\n';
 }
}
 
/* Scratchpad
 case 1- edge case area == 1, so return 1(x4)
 case 2- start is at (1, 1), so return (0, 1) if y greater
   and vice versa
 case 3- same as case 2, but with (n, m) and subtraction
 otherwise- return (1, 1), (n, m) for first and last points
*/