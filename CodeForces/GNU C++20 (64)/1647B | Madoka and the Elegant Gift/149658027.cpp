#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
 
#include <bits/stdc++.h>
using namespace std;
 
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
 
// All connected components of 1's must be rectangular for the table to be elegant
// We can use flood fill on 1 tiles, find the min/max x and y, then check if all
// elements in our rectangle are 1's. This runs in O(n^2)
 
bool table[100][100], visited[100][100];
int dy[]{-1, 0, 1, 0}, dx[]{0, 1, 0, -1};
int n, m, mn_y, mx_y, mn_x, mx_x;
 
void dfs(int y, int x) {
  mn_y = min(mn_y, y);
  mx_y = max(mx_y, y);
  mn_x = min(mn_x, x);
  mx_x = max(mx_x, x);
  visited[y][x] = true;
  for (int i = 0; i < 4; i++) {
    int Y = y + dy[i], X = x + dx[i];
    if (Y >= 0 && Y < n && X >= 0 && X < m && table[Y][X] && !visited[Y][X]) {
      dfs(Y, X);
    }
  }
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < m; j++) {
        table[i][j] = s[j] - '0';
      }
    }
    memset(visited, false, sizeof visited);
    bool OK = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (table[i][j] && !visited[i][j]) {
          mn_y = 1e9, mx_y = 0, mn_x = 1e9, mx_x = 0;
          dfs(i, j);
          for (int k = mn_y; k <= mx_y; k++) {
            for (int l = mn_x; l <= mx_x; l++) {
              OK &= table[k][l];
            }
          }
        }
      }
    }
    cout << (OK ? "YES\n" : "NO\n");
  }
}