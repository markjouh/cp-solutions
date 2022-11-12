#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    vector<string> grid(8);
    for (int i = 0; i < 8; i++) {
      cin >> grid[i];
    }
    for (int i = 1; i < 7; i++) {
      for (int j = 1; j < 7; j++) {
        if (grid[i][j] == '#' && grid[i - 1][j - 1] == '#' && grid[i + 1][j + 1] == '#' && grid[i - 1][j + 1] == '#' && grid[i + 1][j - 1] == '#') {
          cout << i + 1 << ' ' << j + 1 << '\n';
          goto out;
        }
      }
    }
    out:;
  }
}