#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  int last1 = 0, last2 = 0;
  bool ok = true;
  for (int i = 0; i < n; i++) {
   int x, y;
   cin >> x >> y;
   if (x < last1 || y < last2 || x < y || y - last2 > x - last1) {
    ok = false;
   }
   last1 = x;
   last2 = y;
  }
  cout << (ok ? "YES" : "NO") << '\n';
 }
}