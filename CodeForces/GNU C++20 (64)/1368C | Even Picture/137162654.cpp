#include <bits/stdc++.h>
using namespace std;
 
// Read the problem statement carefully
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int n;
 cin >> n;
 set<pair<int, int>> seen;
 cout << (n + 1) * 4 - n << '\n';
 auto drawsquare = [&](int ypos, int xpos) {
  for (int i = ypos; i <= ypos + 1; ++i) {
   for (int j = xpos; j <= xpos + 1; ++j) {
    if (!seen.count({i, j})) {
     cout << i << ' ' << j << '\n';
     seen.insert({i, j});
    }
   }
  }
 };
 int y = 0, x = 0;
 for (int i = 0; i < n + 1; ++i) {
  drawsquare(y, x);
  ++y;
  ++x;
 }
}