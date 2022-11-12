#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define FOR(i, n) for (int i = 0; i < (int)n; i++)
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m, R, C;
    cin >> n >> m >> R >> C;
    R--;
    C--;
    vector<vector<int>> grid(n, vector<int>(m));
    FOR(i, n) {
      string s;
      cin >> s;
      FOR(j, m) {
        grid[i][j] = s[j] == 'B';
      }
    }
    if (grid[R][C]) {
      cout << 0 << '\n';
      continue;
    }
    auto hasadj = [&](int r, int c) {
      bool ok = false;
      FOR(i, n) {
        ok |= grid[i][c];
      }
      FOR(i, m) {
        ok |= grid[r][i];
      }
      return ok;
    };
    if (hasadj(R, C)) {
      cout << 1 << '\n';
      continue;
    }
    FOR(i, n) {
      FOR(j, m) {
        if (!grid[i][j]) {
          grid[i][j] = hasadj(i, j);
        }
      }
    }
    cout << (hasadj(R, C) ? 2 : -1) << '\n'; 
  }
}
 
/*
  Read the problem statement carefully
  Think about the problem in different ways
*/
 