#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i += 2) {
      for (int j = 0; j < m; j += 2) {
        int par = (i / 2 + j / 2) % 2;
        if (par == 0) {
          grid[i][j] = 1;
          grid[i + 1][j + 1] = 1;
        } else {
          grid[i + 1][j] = 1;
          grid[i][j + 1] = 1;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << grid[i][j] << ' ';
      }
      cout << '\n';
    }
  }
}