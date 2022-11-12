#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int mxn = 50;
 
int dy[]{-1, 0, 1, 0}, dx[]{0, 1, 0, -1};
 
int n, m;
char grid[mxn][mxn];
bool seen[mxn][mxn];
 
void dfs(int y, int x) {
  seen[y][x] = true;
  for (int i = 0; i < 4; i++) {
    int y1 = y + dy[i], x1 = x + dx[i];
    if (y1 >= 0 && y1 < n && x1 >= 0 && x1 < m && !seen[y1][x1] && grid[y1][x1] != '#') {
      dfs(y1, x1); 
    }
  }
}
 
int main() {
#ifdef LOCAL
  freopen("input.in", "r", stdin);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> grid[i][j];
        seen[i][j] = false;
      }
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 'B') {
          for (int k = 0; k < 4; k++) {
            int y = i + dy[k], x = j + dx[k];
            if (y >= 0 && y < n && x >= 0 && x < m && grid[y][x] == '.') {
              grid[y][x] = '#';
            }
          }
        }
      }
    }
    if (grid[n - 1][m - 1] != '#') {
      dfs(n - 1, m - 1);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 'G') {
          ok &= seen[i][j];
        }
        if (grid[i][j] == 'B') {
          ok &= !seen[i][j];
        }
      }
    }
    cout << (ok ? "Yes\n" : "No\n");
  }
}