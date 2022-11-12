#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
#define sz(x) int(size(x))
#define all(x) begin(x), end(x)
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, q;
  cin >> n >> m >> q;
  int cnt = 0;
  vector<vector<bool>> grid(n, vector<bool>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      grid[i][j] = c == '*';
      cnt += grid[i][j];
    }
  }
  vector<vector<int>> icon(n, vector<int>(m));
  vector<pair<int, int>> pos(n*m+1);
  int idx = 0, ans = 0;
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      idx++;
      ans += grid[i][j] && idx > cnt;
      icon[i][j] = idx;
      pos[idx] = {i, j};
    }
  }
  while (q--) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    int cur = icon[x][y];
    if (grid[x][y]) {
      auto [fi, se] = pos[cnt];
      // The final allowed position (cnt) is removed, so an icon placed there must be moved
      if (grid[fi][se]) {
        ans++;
      }
      // If the current icon being switched off is not in an allowed position and contributes to ans, removing it will decrease ans
      if (cur > --cnt) {
        ans--;
      }
    } else {
      auto [fi, se] = pos[cnt+1];
      // The final allowed position is increased (cnt+1), so an icon placed there will no longer contribute to ans
      if (grid[fi][se]) {
        ans--;
      }
      // If the current icon being switched on is not in an allowed position, it must be moved
      if (cur > ++cnt) {
        ans++;
      }
    }
    grid[x][y] = 1 - grid[x][y];
    cout << ans << '\n';
  }
}