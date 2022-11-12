#include <bits/stdc++.h>
using namespace std;
 
const int dy[]{-2, -2, 2, 2}, dx[]{-2, 2, -2, 2};
 
char a[8][8];
int par[8][8][2];
 
void dfs(int y, int x, int id, int p) {
  par[y][x][id] = p + 1;
  for (int i = 0; i < 4; i++) {
    int y1 = y + dy[i], x1 = x + dx[i];
    if (y1 >= 0 && y1 < 8 && x1 >= 0 && x1 < 8 && !par[y1][x1][id]) {
      dfs(y1, x1, id, 1 - p);
    }
  }
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    memset(par, 0, sizeof par);
    int id = 0;
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        cin >> a[i][j];
        if (a[i][j] == 'K') {
          dfs(i, j, id++, 0);
        }
      }
    }
    bool ans = false;
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        ans |= par[i][j][0] && par[i][j][0] == par[i][j][1] && a[i][j] != '#';
      }
    }
    cout << (ans ? "YES\n" : "NO\n");
  }
}