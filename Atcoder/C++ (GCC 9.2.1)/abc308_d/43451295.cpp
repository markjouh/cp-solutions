#include "bits/stdc++.h"

using namespace std;

#define int long long

constexpr int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};

char next(char c) {
  const string s = "snuke";
  return s[(s.find(c) + 1) % 5];
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int h, w;
  cin >> h >> w;
  vector<string> grid(h);
  for (int i = 0; i < h; i++) {
    cin >> grid[i];
  }
  vector<vector<bool>> vis(h, vector<bool>(w));
  if (grid[0][0] != 's') {
    cout << "No\n";
    return 0;
  }
  queue<pair<int, int>> q;
  q.push({0, 0});
  vis[0][0] = true;
  while (!q.empty()) {
    auto [y, x] = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i], nx = x + dx[i];
      if (ny >= 0 && ny < h && nx >= 0 && nx < w && !vis[ny][nx] && grid[ny][nx] == next(grid[y][x])) {
        vis[ny][nx] = true;
        q.push({ny, nx});
      }
    }
  }
  cout << (vis[h - 1][w - 1] ? "Yes\n" : "No\n");
}
