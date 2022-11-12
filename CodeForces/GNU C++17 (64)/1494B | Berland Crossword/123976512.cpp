#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int tc;
 cin >> tc;
 while (tc--) {
  int n, U, R, D, L;
  cin >> n >> U >> R >> D >> L;
  bool OK = false;
  for (int mask = 0; mask < 16; mask++) {
   int u = 0, r = 0, d = 0, l = 0;
   if (mask & 1) {
    u++;
    l++;
   }
   if (mask & 2) {
    l++;
    d++;
   }
   if (mask & 4) {
    d++;
    r++;
   }
   if (mask & 8) {
    r++;
    u++;
   }
   if (u <= U && r <= R && d <= D && l <= L && u + (n - 2) >= U && r + (n - 2) >= R && d + (n - 2) >= D && l + (n - 2) >= L) {
    OK = true;
    break;
   }
  }
  cout << (OK ? "YES" : "NO") << '\n';
 }
}