#include <bits/stdc++.h>
 
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = b - 1; i >= a; i--)
#define each(a, b) for (auto &a : b)
#define rep(a) FOR(_, 0, a)
 
using namespace std;
 
/*
  First, generate a 2d prefix sum from the grid described in the statement.
  After, find the contiguous ranges of a and b with minimum sum for all lengths 1..n.
  Finally, test each pair of ranges in a and b. If the sum of all elements in the
  subrectangle <= x, ans = min(ans, area).
*/
 
void solve() {
  int n, m, k;
  cin >> n >> m;
  vector<int> a(n), b(m);
  each(x, a) {
    cin >> x;
  }
  each(x, b) {
    cin >> x;
  }
  cin >> k;
  
  // Generate grid prefix sum
  vector<vector<long long>> pre(n + 1, vector<long long>(m + 1));
  FOR(i, 1, n + 1) {
    FOR(j, 1, m + 1) {
      pre[i][j] = 1ll * a[i - 1] * b[j - 1] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
    }
  }
  
  // Generate a and b prefix sums
  vector<int> pre_a(n + 1), pre_b(m + 1);
  FOR(i, 1, n + 1) {
    pre_a[i] = a[i - 1] + pre_a[i - 1];
  }
  FOR(i, 1, m + 1) {
    pre_b[i] = b[i - 1] + pre_b[i - 1];
  }
  
  // Coordinates of minumum sums of all contiguous subarrays of length i for all i 1..n in arrays a and b
  vector<int> min_a(n + 1, 1e9), min_b(m + 1, 1e9);
  vector<pair<int, int>> pos_a(n + 1), pos_b(m + 1);
  FOR(i, 1, n + 1) {
    FOR(j, 0, i) {
      int sum = pre_a[i] - pre_a[j];
      if (sum < min_a[i - j]) {
        min_a[i - j] = sum;
        pos_a[i - j] = {j, i};
      }
    }
  }
  FOR(i, 1, m + 1) {
    FOR(j, 0, i) {
      int sum = pre_b[i] - pre_b[j];
      if (sum < min_b[i - j]) {
        min_b[i - j] = sum;
        pos_b[i - j] = {j, i};
      }
    }
  }
  
  // Try each pair of lengths in a and b: if the subrectangle's sum <= x, we can update the max area.
  int ans = 0;
  FOR(i, 1, n + 1) {
    FOR(j, 1, m + 1) {
      int y1 = pos_a[i].first, x1 = pos_b[j].first, y2 = pos_a[i].second, x2 = pos_b[j].second;
      long long sum = pre[y2][x2] - pre[y1][x2] - pre[y2][x1] + pre[y1][x1];
      if (sum <= (long long)k) {
        ans = max(ans, i * j);
        // cout << "y1: " << y1 << '\n' << "x1: " << x1 << '\n' << "y2: " << y2 << '\n' << "x2: " << x2 << '\n';
        // cout << i << ' ' << j << ": " << sum << '\n';
      }
    }
  }
  
  cout << ans << '\n';
}
 
int main() {
#ifdef LOCAL
  freopen("input.in", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}