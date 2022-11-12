#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int n, q;
 cin >> n >> q;
 vector<vector<int>> grid(2, vector<int>(n));
 int sum = 0;
 while (q--) {
  int r, c;
  cin >> r >> c;
  grid[r - 1][c - 1] ^= 1;
  int chng = (grid[r - 1][c - 1] ? 1 : -1);
  for (int i = -1; i <= 1; i++) {
   if (c + i >= 1 && c + i <= n) {
    sum += grid[2 - r][c + i - 1] * chng;
   }
  }
  cout << (!sum ? "YES" : "NO") << '\n';
 }
}