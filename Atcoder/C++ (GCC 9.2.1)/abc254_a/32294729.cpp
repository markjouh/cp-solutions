#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> grid(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    grid[i][0] = 1;
    grid[i][i] = 1;
  }
  for (int i = 2; i < n; i++) {
    for (int j = 1; j < i; j++) {
      grid[i][j] += grid[i - 1][j];
      grid[i][j] += grid[i - 1][j - 1];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      cout << grid[i][j] << " \n"[j == i];
    }
  }
}
