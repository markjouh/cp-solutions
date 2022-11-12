#include <bits/stdc++.h>
using namespace std;
 
void move(int &x, int &y, char c) {
 if (c == 'U') {
  y++;
 } else if (c == 'D') {
  y--;
 } else if (c == 'L') {
  x--;
 } else {
  x++;
 }
}
 
void solve() {
 string s;
 cin >> s;
 int n = s.size();
 for (int i = 0; i < n; i++) {
  int x = 0, y = 0;
  for (int j = 0; j <= i; j++) {
   move(x, y, s[j]);
  }
  int stopx = x, stopy = y;
  x = y = 0;
  for (int j = 0; j < n; j++) {
   int x1 = x, y1 = y;
   move(x1, y1, s[j]);
   if (x1 != stopx || y1 != stopy) {
    x = x1;
    y = y1;
   }
  }
  if (x == 0 && y == 0) {
   cout << stopx << ' ' << stopy << '\n';
   return;
  }
 }
 cout << 0 << ' ' << 0 << '\n';
}
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  solve();
 }
}