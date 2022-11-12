#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int c1, c2, swords, axes, wsword, waxe;
  cin >> c1 >> c2 >> swords >> axes >> wsword >> waxe;
  if (wsword > waxe) {
   swap(swords, axes);
   swap(wsword, waxe);
  }
  int ans = 0;
  for (int i = 0; i <= min(swords, c1 / wsword); ++i) {
   int p1sw = i; // Player 1 swords
   int p1ax = (c1 - i * wsword) / waxe; // Player 1 axes
   int p2sw = min(swords - p1sw, c2 / wsword); // Player 2 swords
   int p2ax = min(axes - p1ax, (c2 - p2sw * wsword) / waxe); // Player 2 axes
   ans = max(ans, p1sw + p1ax + p2sw + p2ax);
  }
  cout << ans << '\n';
 }
}