#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int x, y, resy = -1, resx = -1;
  cin >> x >> y;
  for (int i = 0; i <= x; ++i) {
   for (int j = 0; j <= y; ++j) {
    if (i + j == x - i + y - j) {
     resy = i;
     resx = j;
    }
   }
  }
  cout << resy << ' ' << resx << '\n';
 }
}