#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n, m;
  string s;
  cin >> n >> m >> s;
  vector<pair<int, int>> pos(s.size());
  int y = 0, x = 0;
  for (int i = 0; i < s.size(); ++i) {
   switch (s[i]) {
    case 'U': --y; break;
    case 'D': ++y; break;
    case 'L': --x; break;
    case 'R': ++x; break;
   }
   pos[i] = {y, x};
  }
  int y1 = 0, y2 = 0, x1 = 0, x2 = 0, id = 0;
  while (id < s.size() && max(y2, pos[id].first) - min(y1, pos[id].first) < n && max(x2, pos[id].second) - min(x1, pos[id].second) < m) {
   y1 = min(y1, pos[id].first);
   y2 = max(y2, pos[id].first);
   x1 = min(x1, pos[id].second);
   x2 = max(x2, pos[id].second);
   ++id; 
  }
  cout << abs(y1) + 1 << ' ' << abs(x1) + 1 << '\n';
 }
}