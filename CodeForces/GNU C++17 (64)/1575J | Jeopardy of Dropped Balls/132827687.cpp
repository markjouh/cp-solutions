#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int n, m, k;
 cin >> n >> m >> k;
 vector<vector<int>> grid(n, vector<int>(m));
 for (auto& x : grid) {
  for (int& y : x) {
   cin >> y;
  }
 }
 for (int i = 0; i < k; ++i) {
  int r = 0, c;
  cin >> c;
  c--;
  while (r < n) {
   int cur = grid[r][c];
   grid[r][c] = 2;
   if (cur == 1) {
    ++c;
   }
   if (cur == 2) {
    ++r;
   }
   if (cur == 3) {
    --c;
   }
  }
  cout << c + 1 << ' ';
 }
}