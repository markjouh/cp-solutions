#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz(x) int(size(x))
#define all(x) begin(x), end(x)
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  for (int i = 0; i < n; i++) {
    cin >> grid[i];
  }
  reverse(all(grid));
  while (!grid.empty() && grid.back().find('1') == string::npos) {
    grid.pop_back();
  }
  n = sz(grid);
  if (n == 0) {
    cout << 0;
    return 0;
  }
  vector<int> dp(2, 1e9);
  dp[0] = 0;
  for (int i = 0; i < n - 1; i++) {
    vector<int> new_dp(2, 1e9);
    // Move to the other side, then up
    new_dp[1] = min(new_dp[1], dp[0] + m + 2);
    new_dp[0] = min(new_dp[0], dp[1] + m + 2);
    // If there are no lights on the current floor, we can just move up
    if (grid[i].find('1') == string::npos) {
      new_dp[0] = min(new_dp[0], dp[0] + 1);
      new_dp[1] = min(new_dp[1], dp[1] + 1);
    } else { // Otherwise, we visit all lit rooms, then go back and move up
      int r = grid[i].rfind('1');
      new_dp[0] = min(new_dp[0], dp[0] + r * 2 + 1);
      int l = m + 1 - grid[i].find('1');
      new_dp[1] = min(new_dp[1], dp[1] + l * 2 + 1);
    }
    dp = new_dp;
  }
  dp[0] += grid[n - 1].rfind('1');
  dp[1] += m + 1 - grid[n - 1].find('1');
  cout << min(dp[0], dp[1]);
}