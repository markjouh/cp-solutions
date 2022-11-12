#include <bits/stdc++.h>
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
 
/*
https://www.geeksforgeeks.org/inplace-rotate-square-matrix-by-90-degrees/
(x, y), (y, N-1-x), (N-1-x, N-1-y), (N-1-y, x)
*/
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<vector<bool>> a(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        char c;
        cin >> c;
        a[i][j] = c == '1';
      }
    }
    int ans = 0;
    vector<vector<bool>> vis(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (!vis[i][j]) {
          int tot = a[i][j] + a[j][n - i - 1] + a[n - i - 1][n - j - 1] + a[n - j - 1][i];
          ans += min(tot, 4 - tot);
          vis[i][j] = true;
          vis[j][n - i - 1] = true;
          vis[n - i - 1][n - j - 1] = true;
          vis[n - j - 1][i] = true;
        }
      }
    }
    cout << ans << '\n';
  }
}