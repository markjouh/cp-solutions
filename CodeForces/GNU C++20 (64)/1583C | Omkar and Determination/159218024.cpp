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
  for (int i = 0 ; i < n; i++) {
    cin >> grid[i];
  }
  vector<int> con(m);
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m - 1; j++) {
      con[j + 1] += grid[i][j] == 'X' && grid[i - 1][j + 1] == 'X';
    }
  }
  for (int i = 1; i < m; i++) {
    con[i] += con[i - 1];
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << (con[r - 1] - con[l - 1] == 0 ? "YES\n" : "NO\n");
  }
}
 
/*
A grid isn't determinable if we have two X's arranged like this:
 X
X#
since the character in the position of the # could be empty or filled; both
wouldn't be exitable.
*/