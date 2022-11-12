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
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> grid[i][j];
      }
    }
    int f = 0, s = 0;
    for (int i = 0; i < n; i++) {
      vector<int> srt = grid[i];
      sort(srt.begin(), srt.end());
      vector<int> mv;
      for (int j = 0; j < m; j++) {
        if (grid[i][j] != srt[j]) {
          mv.push_back(j);
        }
      }
      if (mv.size() == 2) {
        f = mv[0];
        s = mv[1];
        break;
      }
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
      swap(grid[i][f], grid[i][s]);
      for (int j = 1; j < m; j++) {
        ok &= grid[i][j] >= grid[i][j - 1];
      }
    }
    if (ok) {
      cout << f + 1 << ' ' << s + 1 << '\n';
    } else {
      cout << -1 << '\n';
    }
  }
}