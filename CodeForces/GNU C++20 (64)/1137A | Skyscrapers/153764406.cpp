#include <bits/stdc++.h>
 
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = b - 1; i >= a; i--)
#define each(a, b) for (auto &a : b)
#define rep(a) FOR(_, 0, a)
 
using namespace std;
 
void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m));
  each(row, grid) {
    each(x, row) {
      cin >> x;
    }
  }
  vector<map<int, int>> rplace(n), cplace(m);
  FOR(i, 0, n) {
    vector<int> nums = grid[i];
    sort(all(nums));
    nums.erase(unique(all(nums)), nums.end());
    FOR(j, 0, sz(nums)) {
      rplace[i][nums[j]] = j + 1;
    }
  }
  FOR(i, 0, m) {
    vector<int> nums;
    FOR(j, 0, n) {
      nums.push_back(grid[j][i]);
    }
    sort(all(nums));
    nums.erase(unique(all(nums)), nums.end());
    FOR(j, 0, sz(nums)) {
      cplace[i][nums[j]] = j + 1;
    }
  }
  FOR(i, 0, n) {
    FOR(j, 0, m) {
      int x = grid[i][j];
      cout << max(rplace[i][x], cplace[j][x]) + max(sz(rplace[i]) - rplace[i][x], sz(cplace[j]) - cplace[j][x]) << ' ';
    }
    cout << '\n';
  }
}
 
int main() {
#ifdef LOCAL
  freopen("input.in", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}