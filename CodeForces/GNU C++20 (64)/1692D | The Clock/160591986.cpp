#include <bits/stdc++.h>
using namespace std;
 
int time() {
  int h, m;
  scanf("%d:%d", &h, &m);
  return h * 60 + m;
}
 
int main() {
  // precalculate palindromic times
  vector<bool> pal(1440);
  for (int h = 0; h < 24; h++) {
    int m = h % 10 * 10 + h / 10;
    if (m < 60) {
      pal[h * 60 + m] = true;
    }
  }
  int tc;
  cin >> tc;
  while (tc--) {
    int s = time(), x;
    cin >> x;
    int ans = 0;
    vector<bool> vis(1440);
    for (int i = s, cnt = 0; !vis[i]; i = (i + x) % 1440, cnt++) {
      vis[i] = true;
      ans += pal[i];
    }
    cout << ans << '\n';
  }
}