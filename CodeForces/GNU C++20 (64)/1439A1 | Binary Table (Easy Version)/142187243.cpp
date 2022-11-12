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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    FOR(i, n) {
      string s;
      cin >> s;
      FOR(j, m) {
        grid[i][j] = s[j]-'0';
      }
    }
    vector<vector<int>> res;
    FOR(i, n-1) {
      FOR(j, m-1) {
        int sum = grid[i][j]+grid[i][j+1]+grid[i+1][j]+grid[i+1][j+1];
        int ct[2];
        auto solve = [&]() {
          res.emplace_back();
          FOR(k, 2) {
            FOR(l, 2) {
              if (ct[grid[i+k][j+l]]-- > 0) {
                grid[i+k][j+l] ^= 1;
                res.back().push_back(i+k);
                res.back().push_back(j+l);
              }
            }
          }
        };
        if (sum == 0) {
          continue;
        }
        if (sum == 4) {
          ct[0] = 0;
          ct[1] = 3;
          solve();
          sum = 1;
        }
        if (sum == 1) {
          ct[0] = 2;
          ct[1] = 1;
          solve();
          sum = 2;
        }
        if (sum == 2) {
          ct[0] = 2;
          ct[1] = 1;
          solve();
          sum = 3; 
        }
        if (sum == 3) {
          ct[0] = 0;
          ct[1] = 3;
          solve();
        }
      }
    }
    cout << res.size() << '\n';
    FOR(i, res.size()) {
      FOR(j, 6) {
        cout << res[i][j]+1 << " \n"[j == 5];
      }
    }
  }
}
 
/*
  Read the problem statement carefully
  Think about the problem in different ways
*/