#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const int MXN = 50;
char grid[MXN][MXN];
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> grid[i][j];
    for (int _ = 0; _ < n; _++)
      for (int i = 0; i < m; i++)
        for (int j = 0; j < n - 1; j++) {
          if (grid[j][i] == '*' && grid[j + 1][i] == '.') {
            swap(grid[j][i], grid[j + 1][i]);
          }
        }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << grid[i][j];
      }
      cout << '\n';
    }
  }
}